/*
 Name:		Sketch12.ino
 Created:	7/28/2020 1:58:07 PM
 Author:	Janie
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0, prevSwitchState = 0, reply;

// the setup function runs once when you press reset or power the board
void setup() {
	lcd.begin(16,2);
	pinMode(switchPin, INPUT);
	lcd.print("Ask the");
	lcd.setCursor(0, 1);
	lcd.print("Crystal Ball");
}

// the loop function runs over and over again until power down or reset
void loop() {
	switchState = digitalRead(switchPin);
	if(switchState != prevSwitchState){
		if (switchState == LOW) {
			reply = random(8);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("The ball says:");
			lcd.setCursor(0, 1);
			switch (reply) {
			case 0:
				lcd.print("Yes");
				break;
			case 1:
				lcd.print("Most likely");
				break;
			case 2:
				lcd.print("Certainly");
				break;
			case 3:
				lcd.print("Outlook good");
				break;
			case 4:
				lcd.print("Unsure");
				break;
			case 5:
				lcd.print("Ask again");
				break;
			case 6:
				lcd.print("Doubtful");
				break;
			case 7:
				lcd.print("No forking way!");
				break;
			}
		}
	}
	prevSwitchState = switchState;
}
