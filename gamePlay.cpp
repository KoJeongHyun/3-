#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include"checkData.h"
#include"userInput.h"
#include"computerInput.h"
#include"transNum.h"
#include"gamePlay.h"
#include"print.h"
#pragma warning (disable : 4996)

void startGame() {
	int ranNum[GAME_CHIPER]; //컴퓨터가 랜덤으로 생성한 숫자를 저장하는 배열
	char inputStr[GAME_CHIPER]; //사용자가 입력한 문자열 데이터를 저장하는 배열
	int userNum[GAME_CHIPER]; //inputStr을 참조하여 사용자가 입력한 문자열을 정수로 변환한 값을 저장하는 배열
	int gameResult;
	int strike = 0, ball = 0, count = 1; //사용자가 입력한 숫자의 strike와 ball의 갯수를 저장하는 변수들과 현재 플레이한 횟수를 저장하는 count 변수
	int i;

	system("cls");
	computerInput(ranNum); //컴퓨터가 GAME_CHIPER 갯수만큼의 중복없는 랜덤한 숫자 생성

	for (i = 0; i < GAME_CHIPER; i++) //디버깅용 코드. 컴퓨터가 랜덤하게 발생시킨 숫자를 화면에 출력. 시연용 프로그램에선 삭제될 코드
		printf("%d ", ranNum[i]);

	printf("\n");

	while (1)
	{
		if (userInput(inputStr, &count)) { //사용자가 입력한 숫자를 검사하는 함수. 1이 리턴된다면 0 ~ GAME_NUMBER-1 이외의 값이 입력된 것이므로 다시 입력받게 유도
			printf("\t* 범위를 벗어나는 수가 있습니다. 다시 입력하세요!!\n");
			continue; //잘못된 값이 입력된 상황이므로 다시 userInput() 함수를 호출할수 있도록 유도
		}

		transNum(inputStr, userNum); //사용자가 입력한 문자열을 정수로 변환하기 위한 함수

		if (checkData(userNum)) { //사용자가 입력한 숫자에서 중복된 숫자가 있는지 검사하는 함수
			printf("\t* 중복되는 숫자가 있습니다. 다시 입력하세요!!\n");
			_getch();
			--count; //잘못된 입력은 플레이 횟수로 세지 않기때문에 해당 변수의 값을 1만큼 감소
			continue; //잘못된 값이 입력된 상황이므로 다시 userInput() 함수를 호출할수 있도록 유도
		}

		gameResult = gamePlay(ranNum, userNum, &strike, &ball); //사용자가 입력한 숫자를 참조하여 strke와 ball의 갯수 밑 게임종료조건을 판별하기 위한 함수

		if (output(gameResult, &strike, &ball)) //결과를 보고 화면에 출력해주기 위한 함수. 해당 함수가 1을 리턴했다면 게임이 끝났음을 의미.
			break;
		_getch();
	}
}

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