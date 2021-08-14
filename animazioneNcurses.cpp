//#include <iostream> /*per adesso non mi serve questa libreria, dato che ncurses, include in automatico stdio.h che fa le stesse cose I/O */ 
#include <windows.h>
#include <ncurses.h>

using namespace std;

bool isDivisible;

void animazione(int asseY, int asseX) //funzione creata da me per semplificarmi la programmazione. serve per Output il numero attuale della coordinata asseX.
{
	initscr();
	asseX++;
	refresh();
	mvprintw(asseY, asseX, " %d", asseX);
	Sleep(50);
}

void divedereTest(int asseX) //questa funzione controlla se il numero è isDivisible per la larghezza dello Schermo (asseX) o no. se è isDivisible cambierà il bool in TRUE, oppure FALSE.
{
	if (asseX % 70 == 0)
	{
		isDivisible = true;
	}
	else
	{
		isDivisible = false;
	}
}

int main()
{
	initscr();
	int asseY = 1;
	int asseX = 2;

	while (asseX != 0)
	{
		refresh();
		asseX++;
		animazione(asseY, asseX);

		if (asseX > 70)
		{
			asseX=1;
			while (isDivisible)
			{
				initscr();
				refresh();
				asseY++;
				animazione(asseY, asseX);
				divedereTest(asseX);
			}

			while (!isDivisible)
			{
				initscr();
				refresh();
				asseX++;
				animazione(asseY, asseX);
				divedereTest(asseX);
			}
		}
	}
	return 0;
}
