#ifndef HTML_H
#define HTML_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "html_common.h"
#include "html_meta.i"

#define HTML_IS_EMPTY(...) (sizeof((char[]){#__VA_ARGS__}) == 1)
#define HTML_PRINT_TAG(tag, ...) for ( \
	int _html_break = ( \
		html_tag_prologue(tag, HTML_IS_EMPTY(__VA_ARGS__) ? NULL : HTML_STR(__VA_ARGS__)), 1 \
	); \
	_html_break; \
	_html_break = 0, printf("</%s>", tag) \
)

void html_tag_prologue(char* tag, char* attrs);

#ifdef __cplusplus
}
#endif

#endif /* !HTML_H */
