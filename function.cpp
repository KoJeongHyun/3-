#include "function.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define GAME_CHIPER 4
#define GAME_NUMBER 10

void myFlush();
void computerinput(int* ranNum)
{
	int i;
	int makeNumer = 1;

	while (makeNumer) {
		for (i = 0; i < GAME_CHIPER; i++)
			ranNum[i] = rand() % GAME_NUMBER;

		if (checkData(ranNum))
			continue;

		makeNumer = 0;
	}
}

void transNum(char* strNum, int* userNum)
{
	int i;

	for (i = 0; i < GAME_CHIPER; ++i)
		userNum[i] = strNum[i] - '0';
}

int userinput(const char*, char*, int*);

int checkDate(int*checkArr)
{
	int i, j;

	for (i = 0; i < GAME_CHIPER - 1; ++i)
		for (j = i + 1; j < GAME_CHIPER;++j)
			if (checkArr[i] == checkArr[j])
				return 1;
}
int gamePlay(int*, int*, int*, int*);
int ballChenk(int*, int*);
int output(int, int*, int*);