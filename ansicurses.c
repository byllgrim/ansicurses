/* TODO from curses.h
 * 	stdscr
 * 	COLS
 * 	LINES
 * 	TABSIZE
 * 	raw
 * 	noecho
 * 	endwin
 * 	printw
 * 	move
 * 	getcurx
 * 	getcury
 * 	refresh
 * 	mvprintw
 *
 * additionally from libncursesw.a
 *	wmove
 *	wrefresh
 *	wgetch
 */
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "ansicurses.h"

static struct termios saved_attr;

WINDOW *
initscr(void)
{
	struct termios attr;

	if (!isatty(STDIN_FILENO)) {
		fprintf(stderr, "not a terminal\n");
		exit(EXIT_FAILURE);
		/* TODO die() */
	}

	tcgetattr(STDIN_FILENO, &saved_attr);
	/* TODO? atexit(reset_attr); */

	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~ECHO;
	tcsetattr (STDIN_FILENO, TCSAFLUSH, &attr);
	/* TODO unsetattr(ECHO) */

	/* TODO clear screen etc */
	return NULL;
}
