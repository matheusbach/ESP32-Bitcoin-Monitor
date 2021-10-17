#define ARDUINOJSON_USE_LONG_LONG 1
#define ARDUINOJSON_USE_DOUBLE 1

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "WiFi.h"
#include "esp_wifi.h"
#include "FreeRTOS.h"
#include "ArduinoJson.h"
#include "header.h"
#include <math.h>

void UpdatePrices(void *parameter);

void setup()
{
  Serial.begin(9600);

  LcdStart();

  LcdPrintMessage(0);

  delay(1000);

  StartNetWorkConnection();

  StartOled();

  CreateRoutineTasks();
}

void loop()
{
}