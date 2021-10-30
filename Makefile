CFLAGS:=-Wall -Wextra -pedantic
CPPFLAGS:=-P -w -DDEFINE=\#define -DIFNDEF=\#ifndef -DENDIF=\#endif -UPREFIX
ifdef DEBUG
CFLAGS+=-O0 -g
else
CFLAGS+=-O3 -flto
endif

all: html_meta.i html.out

html.out: html.c main.c
	$(CC) $^ -o $@ $(CFLAGS)

html_meta.i: html_meta.h
	$(CPP) $< $(CPPFLAGS) > $@

clean:
	rm -rf *.out *.i
