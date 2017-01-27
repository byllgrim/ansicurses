#include <sys/ioctl.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "ansicurses.h"

#define CSI "\033["

static struct termios saved_attr;

static void
getcurpos(WINDOW *win, int *y, int *x)
{
	struct termios tmp_attr, attr;
	(void)win;

	tcgetattr(0, &tmp_attr);
	tcgetattr(0, &attr);
	attr.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSAFLUSH, &attr);

	printf("\033[6n"); /* TODO write()? */
	scanf("\033[%d;%dR", y, x);
	*y -= 1;
	*x -= 1;

	tcsetattr(0, TCSAFLUSH, &tmp_attr);
}

static void
unsetlflag(tcflag_t lflag)
{
	struct termios attr;

	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~lflag;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}

static void
updatesize(void)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	LINES = w.ws_row;
	COLS = w.ws_col;
}

static void
winchhandler(int signo)
{
	updatesize();
	(void)signo;
}

int
cbreak(void)
{
	unsetlflag(ICANON);
	/* TODO ISIG */
	/* TODO IXOFF */
	return OK;
}

int
endwin(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_attr);
	printf("\n");
	return OK;
}

int
erase(void)
{
	printf(CSI"2J");
	return OK;
}

int
getcurx(WINDOW *win)
{
	int x, y;
	(void)win;
	getyx(stdscr, y, x);
	return x;
}

int
getcury(WINDOW *win)
{
	int x, y;
	(void)win;
	getyx(stdscr, y, x);
	return y;
}

WINDOW *
initscr(void)
{
	tcgetattr(STDIN_FILENO, &saved_attr);

	updatesize();
	if (signal(SIGWINCH, winchhandler) == SIG_ERR) {
		/* TODO ^ not portable! use sigaction? */
		fprintf(stderr, "cant catch SIGWINCH");
		exit(EXIT_FAILURE);
	}

	noecho();
	cbreak(); /* TODO deviate from ncurses default? */

	erase();
	move(0, 0);
	return stdscr;
}

int
move(int y, int x)
{
	printf(CSI"%d;%dH", y+1, x+1);
	return OK;
}

int
noecho(void)
{
	unsetlflag(ECHO);
	/* TODO check result? */
	return OK;
}

int
printw(const char *fmt, ...)
{
	char buf[BUFSIZ + 1]; /* TODO watch the stack? */
	int i;
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(buf, BUFSIZ, fmt, ap);
	buf[BUFSIZ] = '\0';
	va_end(ap);

	for (i = 0; buf[i]; i++) {
		if (buf[i] == '\n') {
			printf(CSI"0K");
			if (getcury(stdscr) == LINES - 1)
				continue;
		}
		if (getcury(stdscr) == LINES -1 && getcurx(stdscr) == COLS -1)
			break;
		putchar(buf[i]); /* TODO utf */
	}

	return OK;
}

int
raw(void)
{
	unsetlflag(ISIG);
	unsetlflag(ICANON);
	/* TODO IXOFF */
	return OK;
}

int
refresh(void)
{
	/* TODO is this a dummy function? */
	return OK;
}
