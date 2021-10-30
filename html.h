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

#define HTML_PRINT_TAG(tag, type, ...) for ( \
	int _html_break = ( \
		html.open(tag, HTML_STR(__VA_ARGS__), type), 1 \
	); \
	_html_break; \
	_html_break = 0, !type ? html.close(tag) : (void)0 \
)

#define HTML_CUSTOM_TAG(tag, open_cb, close_cb, ...) for ( \
	int _html_break = ( \
		html.open(tag, HTML_STR(__VA_ARGS__), HTML_NORMAL), \
		open_cb(tag, HTML_STR(__VA_ARGS__)), 1 \
	); \
	_html_break; \
	_html_break = 0, html.close(tag), close_cb(tag) \
)

typedef enum html_type_t
{
	HTML_NORMAL,
	HTML_SCLOSE,
	HTML_NCLOSE
} html_type_t;

typedef int (*html_printf_t)(const char* restrict fmt, ...);
typedef void (*html_open_t)(char* tag, char* attrs, html_type_t type);
typedef void (*html_close_t)(char* tag);

typedef struct html_t
{
	html_printf_t printf;
	html_open_t open;
	html_close_t close;
	void* udata;
} html_t;

extern thread_local html_t html;

int _html_printf(const char* restrict fmt, ...);
void _html_open(char* tag, char* attrs, html_type_t type);
void _html_close(char* tag);

#ifdef __cplusplus
}
#endif

#endif /* !HTML_H */
