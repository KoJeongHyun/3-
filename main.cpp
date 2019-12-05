#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"transNum.h"
#include"checkData.h"
#include"gamePlay.h"
#include"userInput.h"
#include"computerInput.h"
#include"keyControl.h"
#include"print.h"
#include"window.h"

int main() {
	int gameFlag = 1;
	int keyInput;

	srand((int)time(NULL));
	init();
	
	while (gameFlag) {
		system("cls");
		titleDraw();
		keyInput = menuDraw();
		
		switch (keyInput) {
		case 0:
			startGame();
			break;
		case 1:
			infoDraw();
			break;
		case 2:
			gameFlag = 0;
			break;
		}
	}
	return 0;
}