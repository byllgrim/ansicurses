/* License is unlicense.
 * There are no ifdef guards, because I oppose nested includes.
 */

#define WINDOW void

int COLS;
int LINES;

int cbreak(void);
int endwin(void);
int erase(void);
WINDOW *initscr(void);
int move(int y, int x);
int noecho(void);
int raw(void);
int refresh(void);
