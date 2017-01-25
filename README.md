ansicurses
==========
ncurses replacement relying on ANSI escape codes

Warning
-------
There is no support for windows.
Everything is in one main window, e.g. stdscr.

Some functions, e.g. refresh, does nothing.
The internals are much simpler (shittier?) than ncurses.

Most functions of ncurses is unimplemented.
I only implement what I need to run
[mvi](https://github.com/byllgrim/mvi).
If you need anything else, it should be easy send a patch.
