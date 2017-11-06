/*
*
* Original code from https://create.arduino.cc/projecthub/39290/useless-box-944ae4
* Modified by Velleman nv
* VarSpeedServo library can be found here => https://github.com/netlabtoolkit/VarSpeedServo
*/

#include <VarSpeedServo.h>

#define switchpin 5
#define servopin 2

VarSpeedServo lid;

void setup() {
  pinMode(switchpin, INPUT_PULLUP);

  lid.attach(servopin);
  closelid(255);
}

void(* resetFunc) (void) = 0;

void loop() {
  while (digitalRead(switchpin));
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(255);
  resetck();
  while (digitalRead(switchpin));
  openlid(40);
  delay(800);
  closelid(255);
  resetck();
  while (digitalRead(switchpin));
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(255);
  delay(500);
  while (digitalRead(switchpin));
  lid.write(95, 25, true);
  delay(950);
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(255);
  resetck();
  while (digitalRead(switchpin));
  delay(1500);
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(150);
  while (digitalRead(switchpin));
  lid.write(110, 255, true);
  delay(800);
  openlid(20);
  delay(800);
  lid.write(110, 25, true);
  delay(800);
  closelid(255);
  resetck();
  while (digitalRead(switchpin));
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(255);
  while (digitalRead(switchpin));
  delay(1500);
  openlid(255);
  delay(1500);
  closelid(255);
  resetck();
  while (digitalRead(switchpin));
  delay(1500);
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  lid.write(90, 10, true);
  delay(800);
  openlid(255);
  delay(250);
  lid.write(90, 10, true);
  delay(800);
  openlid(255);
  delay(1000);
  closelid(255);
  resetck();
  while (digitalRead(switchpin));
  delay(850);
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(10);
  resetck();
  while (digitalRead(switchpin));
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(255);
  delay(800);
  resetck();
  while (digitalRead(switchpin));
  delay(250);
  openlid(255);
  while (!digitalRead(switchpin));
  delay(300);
  closelid(255);
  resetck();
  while (digitalRead(switchpin));
  delay(250);
  openlid(45);
  delay(1250);
  closelid(45);
  delay(1250);
  resetck();
  while (digitalRead(switchpin));
  openlid(10);
  delay(1500);
  closelid(10);
  delay(650);
  openlid(255);
  delay(1000);
  closelid(255);
}


void closelid(byte recv) {
  lid.write(10, recv, true);
}

void openlid(byte recv) {
  lid.write(140, recv, true);
}

void resetck() {
  unsigned long lastmillis = millis();
  while (digitalRead(switchpin)) if (millis() - lastmillis > 10000) resetFunc();
}


