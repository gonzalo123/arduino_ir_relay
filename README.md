Controlling bedside lamp with the TV's remote using Arduino and IR receiver.
======

I've got a new Arduino board (one Arduino nano) and I want to hack a little bit. Today I want to play with IR receiver. My idea is to use my TV's remote and switch on/off one bedside lamp, using one relay. It's a simple Arduino program. First we need to include de IRremote library.

Normally IR receivers have three pins. Vcc (5V), Gnd and signal. We only need to connect the IR receiver to our Arduino and see which hex codes uses our TV's remote. Then we only need to fire our relay depending on the code.

![Circuit](img/img.png?raw=true "Circuit")

```c
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
```

# Hardware:
* 1 Arduino Nano (https://www.arduino.cc/en/Main/ArduinoBoardNano)
* 1 IR receiver
* 1 Relay
* 1 Red led
* a couple of pull down resistors

# Demo
[![Controlling bedside lamp with the TV's remote using Arduino and IR receiver](http://img.youtube.com/vi/VrvagWlpvPc/0.jpg)](https://www.youtube.com/watch?v=VrvagWlpvPc)
