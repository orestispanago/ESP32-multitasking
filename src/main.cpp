#include <Arduino.h>

TaskHandle_t Task1;

void task1(void *parameter)
{
  for (;;)
  {
    Serial.print("task1 running on core ");
    Serial.println(xPortGetCoreID());
    delay(5000);
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
  xTaskCreatePinnedToCore(
      task1,   /* Function to implement the task */
      "Task1", /* Name of the task */
      10000,   /* Stack size in words */
      NULL,    /* Task input parameter */
      0,       /* Priority of the task */
      &Task1,  /* Task handle. */
      0);      /* Core where the task should run */
}
void loop()
{
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());
  delay(10000);
}