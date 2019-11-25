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
			ranNum[i] = rand() % GAME_NUMBER;	//0~9 사이의 수를 생성

		if (checkData(ranNum))
			continue;	//중복 검사

		overlap = 0;	//중복이 없다면 루프 종료
	}
}