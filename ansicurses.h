/* License is unlicense.
 * There are no ifdef guards, because I oppose nested includes.
 */

#define WINDOW void

int erase(void);
WINDOW *initscr(void);
int move(int y, int x);
int refresh(void);
