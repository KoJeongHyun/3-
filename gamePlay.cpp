#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#pragma warning (disable : 4996)

#define GAME_CHIPER 4 //���� �÷��̸� ���� �ڸ���

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