#include <LiquidCrystal_I2C.h>
#include "header.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void LcdStart()
{
    lcd.init();
    lcd.backlight();
    lcd.noCursor();
    lcd.noBlink();
    lcd.availableForWrite();
    lcd.createChar(0, arrowUp);
    lcd.createChar(1, arrowDown);
    lcd.createChar(2, arrowLoading);
    delay(100);
}

void LcdPlaceLoadingChar(bool state)
{
    lcd.setCursor(19, 3);
    lcd.write(state ? (char)2 : ' ');
}

void LcdPrintMessage(int messageIndex)
{
    switch (messageIndex)
    {
    case 0:
    {
        lcd.clear();
        lcd.home();
        lcd.setCursor(0, 0);
        lcd.print(F("    arduino/esp32   "));
        lcd.setCursor(0, 1);
        lcd.print(F("   Bitcoin Monitor  "));
        lcd.setCursor(0, 2);
        lcd.print(F("--------------------"));
        lcd.setCursor(0, 3);
        lcd.print(F("GitHub: @matheusbach"));
        delay(2500);
        lcd.clear();
    }
    break;
    case 1:
    {
        lcd.clear();
        lcd.home();
        lcd.println(" ------------------ ");
        lcd.println(" Conectando ao wifi ");
        lcd.println(" ------------------ ");
    }
    case 2:
    {
        lcd.clear();
        lcd.println(" -----------------  ");
        lcd.println("   Chamando APIs    ");
        lcd.println(" -----------------  ");
    }
    break;
    default:
    {
        // code block
    }
    }
}

void LcdPrintMarketPrices()
{
    lcd.setCursor(0, 0);
    lcd.printf("BTC/BRL: R$ ");
    lcd.printf("%.0f", Price_BTCBRL);

    lcd.setCursor(0, 1);
    lcd.printf("BTC/USD: U$ ");
    lcd.printf("%.0f", Price_BTCUSD);

    lcd.setCursor(0, 3);
    lcd.printf("USD/BRL: R$ ");
    lcd.printf("%.2f", Price_USDBRL);

    lcd.setCursor(0, 2);
    lcd.printf("24H BTC: ");
    lcd.write(Price_changeBTCUSD >= 0 ? (char)0 : (char)1);
    lcd.print(" ");
    lcd.printf("%.2f", fabsf(Price_changeBTCUSD));
    lcd.print("%");

    Serial.println();
    Serial.printf("BTC/BRL: R$ ");
    Serial.printf("%.0f", Price_BTCBRL);
    Serial.println();
    Serial.printf("BTC/USD: U$ ");
    Serial.printf("%.0f", Price_BTCUSD);
    Serial.println();
    Serial.printf("USD/BRL: R$ ");
    Serial.printf("%.2f", Price_USDBRL);
    Serial.println();
    Serial.printf("24H BTC: ");
    Serial.write(Price_changeBTCUSD >= 0 ? (char)0 : (char)1);
    Serial.print(" ");
    Serial.printf("%.2f", fabsf(Price_changeBTCUSD));
    Serial.print("%");
    Serial.println();
}