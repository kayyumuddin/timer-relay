#include <Arduino.h>
#include <SimpleTimer.h>

SimpleTimer timer;

#define relay_pin 13

bool pin_status = false;

void relay_on();
void relay_off();

void relay_on()
{
  if (pin_status == false)
  {
    digitalWrite(relay_pin, HIGH);
    pin_status = true;
    timer.setTimeout(60000L, relay_off);
  }
}

void relay_off()
{
  if (pin_status == true)
  {
    digitalWrite(relay_pin, LOW);
    pin_status = false;
    timer.setTimeout(300000L, relay_on);
  }
}

void setup()
{
  pinMode(relay_pin, OUTPUT);
  relay_on();
}

void loop()
{
  timer.run();
}