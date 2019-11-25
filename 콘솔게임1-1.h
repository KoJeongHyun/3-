#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

enum {

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

int main() {

	init();

	while (1) {

		titleDraw();

		int menuCode = menuDraw();

		if (menuCode == 0) {

			// 게 임 시 작

		}

		else if (menuCode == 1) {

			infoDraw();

		}

		else if (menuCode == 2) {

			break;

		}

		menuCode = 5;

		system("cls");

	}



	gotoxy(30, 19);

	_getch();

	return 0;

}