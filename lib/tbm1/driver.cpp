#include <Arduino.h>
#include "driver.h"
#include "pins.h"

using namespace driver;

namespace motors {
  void setup() {
    pinMode(EN12, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);

    pinMode(EN34, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
  }

  void enable() {
    digitalWrite(EN12, HIGH);
    digitalWrite(EN34, HIGH);
  }

  void disable() {
    digitalWrite(EN12, LOW);
    digitalWrite(EN34, LOW);
  }

  void forward() {
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
  }

  void backward() {
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
  }

  void stop_break() {
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
  }

  void stop_release() {
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
  }
}


namespace button {
  void setup() {
    // init value for global var
    driver::button::isPressed = false;

    // Set up pin    
    pinMode(BUTTON_PIN, INPUT);

    // Set up IRQ
    attachInterrupt(
      digitalPinToInterrupt(BUTTON_PIN),
      updateIsPressed,
      CHANGE
    );
  }

  bool getButtonValue() {
    return digitalRead(BUTTON_PIN);
  }

  void updateIsPressed() {
    driver::button::isPressed = getButtonValue();
  }
}


namespace buzzer {
  void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
  }

  void on() {
    digitalWrite(BUZZER_PIN, HIGH);
  }

  void off() {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

namespace irsensor {
  void setup() {
    pinMode(IR_LEFT_PIN, INPUT);
    pinMode(IR_FRONT_PIN, INPUT);
    pinMode(IR_RIGHT_PIN, INPUT);
  }

  int read(int pin) {
    return analogRead(pin);
  }

  int * read_all(int pin) {
    static int values[3];

    values[0] = read(IR_LEFT_PIN);
    values[1] = read(IR_FRONT_PIN);
    values[2] = read(IR_RIGHT_PIN);

    return values;
  }
}