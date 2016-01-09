#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);  // Pin and # of Displays

unsigned long delayTime=200;  // Delay between Frames

void setup() {
	lc.shutdown(0,false);  // Wake up display
	lc.setIntensity(0,5);  // Set intensity levels
	lc.clearDisplay(0);  // Clear Display

	// Player vars
	int pos_x = 0;
	int pos_y = 0;
}

char lineOneC[8] = {1,1,1,0,1,1,1,1};
char lineOneB = 0;

byte charToByte(char lineC[8]) {
	char lineB = 0;
	for (int i = 0; i < 8; i++) { lineB |= lineC[i] << (7-i); }
	return lineB;
}

void loop() {
	for (int i = 0; i < 8; i++)
	{
		lc.setRow(0,i,charToByte(lineOneC));
	}
	delay(delayTime);
}
