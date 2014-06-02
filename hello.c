#include <ncurses.h>

int main()
{
  /* The character reflector*/
  int ch;

  initscr();			/* Initialize the screen*/
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  raw();			/* Line buffering disabled*/
  keypad(stdscr, TRUE);		/* To receive function keys F1, F2...*/
  noecho();			/* Not to echo back onto the screen*/

  printw("Print any character to see it in bold");
  ch = getch();

  if (ch == KEY_F(1))
    printw("F1 key pressed");

  else
    {
      printw("The printed key is...");
      attron(A_STANDOUT | COLOR_PAIR(1));
      mvprintw(0,5,"%c", ch);
      attroff(A_STANDOUT);
    }
  refresh();
  getch();
  endwin();
  return 0;
}
