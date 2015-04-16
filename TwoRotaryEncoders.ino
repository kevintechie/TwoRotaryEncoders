#include <rotary.h>

Rotary r = Rotary(2, 3);
Rotary r2 = Rotary(4, 5);

void setup() {
  Serial.begin(115200);
  PCICR |= (1 << PCIE2) | (1 << PCIE1);
  PCMSK2 |= (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21);
  sei();
}

void loop() {

}

ISR(PCINT2_vect) {
  char result = r.process();
  char result2 = r2.process();
  if (result) {
    Serial.println(result == DIR_CW ? "1Right" : "1Left");
  }
  if (result2) {
    Serial.println(result2 == DIR_CW ? "2Right" : "2Left");
  }
}
