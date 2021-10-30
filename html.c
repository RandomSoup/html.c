#include "html.h"

void html_tag_prologue(char* tag, char* attrs)
{
	printf("<%s", tag);
	if (attrs)
	{
		printf(" %s", attrs);
	}
	printf(">");
	return;
}
