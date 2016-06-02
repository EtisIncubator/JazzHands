int orig[5] = {1760, 1976, 2093, 2349, 2638}; /*A B C D E*/
int frequencies[5] = {1760, 1976, 2093, 2349, 2638}; /*A B C D E*/
void wait(int pin)
{
	int pressed;
	do {
		pressed = digitalRead(pin);
	} while(pressed == LOW);
}
void setup()
{
	pinMode(13, OUTPUT);
	for (int i = 2; i < 9; ++i)
		pinMode(i, INPUT_PULLUP);
}
void loop()
{
	for (int i = 0; i < 5; i++)
		if (frequencies[i] <= orig[i]/16 )
			frequencies[i] = orig[i]/8;
	for (int i = 0; i < 5; i++)
		if (digitalRead(i + 2) == LOW)
			tone(13, frequencies[i], 20);
	if (digitalRead(7) == LOW){
		for (int i = 0; i < 5; i++)
			frequencies[i] /= 2;
		wait(7);
	}
	else if (digitalRead(8) == LOW){
		for (int i = 0; i < 5; i++)
			frequencies[i] *= 2;
		wait(8);
	}
}
