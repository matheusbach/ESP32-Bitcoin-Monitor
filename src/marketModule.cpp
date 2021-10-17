#include "ArduinoJson.h"
#include "HTTPClient.h"
#include "header.h"

HTTPClient http;

float Price_BTCUSD = 0;
float Price_BTCBRL = 0;
float Price_USDBRL = 0;
float Price_changeBTCUSD = 0;
float Price_changeBTCBRL = 0;
float Price_changeUSDBRL = 0;

void UpdatePrices(void *parameter)
{
    while (true)
    {
        LcdPlaceLoadingChar(true);

        try
        {
            while (WiFi.status() != WL_CONNECTED)
            {
                Serial.print(".");
            }

            http.begin("https://economia.awesomeapi.com.br/json/last/BTC-USD,USD-BRL");
            int httpCode = http.GET();
            if (httpCode > 0)
            { //Maior que 0, tem resposta a ser lida

                // Stream& input;

                StaticJsonDocument<0> filter;
                filter.set(true);

                StaticJsonDocument<1024> doc;

                DeserializationError error = deserializeJson(doc, http.getString(), DeserializationOption::Filter(filter));

                if (error)
                {
                    Serial.print(F("deserializeJson() failed: "));
                    Serial.println(error.f_str());
                }
                else
                {
                    JsonObject BTCUSD = doc["BTCUSD"];
                    const char *BTCUSD_high = BTCUSD["high"];           // "57839"
                    const char *BTCUSD_low = BTCUSD["low"];             // "56301"
                    const char *BTCUSD_pctChange = BTCUSD["pctChange"]; // "0.84"
                    const char *BTCUSD_bid = BTCUSD["bid"];             // "56903.4"

                    JsonObject USDBRL = doc["USDBRL"];
                    const char *USDBRL_high = USDBRL["high"];           // "5.5386"
                    const char *USDBRL_low = USDBRL["low"];             // "5.5367"
                    const char *USDBRL_pctChange = USDBRL["pctChange"]; // "0"
                    const char *USDBRL_bid = USDBRL["bid"];             // "5.5355"

                    Price_BTCUSD = atof(BTCUSD_bid);
                    Price_BTCBRL = atof(BTCUSD_bid) * atof(USDBRL_bid);
                    Price_USDBRL = atof(USDBRL_bid);
                    Price_changeBTCUSD = atof(BTCUSD_pctChange);
                    Price_changeBTCBRL = atof(BTCUSD_pctChange) + atof(USDBRL_pctChange);
                    Price_changeUSDBRL = atof(USDBRL_pctChange);

                    LcdPrintMarketPrices();
                }
            }
            else
            {
                Serial.println("Falha na requisição");
            }
            http.end();

            LcdPlaceLoadingChar(false);
            vTaskDelay(pdMS_TO_TICKS(60000));
        }
        catch (const char *msg)
        {
            LcdPlaceLoadingChar(false);
            vTaskDelay(pdMS_TO_TICKS(10000));
        }
    }
}