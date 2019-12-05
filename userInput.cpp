#include <stdio.h>
#include <conio.h>
#include"gamePlay.h"
#include"keyControl.h"
#include"window.h"
#include"userInput.h"
#include"print.h"

int userInput(char* inputStr, int* count) {
	int inputCount = 0, index = 0, loopFlag = 1;
	int number = 0;
	int pX = START_X_POSITION, pY = START_Y_POSITION;

	drawGameGraphic(&pX, &pY, count);
	
	while (loopFlag) { // 무한반복  
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기  
		switch (n) {
		case UP: { // 입력된 키의 값이 UP인경우 (w) 
			if (pY > START_Y_POSITION) {
				number -= 5;
				gotoxy(pX, pY); 
				printf("  ");
				gotoxy(pX, pY -= 2);  
				printf("●"); 
			}
			break;
		}

		case DOWN: { // 입력된 키의 값이 DOWN인경우 (s) 
			if (pY < START_Y_POSITION + 2) {
				number += 5;
				gotoxy(pX, pY);
				printf("  ");
				gotoxy(pX, pY += 2);   
				printf("●");
			}
			break;
		}

		case LEFT: { // 입력된 키의 값이 LEFT인경우 (a) 
			if (pX > START_X_POSITION + 1) {
				number -= 1;
				gotoxy(pX, pY);  
				printf("  "); 
				gotoxy(pX -= 7, pY); 
				printf("●");
			}
			break;
		}

		case RIGHT: { // 입력된 키의 값이 RIGHT인경우 (d) 
			if (pX < 40) { // 입력의 오른쪽 상한선 값을 계산하면 40이 되므로 해당 값 내에서만 이동
				number += 1;
				gotoxy(pX, pY);
				printf("  ");
				gotoxy(pX += 7, pY);
				printf("●");
			}
			break;
		}
		case SUBMIT: {
			inputStr[index] = (char)number + '0';
			++index;	

			if (++inputCount == GAME_CHIPER)
				loopFlag = 0;

			break;
		}
		}
	}
	*count += 1;

	return 0;
}