#include "checkData.h"
#include <stdio.h>
#include <stdlib.h>
#include"computerInput.h"

void computerInput(int *ranNum)
{
	int i;
	int overlap = 1;

	while (overlap)
	{
		for (i = 0; i < GAME_CHIPER; i++)
			ranNum[i] = rand() % GAME_NUMBER;	//0~9 ������ ���� ����

		if (checkData(ranNum))
			continue;	//�ߺ� �˻�

		overlap = 0;	//�ߺ��� ���ٸ� ���� ����
	}
}