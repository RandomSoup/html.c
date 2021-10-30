#include <stdio.h>
#include "html.h"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[])
{
	html(lang="en") {
		body() {
			p() {
				span() html_printf("Hello, ");
				span() html_printf("World!");
			}
		}
	}
	printf("\n");
	return 0;
}
