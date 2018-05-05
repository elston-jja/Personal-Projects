#include <ncurses.h>
#include <string.h>

int main()
{
    char messg[]="Enter a message: ";
    char str[80];
    int row, col;

    initscr();

    getmaxyx(stdscr,row,col);
    mvprintw(row/2,(col-strlen(messg))/2,"%s", messg);

    getstr(str);
    mvprintw(LINES -1, 0, "You Entered: %s", str);
    getch();
    endwin();
    return 0;
}
