#include "http.h"
#include "html.h"

void handle_req(http_req_t* req)
{
	route_index {
		goto index;
	}

	route("/index.html") {
	index:
		headers {
			set("Content-Type: text/html");
			set("Status: 200");
		}

		doctype();
		root(lang="en") {
			body() {
				p() {
					span() html.printf("Hello, ");
					span() html.printf("World!");
				}
			}
		}
	}

	route_default {
		headers {
			set("Content-Type: text/plain");
			set("Status: 404");
		}
		html.printf("Not found");
	}
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[])
{
	http_req_t req = { HTTP_GET, argv[1] };

	handle_req(&req);
	html.printf("\n");
	return 0;
}
