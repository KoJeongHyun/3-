#include<stdio.h>
#include<conio.h>
#include"window.h"
#include"keyControl.h"
#include"print.h"

void titleDraw(void) {

	printf("\n\n\n\n"); // 맨위에 4칸 개행  
	printf("        #####    ###    ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
}

void infoDraw()
{
	system("cls"); // 화면 모두 지우기  
	printf("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: W, A, S, D\n");
	printf("                    선택: 스페이스바\n\n\n\n\n\n\n");
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

int output(int gameResult, int* strike, int* ball)
{
	gotoxy(10, 13);
	printf("                                                      ");
	gotoxy(8, 15);
	
	if (gameResult == 0) //사용자가 입력한 숫자가 strike 도 0이고 ball 도 0인 꽝이라면
		printf("\tNo!!!\n"); //아예 꽝이라는 문자열 출력

	else if (gameResult == 1 && *strike == 4) { //모든 숫자를 맞추었다면
		printf("\tOK!!!\n"); //게임이 끝났음을 출력
		_getch();
		return 1; //그리고 1을 리턴. 즉, 게임이 끝났음을 의미
	}
	else {
		printf("\t%dS %dB \n", *strike, *ball); //게임이 끝나지 않다면
		*strike = 0; //입력한 숫자에서 strike가 몇개인지 출력
		*ball = 0; //입력한 숫자에서 ball이 몇개인지 출력
	}
	return 0; //아직 게임이 끝나지 않았다면 0을 리턴
}

void drawGameGraphic(int *pX, int *pY, int *count) {
	int i, j;
	int printIndex = 0;
	
	gotoxy(30, 15);
	printf("%d회차 PLAYING", *count);

	for (i = 0; i < 2; ++i) {
		for (j = printIndex; j < printIndex + 5; ++j) {
			gotoxy(*pX, *pY);
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