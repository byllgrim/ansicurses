/* TODO from curses.h
 * 	stdscr
 * 	COLS
 * 	LINES
 * 	TABSIZE
 * 	raw
 * 	noecho
 * 	endwin
 * 	printw
 * 	getcurx
 * 	getcury
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

#define CSI  "\033["

static struct termios saved_attr;

int
erase(void)
{
	printf(CSI"2J");
	return 1; /* TODO OK */
}

WINDOW *
initscr(void)
{
	struct termios attr;

	tcgetattr(STDIN_FILENO, &saved_attr);
	/* TODO? atexit(reset_attr); */

	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~ECHO;
	tcsetattr (STDIN_FILENO, TCSAFLUSH, &attr);
	/* TODO unsetattr(ECHO) */

	erase();
	return NULL;
}

int
move(int y, int x)
{
	printf(CSI"%d;%dH", y+1, x+1);

	return 1; /* TODO OK */
}

int
refresh(void)
{
	/* TODO is this a dummy function? */
	return 1; /* TODO OK */
}
