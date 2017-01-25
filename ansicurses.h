/* License is unlicense.
 * There are no ifdef guards, because I oppose nested includes.
 */

#define WINDOW void

int cbreak(void);
int erase(void);
WINDOW *initscr(void);
int move(int y, int x);
int noecho(void);
int refresh(void);
