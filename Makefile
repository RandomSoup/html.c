CFLAGS:=-Wall -Wextra -pedantic -I./src
CPPFLAGS:=-P -w -UHTML_PREFIX
ifdef DEBUG
CFLAGS+=-O0 -g
else
CFLAGS+=-O3 -flto
endif

all: src/html_meta.i test.out

test.out: src/html.c test/main.c
	$(CC) $^ -o $@ $(CFLAGS)

src/%.i: src/%.h
	$(CPP) $< $(CPPFLAGS) > $@

clean:
	rm -rf *.out src/*.i
