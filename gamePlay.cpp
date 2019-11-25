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
	int ranNum[GAME_CHIPER]; //��ǻ�Ͱ� �������� ������ ���ڸ� �����ϴ� �迭
	char inputStr[GAME_CHIPER]; //����ڰ� �Է��� ���ڿ� �����͸� �����ϴ� �迭
	int userNum[GAME_CHIPER]; //inputStr�� �����Ͽ� ����ڰ� �Է��� ���ڿ��� ������ ��ȯ�� ���� �����ϴ� �迭
	int gameResult;
	int strike = 0, ball = 0, count = 1; //����ڰ� �Է��� ������ strike�� ball�� ������ �����ϴ� ������� ���� �÷����� Ƚ���� �����ϴ� count ����
	int i;

	system("cls");
	computerInput(ranNum); //��ǻ�Ͱ� GAME_CHIPER ������ŭ�� �ߺ����� ������ ���� ����

	for (i = 0; i < GAME_CHIPER; i++) //������ �ڵ�. ��ǻ�Ͱ� �����ϰ� �߻���Ų ���ڸ� ȭ�鿡 ���. �ÿ��� ���α׷����� ������ �ڵ�
		printf("%d ", ranNum[i]);

	printf("\n");

	while (1)
	{
		if (userInput(inputStr, &count)) { //����ڰ� �Է��� ���ڸ� �˻��ϴ� �Լ�. 1�� ���ϵȴٸ� 0 ~ GAME_NUMBER-1 �̿��� ���� �Էµ� ���̹Ƿ� �ٽ� �Է¹ް� ����
			printf("\t* ������ ����� ���� �ֽ��ϴ�. �ٽ� �Է��ϼ���!!\n");
			continue; //�߸��� ���� �Էµ� ��Ȳ�̹Ƿ� �ٽ� userInput() �Լ��� ȣ���Ҽ� �ֵ��� ����
		}

		transNum(inputStr, userNum); //����ڰ� �Է��� ���ڿ��� ������ ��ȯ�ϱ� ���� �Լ�

		if (checkData(userNum)) { //����ڰ� �Է��� ���ڿ��� �ߺ��� ���ڰ� �ִ��� �˻��ϴ� �Լ�
			printf("\t* �ߺ��Ǵ� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���!!\n");
			_getch();
			--count; //�߸��� �Է��� �÷��� Ƚ���� ���� �ʱ⶧���� �ش� ������ ���� 1��ŭ ����
			continue; //�߸��� ���� �Էµ� ��Ȳ�̹Ƿ� �ٽ� userInput() �Լ��� ȣ���Ҽ� �ֵ��� ����
		}

		gameResult = gamePlay(ranNum, userNum, &strike, &ball); //����ڰ� �Է��� ���ڸ� �����Ͽ� strke�� ball�� ���� �� �������������� �Ǻ��ϱ� ���� �Լ�

		if (output(gameResult, &strike, &ball)) //����� ���� ȭ�鿡 ������ֱ� ���� �Լ�. �ش� �Լ��� 1�� �����ߴٸ� ������ �������� �ǹ�.
			break;
		_getch();
	}
}

int gamePlay(int *ranNum, int *userNum, int *strike, int *ball) {
	int i;

	for (i = 0; i < GAME_CHIPER; i++) {
		if (ranNum[i] == userNum[i]) //���� ����ڰ� �Է��� ���ڿ� ��ǻ�Ͱ� �߻��� ���ڰ� ���� �ڸ������� ��ġ�Ѵٸ�
			*strike += 1; //strike �̹Ƿ� 1��ŭ ����
		else if (ballCheck(&ranNum[i], userNum)) //ball���� ���θ� �Ǵ��ϱ����� ballCheck() �Լ� ȣ��
			*ball += 1; //ballCheck() �Լ��� 1�� �����ߴٸ� ball �̹Ƿ� 1��ŭ ����
	}

	if (*strike == 0 && *ball == 0) //���� ����ڰ� �Է��� ���ڰ� ������ ���̶��
		return 0; //0�� ����
	else
		return 1; //���� �ƴ϶�� 1�� ����
}

int ballCheck(int *ranNum, int *userNum) {
	int i;

	for (i = 0; i < GAME_CHIPER; ++i) { //ballCheck() �Լ��� ȣ��Ǿ��ٴ� ���� �̹� �ش� ���ڴ� strike�� �ش����� �ʴ´ٴ� ��. ��, �ش� ���ڰ� ���� �ڸ��� ���� ���ɼ��� ����
		if (*ranNum == userNum[i]) //strike �� �ƴ����� ���� ���ڰ� �迭 ��򰡿� �����Ѵٸ� 
			return 1; //1�� ����
	}

	return 0; //���� ���ڰ� userNum �迭�� ���ٸ� 0�� ����
}
void myFlush() //���� ���� �Լ�
{
	while (getchar() != '\n');
}