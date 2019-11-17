#include <stdio.h>

#define GAME_CHIPER 4

void transNum(char* strNum, int* userNum)
{
	int i;

	for (i = 0; i < GAME_CHIPER; ++i)
		userNum[i] = strNum[i] - '0';
}
