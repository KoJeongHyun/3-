#pragma warning(disable:4996)
#include<Windows.h>

enum{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void init();
void gotoxy(int, int);
void setColor(int, int);