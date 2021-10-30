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

void _html_open(char* tag, char* attrs, html_type_t type)
{
	html.printf("<%s", tag);
	if (*attrs)
	{
		html.printf(" %s", attrs);
	}
	if (type == HTML_SCLOSE)
	{
		html.printf(" /");
	}
	html.printf(">");
	return;
}

void _html_close(char* tag)
{
	html.printf("</%s>", tag);
	return;
}

thread_local html_t html = {
	_html_printf,
	_html_open,
	_html_close,
	NULL
};
