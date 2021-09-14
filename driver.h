#ifndef DRIVER_HEADER
#define DRIVER_HEADER

namespace driver {
  namespace motors {
      void setup();
      void enable();
      void disable();
      void forward();
      void backward();
      void stop_break();
      void stop_release();
  }

  namespace button {
    void setup();
    volatile bool isPressed;
    bool getButtonValue();
    void updateIsPressed();
    void setOnPress();
  }

  namespace buzzer {
    void setup();
    void on();
    void off();
  }

  namespace irsensors {
    void setup();
    int read(int pin);
    int read_all();
  }
}

#endif