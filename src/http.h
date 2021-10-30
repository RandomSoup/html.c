#ifndef HTTP_H
#define HTTP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <string.h>
#include "html_common.h"

typedef struct http_req_t
{
	enum
	{
		HTTP_GET,
		HTTP_HEAD,
		HTTP_POST,
		HTTP_PUT,
		HTTP_DELETE,
		HTTP_CONNECT,
		HTTP_OPTIONS,
		HTTP_TRACE,
		HTTP_PATCH
	} method;
	char* path;
} http_req_t;

#define route_index if (!req->path || !*req->path || !strcmp(req->path, "/"))
#define route_default else
#define route(rp) else if (!strcmp(req->path, rp))
#define set(hd) html.printf("%s\r\n", hd)
#define headers for ( \
	int _headers_break = 1; \
	_headers_break; \
	_headers_break = 0, html.printf("\r\n") \
)

#ifdef __cplusplus
}
#endif

#endif /* !HTTP_H */
