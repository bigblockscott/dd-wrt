/*
 * $Id: subscribe.h,v 1.1.1.1 2005/06/13 16:47:42 bogdan_iancu Exp $
 *
 * Presence Agent, subscribe handling
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of openser, a free SIP server.
 *
 * openser is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * openser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include "../../parser/msg_parser.h"

/*
 * Check if a message received has been constructed properly
 */
int check_message(struct sip_msg* _m);

/*
 * Handle a subscribe Request
 */
int handle_subscription(struct sip_msg* _m, char* _domain, char* _s2);


/*
 * Return 1 if the subscription exists and 0 if not
 */
int existing_subscription(struct sip_msg* _m, char* _domain, char* _s2);


/*
 * Handle a REGISTER Request: ensures AOR is in presentity table.
 */
int pa_handle_registration(struct sip_msg* _m, char* _domain, char* _s2);

/*
 * Returns 1 if possibly a user agent can handle SUBSCRIBE
 * itself, 0 if it cannot for sure
 */
int pua_exists(struct sip_msg* _m, char* _domain, char* _s2);

enum doctype;
/*
 * Get presentity URI, which is stored in R-URI
 */
int get_pres_uri(struct sip_msg* _m, str* _puri);

/*
 * Parse Accept header field body
 */
int parse_accept(struct hdr_field* _h, enum doctype* _a);

#endif /* SUBSCRIBE_H */
