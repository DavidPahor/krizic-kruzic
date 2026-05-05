#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#include <iostream>
using namespace std;

void restart(int r)
{
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	line((1.0/3)*r, 0, (1.0 / 3) * r, r);
	line((2.0 / 3) * r, 0, (2.0 / 3) * r, r);
	//l,d
	line(0, (1.0 / 3) * r, 1080, (1.0 / 3) * r);
	line(0, (2.0 / 3) * r, 1080, (2.0 / 3) * r);
	//g,d
}  

void stvorix(int mj, int r) 
{
	float p1, p2;
	p1 = (1.0 / 3) * r;
	p2 = (2.0 / 3) * r;

	setcolor(RED);
	if (mj == 1) 
	{
		line(0, 0, p1, p1);
		line(0, p1, p1, 0);
	}
	else if (mj == 2)
	{
		line(p1, 0, p2, p1);
		line(p1, p1, p2, 0);
	}
	else if (mj == 3)
	{
		line(p2, 0, r, p1);
		line(p2, p1, r, 0);
	}
	else if (mj == 4)
	{
		line(0, p1, p1, p2);
		line(0, p2, p1, p1);
	}
	else if (mj == 5)
	{
		line(p1, p1, p2, p2);
		line(p2, p1, p1, p2);
	}
	else if (mj == 6)
	{
		line(p2, p1, r, p2);
		line(r, p1, p2, p2);
	}
	else if (mj == 7)
	{
		line(0, p2, p1, r);
		line(p1, p2, 0, r);
	}
	else if (mj == 8)
	{
		line(p1, p2, p2, r);
		line(p2, p2, p1, r);
	}
	if (mj == 9)
	{
		line(p2, p2, r, r);
		line(r, p2, p2, r);
	}
}

void stvorio(int mj, int r)
{
	float p1, pom;
	p1 = (1.0 / 3) * r;;
	pom = p1 / 2;

	setcolor(BLUE);
	if (mj == 1)
	{
		circle(pom, pom, pom);
	}
	if (mj == 2)
	{
		circle(p1+pom, pom, pom);
	}
	if (mj == 3)
	{
		circle(p1*2 + pom, pom, pom);
	}
	if (mj == 4)
	{
		circle(pom, p1 + pom, pom);
	}
	if (mj == 5)
	{
		circle(p1 + pom, p1 + pom, pom);
	}
	if (mj == 6)
	{
		circle(p1 * 2 + pom, p1 + pom, pom);
	}
	if (mj == 7)
	{
		circle(pom, p1 * 2 + pom, pom);
	}
	if (mj == 8)
	{
		circle(p1 + pom, p1 * 2 + pom, pom);
	}
	if(mj == 9)
	{
		circle(p1 * 2 + pom, p1 * 2 + pom, pom);
	}
}

void pobijeda(int br, int r) 
{
	float p1, pom;
	p1 = (1.0 / 3) * r;
	pom = p1 / 2;

	setcolor(BLACK);
	if (br == 1)
		line(pom, 0, pom, r);
	if (br == 2)
		line(p1 + pom, 0, p1 + pom, r);
	if (br == 3)
		line(p1 * 2 + pom, 0, p1 * 2 + pom, r);
	if (br == 4)
		line(0, pom, r, pom);
	if (br == 5)
		line(0, p1 + pom, r, p1 + pom);
	if (br == 6)
		line(0, p1 * 2 + pom, r, p1 * 2 + pom);
	if (br == 7)
		line(0, 0, r, r);
	if (br == 8)
		line(r, 0, 0, r);
}

int provjera(char *p, int r) 
{

	if (*(p) == *(p + 1) && *(p) == *(p + 2)) 
	{
		if (*p == 'x' || *p == 'o')
		{
			pobijeda(4,r);
			return 1;
		}
	}
	if (*(p + 3) == *(p + 4) && *(p + 3) == *(p + 5))
	{
		if (*(p + 3) == 'x' || *(p + 3) == 'o')
		{
			pobijeda(5, r);
			return 1;
		}
	}
	if (*(p + 6) == *(p + 7) && *(p + 6) == *(p + 8))
	{
		if (*(p + 6) == 'x' || *(p + 6) == 'o')
		{
			pobijeda(6, r);
			return 1;
		}
	}
	if (*(p) == *(p + 3) && *(p) == *(p + 6))
	{
		if (*p == 'x' || *p == 'o')
		{
			pobijeda(1, r);
			return 1;
		}
	}
	if (*(p + 1) == *(p + 4) && *(p + 1) == *(p + 7))
	{
		if (*(p + 1) == 'x' || *(p + 1) == 'o')
		{
			pobijeda(2, r);
			return 1;
		}
	}
	if (*(p + 2) == *(p + 5) && *(p + 2) == *(p + 8))
	{
		if (*(p + 2) == 'x' || *(p + 2) == 'o')
		{
			pobijeda(3, r);
			return 1;
		}
	}
	if (*(p) == *(p + 4) && *(p) == *(p + 8))
	{
		if (*p == 'x' || *p == 'o')
		{
			pobijeda(7, r);
			return 1;
		}
	}
	if (*(p + 2) == *(p + 4) && *(p + 2) == *(p + 6)) 
	{
		if (*(p + 2) == 'x' || *(p + 2) == 'o')
		{
			pobijeda(8, r);
			return 1;
		}
	}

	for (int i = 0; i < 9; i++) 
	{
		if (*(p + i) == '0')
			return 0;
	}
	return 3;
}

bool dodajx(char *p, int br, int r) 
{
	if (*(p + br) != '0' || br > 8)
		return 1;
	stvorix(br+1, r);
	*(p + br) = 'x';
	return 0;
}

bool dodajo(char* p, int br, int r)
{
	if (*(p + br) != '0' || br > 8)
		return 1;
	stvorio(br+1, r);
	*(p + br) = 'o';
	return 0;
}

void igra(int r) 
{
	int x, o, i = 0;
	initwindow(r, r, "kriz kruz");
	while (1)
	{
		system("CLS");
		restart(r);
		char p[3][3] = {
		{'0','0','0'},
		{'0','0','0'},
		{'0','0','0'}
		};
		while (1)
		{
			do {
				cin >> x;
			} while (dodajx(&p[0][0], x - 1,r));
			if (provjera(&p[0][0],r) != 0)
			{
				delay(2000);
				break;
			}
			do {
				cin >> o;
			} while (dodajo(&p[0][0], o - 1,r));
			if (provjera(&p[0][0],r) != 0)
			{
				delay(2000);
				break;
			}
		}
	}
}

int main()
{
	int x, y;
	char z;
	cout << "Upisi rezoluciju:";
	cin >> x >> z >> y;
	if (x > y)
		x = y;
	igra(x);



	getch();
	cleardevice();

	return 0;

}
