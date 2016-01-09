#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);	// Pin and # of Displays

unsigned long delayTime=100;	// Delay between Frames

// screen initialization
char screen[8][8] = {
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1},
};

// player vars
int player_pos[] {
	8,	// x axis player position on the matrix
	8, 	// y axis player position on the matrix
};

void setup() {
	lc.shutdown(0,false);	// Wake up display
	lc.setIntensity(0,5);	// Set intensity levels
	lc.clearDisplay(0);	 	// Clear Display
}

// 0 == right, 1 == left, 2 == up,
void movePlayer(int player_pos[], int direction) {
	screen[player_pos[1] - 1][player_pos[0] - 1] = 0;

	switch (direction) {
	case 0:	// right
		if (player_pos[0] < 8) player_pos[0]++;
		break;
	case 1:	// left
		if (player_pos[0] > 1) player_pos[0]--;
		break;
	case 2:	// up
		if (player_pos[1] > 1) player_pos[1]--;
		break;
	case 3:	// down
		if (player_pos[1] < 8) player_pos[1]++;
		break;
	}

	screen[player_pos[1] - 1][player_pos[0] - 1] = 1;
}

byte charToByte(char lineC[8]) {
	// lineC stands for line of chars and lineB for a byte line
	char lineB = 0;
	for (int i = 0; i < 8; i++) lineB |= lineC[i] << (7-i);
	return lineB;
}

void loop() {
	movePlayer(player_pos, 1);
	movePlayer(player_pos, 2);
	for (int i = 0; i < 8; i++) lc.setRow(0,i,charToByte(screen[i]));	// draws the screen var to the lcd display
	delay(delayTime);
}
