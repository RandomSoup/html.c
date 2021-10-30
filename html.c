#include "html.h"

int _html_printf(const char* restrict fmt, ...)
{
	int rt = 0;
	va_list args;
	va_start(args, fmt);
	rt = vprintf(fmt, args);
	va_end(args);
	return rt;
}

void _html_tag_open(char* tag, char* attrs)
{
	html_printf("<%s", tag);
	if (*attrs)
	{
		html_printf(" %s", attrs);
	}
	html_printf(">");
	return;
}

void _html_tag_close(char* tag)
{
	html_printf("</%s>", tag);
	return;
}

thread_local html_printf_t html_printf = _html_printf;
thread_local html_tag_open_t html_tag_open = _html_tag_open;
thread_local html_tag_close_t html_tag_close = _html_tag_close;
