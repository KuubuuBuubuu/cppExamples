#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator {
public:
  Oscillator();
  ~Oscillator();
  void setFrequency(float frequency);
  float getFrequency();
  void displayCount();

private:
  float frequency;
  static int count;
};
#endif
