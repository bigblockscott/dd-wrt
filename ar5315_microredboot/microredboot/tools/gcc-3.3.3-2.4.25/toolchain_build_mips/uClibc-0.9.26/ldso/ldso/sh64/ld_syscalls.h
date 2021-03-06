/* Define the __set_errno macro as nothing so that we don't bother
 * setting errno, which is important since we make system calls
 * before the errno symbol is dynamicly linked. */

#include <errno.h>
#undef __set_errno
#define __set_errno(X) {(void)(X);}
#include "sys/syscall.h"

