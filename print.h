#pragma once

#define START_X_POSITION 11
#define START_Y_POSITION 5
#define ROW 20
#define COL 56

void titleDraw();
void infoDraw();
int menuDraw();
int output(int, int*, int*, int*);
void drawGameGraphic(int*, int*, int*);
void drawText(int*, int*, int*);
void drawFrame();