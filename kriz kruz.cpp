#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#include <iostream>
using namespace std;

void restart()
{
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	//960, 540
	line(360, 0, 360, 1080);
	line(720, 0, 720, 1080);
	//l,d
	line(0, 360, 1080, 360);
	line(0, 720, 1080, 720);
	//g,d
}  

void stvorix(int mj) 
{
	setcolor(RED);
	if (mj == 1) 
	{
		line(0, 0, 360, 360);
		line(0, 360, 360, 0);
	}
	else if (mj == 2)
	{
		line(360, 0, 720, 360);
		line(360, 360, 720, 0);
	}
	else if (mj == 3)
	{
		line(720, 0, 1080, 360);
		line(720, 360, 1080, 0);
	}
	else if (mj == 4)
	{
		line(0, 360, 360, 720);
		line(0, 720, 360, 360);
	}
	else if (mj == 5)
	{
		line(360, 360, 720, 720);
		line(720, 360, 360, 720);
	}
	else if (mj == 6)
	{
		line(720, 360, 1080, 720);
		line(1080, 360, 720, 720);
	}
	else if (mj == 7)
	{
		line(0, 720, 360, 1080);
		line(360, 720, 0, 1080);
	}
	else if (mj == 8)
	{
		line(360, 720, 720, 1080);
		line(720, 720, 360, 1080);
	}
	if (mj == 9)
	{
		line(720, 720, 1080, 1080);
		line(1080, 720, 720, 1080);
	}
}

void stvorio(int mj)
{
	setcolor(BLUE);
	if (mj == 1)
	{
		circle(180, 180, 180);
	}
	if (mj == 2)
	{
		circle(540, 180, 180);
	}
	if (mj == 3)
	{
		circle(900, 180, 180);
	}
	if (mj == 4)
	{
		circle(180, 540, 180);
	}
	if (mj == 5)
	{
		circle(540, 540, 180);
	}
	if (mj == 6)
	{
		circle(900, 540, 180);
	}
	if (mj == 7)
	{
		circle(180, 900, 180);
	}
	if (mj == 8)
	{
		circle(540, 900, 180);
	}
	if(mj == 9)
	{
		circle(900, 900, 180);
	}
}

void pobijeda(int br) 
{
	setcolor(BLACK);
	if (br == 1)
		line(180, 0, 180, 1080);
	if (br == 2)
		line(540, 0, 540, 1080);
	if (br == 3)
		line(900, 0, 900, 1080);
	if (br == 4)
		line(0, 180, 1080, 180);
	if (br == 5)
		line(0, 540, 1080, 540);
	if (br == 6)
		line(0, 900, 1080, 900);
	if (br == 7)
		line(0, 0, 1080, 1080);
	if (br == 8)
		line(1080, 1080, 0, 0);
}

bool provjera(char *p) 
{

	if (*(p) == *(p + 1) && *(p) == *(p + 2)) 
	{
		if (*p == 'x' || *p == 'o')
		{
			pobijeda(14);
			return 1;
		}
	}
	if (*(p + 3) == *(p + 4) && *(p + 3) == *(p + 5))
	{
		if (*(p + 3) == 'x' || *(p + 3) == 'o')
		{
			pobijeda(5);
			return 1;
		}
	}
	if (*(p + 5) == *(p + 6) && *(p + 5) == *(p + 7))
	{
		if (*(p + 5) == 'x' || *(p + 5) == 'o')
		{
			pobijeda(6);
			return 1;
		}
	}
	if (*(p) == *(p + 3) && *(p) == *(p + 6))
	{
		if (*p == 'x' || *p == 'o')
		{
			pobijeda(1);
			return 1;
		}
	}
	if (*(p + 1) == *(p + 4) && *(p + 1) == *(p + 7))
	{
		if (*(p + 1) == 'x' || *(p + 1) == 'o')
		{
			pobijeda(2);
			return 1;
		}
	}
	if (*(p + 2) == *(p + 5) && *(p + 2) == *(p + 8))
	{
		if (*(p + 2) == 'x' || *(p + 2) == 'o')
		{
			pobijeda(3);
			return 1;
		}
	}
	if (*(p) == *(p + 4) && *(p) == *(p + 8))
	{
		if (*p == 'x' || *p == 'o')
		{
			pobijeda(7);
			return 1;
		}
	}
	if (*(p + 2) == *(p + 4) && *(p + 2) == *(p + 6)) 
	{
		if (*(p + 2) == 'x' || *(p + 2) == 'o')
		{
			pobijeda(8);
			return 1;
		}
	}

	return 0;
}

void dodajx(char *p, int br) 
{
	stvorix(br+1);
	*(p + br) = 'x';
}

void dodajo(char* p, int br)
{
	stvorio(br+1);
	*(p + br) = 'o';
}

int main()
{
	int x, o;
	initwindow(1080, 1080, "kriz kruz");
	while (1) 
	{
		system("CLS");
		restart();
		char p[3][3] = {
		{'0','0','0'},
		{'0','0','0'},
		{'0','0','0'}
		};
		while (1)
		{
			cin >> x;
			dodajx(&p[0][0], x - 1);
			if (provjera(&p[0][0]))
			{
				delay(2000);
				break;
			}
			cin >> o;
			dodajo(&p[0][0], o - 1);
			if (provjera(&p[0][0]))
			{
				delay(2000);
				break;
			}
		}
	}

	getch();
	cleardevice();

	return 0;

}
