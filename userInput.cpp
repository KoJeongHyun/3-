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
	
	while (loopFlag) { // ���ѹݺ�  
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���  
		switch (n) {
		case UP: { // �Էµ� Ű�� ���� UP�ΰ�� (w) 
			if (pY > START_Y_POSITION) {
				number -= 5;
				gotoxy(pX, pY); 
				printf("  ");
				gotoxy(pX, pY -= 2);  
				printf("��"); 
			}
			break;
		}

		case DOWN: { // �Էµ� Ű�� ���� DOWN�ΰ�� (s) 
			if (pY < START_Y_POSITION + 2) {
				number += 5;
				gotoxy(pX, pY);
				printf("  ");
				gotoxy(pX, pY += 2);   
				printf("��");
			}
			break;
		}

		case LEFT: { // �Էµ� Ű�� ���� LEFT�ΰ�� (a) 
			if (pX > START_X_POSITION + 1) {
				number -= 1;
				gotoxy(pX, pY);  
				printf("  "); 
				gotoxy(pX -= 7, pY); 
				printf("��");
			}
			break;
		}

		case RIGHT: { // �Էµ� Ű�� ���� RIGHT�ΰ�� (d) 
			if (pX < 40) { // �Է��� ������ ���Ѽ� ���� ����ϸ� 40�� �ǹǷ� �ش� �� �������� �̵�
				number += 1;
				gotoxy(pX, pY);
				printf("  ");
				gotoxy(pX += 7, pY);
				printf("��");
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