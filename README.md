ansicurses
==========
ncurses replacement relying on ANSI escape codes

Warning!
--------
This is a work in progress and is therefore buggy as a motherf*****.

Some functions, e.g. refresh, does nothing.
The internals are much simpler (shittier?) than ncurses.

Most functions of ncurses are unimplemented.
I only implement what I need to run
[mvi](https://github.com/byllgrim/mvi).
If you need anything else, it should be easy to add.

There is no support for windows.
Everything is in one main window, i.e. stdscr.

Neither does it use alternative buffer.
Everything is printed in the same terminal that executed the program.
