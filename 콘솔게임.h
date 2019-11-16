#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include"function.h"
#pragma warning (disable : 4996)

#define GAME_CHIPER 4
#define GAME_NUMBER 10

int main()
{
	int ranNum[GAME_CHIPER];
	char inputStr[GAME_CHIPER];
	int userNum[GAME_CHIPER];
	int i;
	int gameResult;
	int strike = 0, ball = 0, count = 1;

	srand((int)time(0));

	computerinput(ranNum);


}