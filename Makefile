PREFIX = /usr/local
CFLAGS = -std=c89 -pedantic -Wall -Wextra

OBJ = ansicurses.o
LIB = libansicurses.a

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) -rcs $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $<

install: $(LIB)
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	cp $(LIB) $(DESTDIR)$(PREFIX)/lib/$(LIB)

clean:
	rm -f $(LIB) $(OBJ)
