#include<stdio.h>
#include<conio.h>
#include"window.h"
#include"keyControl.h"
#include"print.h"

void titleDraw(void) {

	printf("\n\n\n\n"); // ������ 4ĭ ����  
	printf("        #####    ###    ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
}

void infoDraw()
{
	system("cls"); // ȭ�� ��� �����  
	printf("\n\n");
	printf("                        [ ���۹� ]\n\n");
	printf("                    �̵�: W, A, S, D\n");
	printf("                    ����: �����̽���\n\n\n\n\n\n\n");
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

int output(int gameResult, int* strike, int* ball)
{
	gotoxy(10, 13);
	printf("                                                      ");
	gotoxy(8, 15);
	
	if (gameResult == 0) //����ڰ� �Է��� ���ڰ� strike �� 0�̰� ball �� 0�� ���̶��
		printf("\tNo!!!\n"); //�ƿ� ���̶�� ���ڿ� ���

	else if (gameResult == 1 && *strike == 4) { //��� ���ڸ� ���߾��ٸ�
		printf("\tOK!!!\n"); //������ �������� ���
		_getch();
		return 1; //�׸��� 1�� ����. ��, ������ �������� �ǹ�
	}
	else {
		printf("\t%dS %dB \n", *strike, *ball); //������ ������ �ʴٸ�
		*strike = 0; //�Է��� ���ڿ��� strike�� ����� ���
		*ball = 0; //�Է��� ���ڿ��� ball�� ����� ���
	}
	return 0; //���� ������ ������ �ʾҴٸ� 0�� ����
}

void drawGameGraphic(int *pX, int *pY, int *count) {
	int i, j;
	int printIndex = 0;
	
	gotoxy(30, 15);
	printf("%dȸ�� PLAYING", *count);

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
	printf("��");
}