#include <iostream>
#include <windows.h>
#include <ncurses.h>

using namespace std;

bool divisibile;

void animazione(int y, int x)
{
	/*test N1*/ 
	initscr();
	x++;
	//y++;
	refresh();
	mvprintw(y, x, " %d", x);
	Sleep(50);
}

void diviso(int x)
{
	if (x % 70 == 0)
	{
		divisibile = true;
	}
	else
	{
		divisibile = false;
	}
}

int main()
{
	initscr();
	int y = 1;
	int x = 2;

	while (x != 0)
	{
		refresh();
		x++;
		animazione(y, x);
		/*y++;
		refresh();
		mvprintw(1, x, " %d", x);
		Sleep(50);*/

		if (x > 70)
		{
			x=1;
			while (divisibile)
			{
				initscr();
				refresh();
				y++;
				animazione(y, x);
				diviso(x);
			}

			while (!divisibile)
			{
				initscr();
				refresh();
				x++;
				animazione(y, x);
				diviso(x);
			}
		}
	}
	return 0;
}
