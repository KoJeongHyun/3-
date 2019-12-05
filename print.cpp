#include<stdio.h>
#include<conio.h>
#include"userInput.h"
#include"gamePlay.h"
#include"window.h"
#include"keyControl.h"
#include"print.h"
#include"window.h"

void titleDraw(void) {
	int i, j;
	char ary[][COL] = {
	"000001111011000001110001110111101100000100000100000",
	"000001001010100010000010000100101010000100000100000",
	"000001110011110001110001110111001111000100000100000",
	"000001001010001000001010000100101000100100000100000",
	"000001111010000101110001110111101000010111110111110"
	};
	printf("\n\n\n");

	for (i = 0; i < sizeof(ary) / sizeof(ary[0]); ++i) {
		for (j = 0; j < sizeof(ary[0]) / sizeof(ary[0][0]); ++j) {
			if (ary[i][j] == '1')
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void infoDraw()
{
	system("cls"); // 화면 모두 지우기  
	printf("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: W, A, S, D\n");
	printf("                    선택: 스페이스바\n\n");
	printf("                       [ 게임방법 ]               \n\n");
	printf("       0 ~ 9 사이의 숫자들 중에서 컴퓨터가 랜덤하게\n");
	printf("  생성한 네개의 숫자를 모두 맞추면 승리하는 게임입니다.\n");
	printf("  입력한 숫자와 랜덤하게 생성된 숫자를 비교하여 자릿수\n");
	printf("  및 숫자가 모두 일치하면 Strike 이고 숫자는 일치하되\n");
	printf("   자리가 맞지 않으면 Ball 입니다. 4S 이면 승리입니다.\n\n\n");
	printf("               개발자: 고경빈, 고정현, 신지원\n\n");
	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

int menuDraw(void) {
	int x = 24;
	int y = 12;
	gotoxy(x - 2, y); // -2 한 이유는 > 를 출력해야하기 때문에  
	printf("> 게임시작");
	gotoxy(x, y + 1);
	printf("게임정보");
	gotoxy(x, y + 2);
	printf("  종료  ");
	while (1) { // 무한반복  
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기  
		switch (n) {
		case UP: { // 입력된 키의 값이 UP인경우 (w) 
			if (y > 12) { // y는 12~14까지만 이동  
				gotoxy(x - 2, y); // x-2 하는 이유는 ">"를 두칸 이전에 출력하기위해  
				printf(" "); // 원래 위치를 지우고  
				gotoxy(x - 2, --y); // 새로 이동한 위치로 이동하여  
				printf(">"); // 다시 그리기  
			}
			break;
		}

		case DOWN: { // 입력된 키의 값이 DOWN인경우 (s) 
			if (y < 14) { // 최대 14  
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 12; // 스페이스바(선택)되었을 경우 y-12
			// y 시작 위치가 12였으므로 y-12 를 하면 0, 1, 2 세 숫자를 받을 수 있다. 
		}
		}
	}
}

int output(int gameResult, int* strike, int* ball, int *userNum)
{
	int i;
	
	setColor(white, black);
	gotoxy(10, 13);
	printf("                               ");

	gotoxy(8, 15);
	printf("입력 : ");
	
	for (i = 0; i < GAME_CHIPER; ++i) {
		setColor(rand() % white + 1, black);
		printf("%d ", userNum[i]);
	}

	gotoxy(25, 15);
	
	if (gameResult == 0) {//사용자가 입력한 숫자가 strike 도 0이고 ball 도 0인 꽝이라면
		setColor(red, black);
		printf("No!!!\n"); //아예 꽝이라는 문자열 출력
	}

	else if (gameResult == 1 && *strike == 4) { //모든 숫자를 맞추었다면
		setColor(blue, black);
		printf("OK!!!\n"); //게임이 끝났음을 출력
		_getch();
		return 1; //그리고 1을 리턴. 즉, 게임이 끝났음을 의미
	}
	else { //게임이 끝나지 않았다면
		setColor(blue, black);
		printf("%dS ", *strike);
		setColor(yellow, black);
		printf("%dB \n", *ball);
		*strike = 0; //입력한 숫자에서 strike가 몇개인지 출력
		*ball = 0; //입력한 숫자에서 ball이 몇개인지 출력
	}
	return 0; //아직 게임이 끝나지 않았다면 0을 리턴
}

void drawGameGraphic(int *pX, int *pY, int *count) {
	drawText(pX, pY, count);
}

void drawText(int *pX, int *pY, int* count) {
	int i, j;
	int printIndex = 0;

	setColor(white, black);
	gotoxy(35, 15);
	printf("%d회차 PLAYING", *count);

	for (i = 0; i < 2; ++i) {
		for (j = printIndex; j < printIndex + 5; ++j) {
			gotoxy(*pX, *pY);
			setColor(rand() % white + 1, black);
			printf("[  ] %d", j);
			*pX += 7;
		}
		*pX = START_X_POSITION;
		*pY += 2;
		printIndex += 5;
		printf("\n");
	}

	gotoxy(*pX = START_X_POSITION + 1, *pY = START_Y_POSITION);
	printf("●");
}

void drawFrame() {
	int i, j;
	char ary[ROW][COL] = {
		"1111111111111111111111111111",
		"1111111111111111111111111111",
		"1111111111111111111111111111",
		"1110000000000000000000000111",
		"1110000000000000000000000111",
		"1110000000000000000000000111",
		"1110000000000000000000000111",
		"1110000000000000000000000111",
		"1110000000000000000000000111",
		"1110000000000000000000000111",
		"1111111111111111111111111111",
		"1111111111111111111111111111",
		"1111111111111111111111111111",
		"1111110000000000000000111111",
		"1111111111111111111111111111",
		"1100000000000000100000000011",
		"1111111111111111111111111111",
		"1111111111111111111111111111",
		"1111111111111111111111111111",
		"1111111111111111111111111111",
	};

	gotoxy(0, 0);
	setColor(white, black);
	for (i = 0; i < sizeof(ary) / sizeof(ary[0]); ++i) {
		for (j = 0; j < sizeof(ary[0]) / sizeof(ary[0][0]); ++j) {
			if (ary[i][j] == '1')
				printf("■");
			else if (ary[i][j] == '0')
				printf("  ");
			else
				;
		}
	}
}