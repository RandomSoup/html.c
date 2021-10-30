#ifndef HTML_COMMON_H
#define HTML_COMMON_H

/* Just to be sure... */
#define HTML_STR1(a) #a
#define HTML_STR0(a) HTML_STR1(a)
#define HTML_STR(a) HTML_STR0(a)

#define HTML_CAT1(a, b) a##b
#define HTML_CAT0(a, b) HTML_CAT1(a, b)
#define HTML_CAT(a, b) HTML_CAT0(a, b)

#ifdef HTML_PREFIX
#define HTML_NAME(a) HTML_CAT(HTML_PREFIX, a)
#else
#define HTML_NAME(a) a
#endif /* HTML_PREFIX */

#endif /* !HTML_COMMON_H */
