#include <stdio.h>
#include "setColor.h"
#include "gotoxy.h"
#include "userInput.h"

void drawUI(int *strike, int *ball)
{
	setColor(white, black);
	gotoxy(0, 14);
	printf("########################################################");

	gotoxy(3, 16);
	printf("%dS %dB", *strike, *ball);

	setColor(red, black);
	gotoxy(34, 16);
	
	if (pInput == 1)
	{
		printf("* ������ ����� ���� �ֽ��ϴ�. �ٽ� �Է��ϼ���!!\n");
	}

	setColor(white, black);
}