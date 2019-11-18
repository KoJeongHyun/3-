#include <stdio.h>
#include <conio.h>

#define GAME_CHIPER 4

int userInput(const char* msg, char* inputStr, int* count)
{
	int i;
	printf(msg, *count);

	for (i = 0; i < GAME_CHIPER; i++)
	{
		inputStr[i] = getche();

		if (inputStr[i] > '9' || inputStr[i] < '0')
			return 1;
	}

	*count += 1;	//사용자가 성공적으로 값을 입력하면 플레이 횟수를 1 증가
	
	return 0;
}