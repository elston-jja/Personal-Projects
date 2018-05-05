#include <ncurses.h>
#include <string>

#define LEN(a) (sizeof(a) /sizeof(*a))


int main(void)
{
    initscr();
    noecho();
    cbreak();

    int maxY, maxX;
    getmaxyx(stdscr,maxY,maxX);

    WINDOW * menuwin = newwin(0,0,0,0);
    box(menuwin,0,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    


    std::string menuchoices[5] = {"Choice 1", "Choice 2", "Choice 3", "Choice 4", "Choice 5"};

    int choice;
    int highlight = 0;

    while(1)
    {
	for (int i = 0; i < LEN(menuchoices)+1; i++)
	{
	    if (i == highlight)
	    {
		wattron(menuwin, A_REVERSE);
	    }
	    
	    mvwprintw(menuwin, i+1, 1, menuchoices[i].c_str());
	    wattroff(menuwin, A_REVERSE);
	}
	choice = wgetch(menuwin);

	switch(choice)
	{
	case KEY_UP:
	    highlight--;
	    if (highlight == -1)
	    {
		highlight = 0;
	    }
	    break;
	case KEY_DOWN:
	    highlight++;
	    if (highlight == LEN(menuchoices))
	    {
		highlight = LEN(menuchoices)-1;
	    }
	    break;
	default:
	    break;
	
	}
	if (choice == 10)
	{
	    break;
	}
    }
    
    mvprintw((maxY -3),(maxY-menuchoices[highlight].length()),menuchoices[highlight].c_str());
    
    getch();
    endwin();

    return (0);
}
