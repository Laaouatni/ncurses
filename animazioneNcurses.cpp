//#include <iostream> /*per adesso non mi serve questa libreria, dato che ncurses, include in automatico stdio.h che fa le stesse cose I/O */ 
#include <windows.h>
#include <ncurses.h>

using namespace std;

bool divisibile;

void animazione(int y, int x) //funzione creata da me per semplificarmi la programmazione. serve per Output il numero attuale della coordinata X.
{
	initscr();
	x++;
	refresh();
	mvprintw(y, x, " %d", x);
	Sleep(50);
}

void diviso(int x) //questa funzione controlla se il numero è divisibile per la larghezza dello Schermo (X) o no. se è divisibile cambierà il bool in TRUE, oppure FALSE.
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
