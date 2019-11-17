#include <stdio.h>

void transNum(char* strNum, int* userNum)
{
	int i;

	for (i = 0; i < GAME_CHIPER; ++i)
		userNum[i] = strNum[i] - '0';
}
