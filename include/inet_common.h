/* vi: set sw=4 ts=4: */
/*
 * stolen from net-tools-1.59 and stripped down for busybox by
 *                      Erik Andersen <andersen@codepoet.org>
 *
 * Heavily modified by Manuel Novoa III       Mar 12, 2001
 *
 */
#ifndef INET_COMMON_H
#define INET_COMMON_H 1

PUSH_AND_SET_FUNCTION_VISIBILITY_TO_HIDDEN

/* hostfirst!=0 If we expect this to be a hostname,
   try hostname database first
 */
int INET_resolve(const char *name, struct sockaddr_in *s_in, int hostfirst) FAST_FUNC;

/* numeric: & 0x8000: "default" instead of "*",
 *          & 0x4000: host instead of net,
 *          & 0x0fff: don't resolve
 */

int INET6_resolve(const char *name, struct sockaddr_in6 *sin6) FAST_FUNC;

/* These return malloced string */
char *INET_rresolve(struct sockaddr_in *s_in, int numeric, uint32_t netmask) FAST_FUNC;
char *INET6_rresolve(struct sockaddr_in6 *sin6, int numeric) FAST_FUNC;

#if ENABLE_FEATURE_TRACEROUTE_VERBOSE
int hexdump_if_verbose(const struct icmp *icp, int len, struct sockaddr *from, struct sockaddr *to, int verbose) FAST_FUNC;
#else
# define hexdump_if_verbose(...) 0
#endif

const char *icmp_type_name(unsigned char id);
const char *icmp6_type_name(unsigned char id);

POP_SAVED_FUNCTION_VISIBILITY

#endif
