/*
 * nameif.c - Naming Interfaces based on MAC address for busybox.
 *
 * Written 2000 by Andi Kleen.
 * Busybox port 2002 by Nick Fedchik <nick@fedchik.org.ua>
 *			Glenn McGrath <bug1@iinet.net.au>
 *
 * Licensed under the GPL v2 or later, see the file LICENSE in this tarball.
 */

#include <sys/syslog.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <netinet/ether.h>

#include "busybox.h"

/* Older versions of net/if.h do not appear to define IF_NAMESIZE. */
#ifndef IF_NAMESIZE
#  ifdef IFNAMSIZ
#    define IF_NAMESIZE IFNAMSIZ
#  else
#    define IF_NAMESIZE 16
#  endif
#endif

/* take from linux/sockios.h */
#define SIOCSIFNAME	0x8923	/* set interface name */

/* Octets in one Ethernet addr, from <linux/if_ether.h> */
#define ETH_ALEN	6

#ifndef ifr_newname
#define ifr_newname ifr_ifru.ifru_slave
#endif

typedef struct mactable_s {
	struct mactable_s *next;
	struct mactable_s *prev;
	char *ifname;
	struct ether_addr *mac;
} mactable_t;

static unsigned long flags;

static void serror(const char *s, ...) ATTRIBUTE_NORETURN;

static void serror(const char *s, ...)
{
	va_list ap;

	va_start(ap, s);

	if (flags & 1) {
		openlog(bb_applet_name, 0, LOG_LOCAL0);
		vsyslog(LOG_ERR, s, ap);
		closelog();
	} else {
		bb_verror_msg(s, ap);
		putc('\n', stderr);
	}
	va_end(ap);

	exit(EXIT_FAILURE);
}

/* Check ascii str_macaddr, convert and copy to *mac */
static struct ether_addr *cc_macaddr(const char *str_macaddr)
{
	struct ether_addr *lmac, *mac;

	lmac = ether_aton(str_macaddr);
	if (lmac == NULL)
		serror("cannot parse MAC %s", str_macaddr);
	mac = xmalloc(ETH_ALEN);
	memcpy(mac, lmac, ETH_ALEN);

	return mac;
}

int nameif_main(int argc, char **argv)
{
	mactable_t *clist = NULL;
	FILE *ifh;
	const char *fname = "/etc/mactab";
	char *line;
	int ctl_sk;
	int if_index = 1;
	mactable_t *ch;

	flags = bb_getopt_ulflags(argc, argv, "sc:", &fname);

	if ((argc - optind) & 1)
		bb_show_usage();

	if (optind < argc) {
		char **a = argv + optind;

		while (*a) {

			if (strlen(*a) > IF_NAMESIZE)
				serror("interface name `%s' too long", *a);
			ch = xcalloc(1, sizeof(mactable_t));
			ch->ifname = bb_xstrdup(*a++);
			ch->mac = cc_macaddr(*a++);
			if (clist)
				clist->prev = ch;
			ch->next = clist;
			clist = ch;
		}
	} else {
		ifh = bb_xfopen(fname, "r");

		while ((line = bb_get_line_from_file(ifh)) != NULL) {
			char *line_ptr;
			size_t name_length;

			line_ptr = line + strspn(line, " \t");
			if ((line_ptr[0] == '#') || (line_ptr[0] == '\n')) {
				free(line);
				continue;
			}
			name_length = strcspn(line_ptr, " \t");
			ch = xcalloc(1, sizeof(mactable_t));
			ch->ifname = bb_xstrndup(line_ptr, name_length);
			if (name_length > IF_NAMESIZE)
				serror("interface name `%s' too long", ch->ifname);
			line_ptr += name_length;
			line_ptr += strspn(line_ptr, " \t");
			name_length = strspn(line_ptr, "0123456789ABCDEFabcdef:");
			line_ptr[name_length] = '\0';
			ch->mac = cc_macaddr(line_ptr);
			if (clist)
				clist->prev = ch;
			ch->next = clist;
			clist = ch;
			free(line);
		}
		fclose(ifh);
	}

	if ((ctl_sk = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
		serror("socket: %m");

	while (clist) {
		struct ifreq ifr;

		memset(&ifr, 0, sizeof(struct ifreq));
		if_index++;
		ifr.ifr_ifindex = if_index;

		/* Get ifname by index or die */
		if (ioctl(ctl_sk, SIOCGIFNAME, &ifr))
			break;

		/* Has this device hwaddr? */
		if (ioctl(ctl_sk, SIOCGIFHWADDR, &ifr))
			continue;

		/* Search for mac like in ifr.ifr_hwaddr.sa_data */
		for (ch = clist; ch; ch = ch->next)
			if (!memcmp(ch->mac, ifr.ifr_hwaddr.sa_data, ETH_ALEN))
				break;

		/* Nothing found for current ifr.ifr_hwaddr.sa_data */
		if (ch == NULL)
			continue;

		strcpy(ifr.ifr_newname, ch->ifname);
		if (ioctl(ctl_sk, SIOCSIFNAME, &ifr) < 0)
			serror("cannot change ifname %s to %s: %m",
				   ifr.ifr_name, ch->ifname);

		/* Remove list entry of renamed interface */
		if (ch->prev != NULL) {
			(ch->prev)->next = ch->next;
		} else {
			clist = ch->next;
		}
		if (ch->next != NULL)
			(ch->next)->prev = ch->prev;
#ifdef CONFIG_FEATURE_CLEAN_UP
		free(ch->ifname);
		free(ch->mac);
		free(ch);
#endif
	}

	return 0;
}
