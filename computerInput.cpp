#include "checkData"
#include <stdio.h>
#include <stdlib.h>

#define GAME_CHIPER 4
#define GAME_NUMBER 10

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