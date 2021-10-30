#ifndef HTML_H
#define HTML_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>
#include <threads.h>
#include "html_common.h"
#include "html_meta.i"

#define HTML_PRINT_TAG(tag, ...) for ( \
	int _html_break = ( \
		html_tag_open(tag, HTML_STR(__VA_ARGS__)), 1 \
	); \
	_html_break; \
	_html_break = 0, html_tag_close(tag) \
)

typedef int (*html_printf_t)(const char* restrict fmt, ...);
typedef void (*html_tag_open_t)(char* tag, char* attrs);
typedef void (*html_tag_close_t)(char* tag);

extern thread_local html_printf_t html_printf;
extern thread_local html_tag_open_t html_tag_open;
extern thread_local html_tag_close_t html_tag_close;

#ifdef __cplusplus
}
#endif

#endif /* !HTML_H */
