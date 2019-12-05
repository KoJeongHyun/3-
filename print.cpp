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
	system("cls"); // ȭ�� ��� �����  
	printf("\n\n");
	printf("                        [ ���۹� ]\n\n");
	printf("                    �̵�: W, A, S, D\n");
	printf("                    ����: �����̽���\n\n");
	printf("                       [ ���ӹ�� ]               \n\n");
	printf("       0 ~ 9 ������ ���ڵ� �߿��� ��ǻ�Ͱ� �����ϰ�\n");
	printf("  ������ �װ��� ���ڸ� ��� ���߸� �¸��ϴ� �����Դϴ�.\n");
	printf("  �Է��� ���ڿ� �����ϰ� ������ ���ڸ� ���Ͽ� �ڸ���\n");
	printf("  �� ���ڰ� ��� ��ġ�ϸ� Strike �̰� ���ڴ� ��ġ�ϵ�\n");
	printf("   �ڸ��� ���� ������ Ball �Դϴ�. 4S �̸� �¸��Դϴ�.\n\n\n");
	printf("               ������: ����, ������, ������\n\n");
	printf("      �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

int menuDraw(void) {
	int x = 24;
	int y = 12;
	gotoxy(x - 2, y); // -2 �� ������ > �� ����ؾ��ϱ� ������  
	printf("> ���ӽ���");
	gotoxy(x, y + 1);
	printf("��������");
	gotoxy(x, y + 2);
	printf("  ����  ");
	while (1) { // ���ѹݺ�  
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���  
		switch (n) {
		case UP: { // �Էµ� Ű�� ���� UP�ΰ�� (w) 
			if (y > 12) { // y�� 12~14������ �̵�  
				gotoxy(x - 2, y); // x-2 �ϴ� ������ ">"�� ��ĭ ������ ����ϱ�����  
				printf(" "); // ���� ��ġ�� �����  
				gotoxy(x - 2, --y); // ���� �̵��� ��ġ�� �̵��Ͽ�  
				printf(">"); // �ٽ� �׸���  
			}
			break;
		}

		case DOWN: { // �Էµ� Ű�� ���� DOWN�ΰ�� (s) 
			if (y < 14) { // �ִ� 14  
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 12; // �����̽���(����)�Ǿ��� ��� y-12
			// y ���� ��ġ�� 12�����Ƿ� y-12 �� �ϸ� 0, 1, 2 �� ���ڸ� ���� �� �ִ�. 
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
	printf("�Է� : ");
	
	for (i = 0; i < GAME_CHIPER; ++i) {
		setColor(rand() % white + 1, black);
		printf("%d ", userNum[i]);
	}

	gotoxy(25, 15);
	
	if (gameResult == 0) {//����ڰ� �Է��� ���ڰ� strike �� 0�̰� ball �� 0�� ���̶��
		setColor(red, black);
		printf("No!!!\n"); //�ƿ� ���̶�� ���ڿ� ���
	}

	else if (gameResult == 1 && *strike == 4) { //��� ���ڸ� ���߾��ٸ�
		setColor(blue, black);
		printf("OK!!!\n"); //������ �������� ���
		_getch();
		return 1; //�׸��� 1�� ����. ��, ������ �������� �ǹ�
	}
	else { //������ ������ �ʾҴٸ�
		setColor(blue, black);
		printf("%dS ", *strike);
		setColor(yellow, black);
		printf("%dB \n", *ball);
		*strike = 0; //�Է��� ���ڿ��� strike�� ����� ���
		*ball = 0; //�Է��� ���ڿ��� ball�� ����� ���
	}
	return 0; //���� ������ ������ �ʾҴٸ� 0�� ����
}

void drawGameGraphic(int *pX, int *pY, int *count) {
	drawText(pX, pY, count);
}

void drawText(int *pX, int *pY, int* count) {
	int i, j;
	int printIndex = 0;

	setColor(white, black);
	gotoxy(35, 15);
	printf("%dȸ�� PLAYING", *count);

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
	printf("��");
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
				printf("��");
			else if (ary[i][j] == '0')
				printf("  ");
			else
				;
		}
	}
}