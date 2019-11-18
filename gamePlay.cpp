#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#pragma warning (disable : 4996)

#define GAME_CHIPER 4 //게임 플레이를 위한 자릿수

int gamePlay(int *ranNum, int *userNum, int *strike, int *ball) {
	int i;

	for (i = 0; i < GAME_CHIPER; i++) {
		if (ranNum[i] == userNum[i]) //만약 사용자가 입력한 숫자와 컴퓨터가 발생한 숫자가 같고 자릿수까지 일치한다면
			*strike += 1; //strike 이므로 1만큼 증가
		else if (ballCheck(&ranNum[i], userNum)) //ball인지 여부를 판단하기위한 ballCheck() 함수 호출
			*ball += 1; //ballCheck() 함수가 1을 리턴했다면 ball 이므로 1만큼 증가
	}

	if (*strike == 0 && *ball == 0) //만약 사용자가 입력한 숫자가 완전히 꽝이라면
		return 0; //0을 리턴
	else
		return 1; //꽝이 아니라면 1을 리턴
}

int ballCheck(int *ranNum, int *userNum) {
	int i;

	for (i = 0; i < GAME_CHIPER; ++i) { //ballCheck() 함수가 호출되었다는 뜻은 이미 해당 숫자는 strike에 해당하지 않는다는 뜻. 즉, 해당 숫자가 같은 자리에 있을 가능성이 없음
		if (*ranNum == userNum[i]) //strike 는 아니지만 같은 숫자가 배열 어딘가에 존재한다면 
			return 1; //1을 리턴
	}

	return 0; //같은 숫자가 userNum 배열에 없다면 0을 리턴
}
void myFlush() //버퍼 비우는 함수
{
	while (getchar() != '\n');
}