CPPFLAGS = -D_POSIX_C_SOURCE=200809L
CFLAGS = -std=c89 -pedantic -Wall -Wextra ${CPPFLAGS}
PREFIX = /usr/local

OBJ = ansicurses.o
LIB = libansicurses.a
INC = ansicurses.h

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) -rcs $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $<

install: $(LIB)
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	cp $(LIB) $(DESTDIR)$(PREFIX)/lib/$(LIB)
	mkdir -p $(DESTDIR)$(PREFIX)/include
	cp $(INC) $(DESTDIR)$(PREFIX)/include/$(INC)

clean:
	rm -f $(LIB) $(OBJ)
