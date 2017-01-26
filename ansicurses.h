/* License is unlicense.
 * There are no ifdef guards, because I oppose nested includes.
 */

#define stdscr NULL
#define TABSIZE 8 /* TODO getenv or such? */
#define WINDOW void
#define getyx(win, y, x) (getcurpos(win, &(y), &(x)))

int COLS;
int LINES;

int cbreak(void);
int endwin(void);
int erase(void);
int getcurx(WINDOW *win);
int getcury(WINDOW *win);
WINDOW *initscr(void);
int move(int y, int x);
int noecho(void);
int printw(const char *fmt, ...);
int raw(void);
int refresh(void);
