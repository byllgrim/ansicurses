/* TODO from curses.h
 * 	stdscr
 * 	COLS
 * 	LINES
 * 	TABSIZE
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

static void
unsetlflag(tcflag_t lflag)
{
	struct termios attr;

	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~lflag;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}

int
cbreak(void)
{
	unsetlflag(ICANON);
	/* TODO ISIG */
	/* TODO IXOFF */
	return 1; /* TODO OK */
}

int
endwin(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_attr);
	return 1; /* TODO OK */
}

int
erase(void)
{
	printf(CSI"2J");
	return 1; /* TODO OK */
}

WINDOW *
initscr(void)
{
	tcgetattr(STDIN_FILENO, &saved_attr);

	noecho();
	cbreak(); /* TODO deviate from ncurses default? */

	erase();
	move(0, 0);
	return NULL;
}

int
move(int y, int x)
{
	printf(CSI"%d;%dH", y+1, x+1);

	return 1; /* TODO OK */
}

int
noecho(void)
{
	unsetlflag(ECHO);
	/* TODO check result? */
	return 1; /* TODO OK */
}

int
raw(void)
{
	unsetlflag(ISIG);
	unsetlflag(ICANON);
	/* TODO IXOFF */
	return 1; /* TODO OK */
}

int
refresh(void)
{
	/* TODO is this a dummy function? */
	return 1; /* TODO OK */
}
