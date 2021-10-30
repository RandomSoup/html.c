#include <stdio.h>
#include "html.h"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[])
{
	doctype();
	root(lang="en") {
		body() {
			p() {
				span() html.printf("Hello, ");
				span() html.printf("World!");
			}
		}
	}
	printf("\n");
	return 0;
}
