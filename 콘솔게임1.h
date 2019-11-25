#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

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

void init(void) {
	system("mode  con cols=80 lines=25|title 숫자야구");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
	printf("\n\n\n\n");
	printf("              #      # # # # #    # # # #     # #       ##    #\n");
	printf("       ##     #              #          #     # #     #    #  #\n");
	printf("     #    #   ###            #          #     # #    #      # #\n");
	printf("    #      #  #              #          # # # # #     #    #  #\n");
	printf("     #    #   ###  # # # # # # #        #     # #       ##    #\n");
	printf("       ##     #          #              #     # #       # # # #\n");
	printf("              #          #              #     # #       #     #\n");
	printf("              #          #                    # #       # # # #\n");
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void setColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

int keyControl(void) {
	char temp = _getch();

	if (temp == 'w' || temp == 'W')
	{
		return UP;
	}
	else if (temp == 'a' || temp == 'A')
	{
		return LEFT;
	}
	else if (temp == 's' || temp == 'S')
	{
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D')
	{
		return RIGHT;
	}
	else if (temp == ' ')
	{
		return SUBMIT;
	}
}

int menuDraw(void) {
	int x = 30;
	int y = 15;
	gotoxy(x - 2, y);
	printf("> 게 임 시 작 ");
	gotoxy(x, y+1);
	printf("게 임 정 보");
	gotoxy(x, y+2);
	printf("   종 료   ");
	while (1) {  
		int n = keyControl(); 
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 17) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 12;
		}
		}
	}
}
void infoDraw(void)
{
	system("cls");  
	printf("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: W, A, S, D\n");
	printf("                    선택: 스페이스바\n\n\n\n\n\n\n");
	printf("               개발자: 고정현, 고경빈, 신지원\n\n");
	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}


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
