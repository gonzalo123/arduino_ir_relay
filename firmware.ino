#include <IRremote.h>

#define IR 11
#define RELAY 9

IRrecv irrecv(IR);
IRsend irsender;
decode_results results;

unsigned long code;

void setup()
{
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);

  irrecv.blink13(true);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned long current = results.value;
    if (current != code) {
      code = current;
      switch (code) {
        case 3772833823:
          digitalWrite(RELAY, HIGH);
          break;
        case 3772829743:
          digitalWrite(RELAY, LOW);
          break;
      }
    }

    irrecv.resume();
    delay(100);
  }
}
