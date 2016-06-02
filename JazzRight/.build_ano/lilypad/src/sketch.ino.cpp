#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
int frequencies[5] = {1046, 1175, 1316,1397, 1568}; /*C D E F G*/
/*int frequencies[5] = {1046, 1175, 1316,1397, 1568};*/ /*A B C D E*/
void setup()
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);
	for (int i = 2; i < 9; ++i)
		pinMode(i, INPUT_PULLUP);
}
void loop()
{
	for (int i = 0; i < 5; ++i)
		if (digitalRead(i + 2) == LOW)
			tone(13, frequencies[i], 20);
	if (digitalRead(7) == LOW){
		for (int i = 0; i < 5; i++)
			frequencies[i] /= 2;
		delay(500);
	}
	else if (digitalRead(8) == LOW){
		for (int i = 0; i < 5; i++)
			frequencies[i] *= 2;
		delay(500);
	}
	for (int i = 0; i < 5; i++)
		Serial.print(frequencies[i]);
	Serial.println("");
}
