#include <string>
#include "Arduino.h"

void CreateRoutineTasks();
void UpdatePrices(void *parameter);
void CheckNetworkConnection(void *parameter);
void StartNetWorkConnection();

void LcdStart();
void StartOled();

void SyncSystemTime();

void testdrawline();
void testdrawrect(void);
void testfillrect(void);
void testdrawcircle(void);
void testfillcircle(void);
void testdrawroundrect(void);
void testfillroundrect(void);
void testdrawtriangle(void);
void testfilltriangle(void);
void testdrawchar(void);
void testdrawstyles(void);
void testscrolltext(void);
void testdrawbitmap(void);
void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h);
void testanimate2(const uint8_t *bitmap, uint8_t w, uint8_t h);
void OledAnimateBTC(void *parameter);

extern float Price_BTCUSD;
extern float Price_BTCBRL;
extern float Price_USDBRL;
extern float Price_changeBTCUSD;
extern float Price_changeBTCBRL;
extern float Price_changeUSDBRL;

void LcdPrintMessage(int messageIndex);
void LcdPrintMarketPrices();
void LcdPlaceLoadingChar(bool state);

static const unsigned char PROGMEM logo_bmp[] =
    {B00000000, B00000011, B11000000, B00000000,
     B00000000, B00011111, B11111000, B00000000,
     B00000000, B01111111, B11111110, B00000000,
     B00000001, B11111000, B10001111, B10000000,
     B00000011, B11111000, B10001111, B11000000,
     B00000111, B11111000, B10001111, B11100000,
     B00001111, B11111000, B10001111, B11110000,
     B00011111, B11000000, B00000011, B11111000,
     B00011111, B11000000, B00000000, B11111000,
     B00111111, B11000011, B11110000, B11111100,
     B00111111, B11000011, B11111000, B11111100,
     B01111111, B11000011, B11111000, B11111110,
     B01111111, B11000011, B11111000, B11111110,
     B01111111, B11000011, B11111000, B11111110,
     B11111111, B11000011, B11110000, B11111111,
     B11111111, B11000000, B00000001, B11111111,
     B11111111, B11000000, B00000000, B11111111,
     B11111111, B11000000, B00000000, B11111111,
     B01111111, B11000011, B11111000, B01111110,
     B01111111, B11000011, B11111100, B01111110,
     B01111111, B11000011, B11111100, B01111110,
     B00111111, B11000011, B11111100, B01111100,
     B00111111, B11000011, B11111000, B01111100,
     B00011111, B11000000, B00000000, B11111000,
     B00011111, B11000000, B00000011, B11111000,
     B00001111, B11111000, B10001111, B11110000,
     B00000111, B11111000, B10001111, B11100000,
     B00000011, B11111000, B10001111, B11100000,
     B00000001, B11111111, B11111111, B10000000,
     B00000000, B01111111, B11111110, B00000000,
     B00000000, B00011111, B11111000, B00000000,
     B00000000, B00000011, B11000000, B00000000};

#define NUMFLAKES 3 // Number of snowflakes in the animation example

#define LOGO_HEIGHT 32
#define LOGO_WIDTH 32

static byte arrowUp[8] = {
    B00000,
    B00100,
    B01110,
    B11011,
    B10001,
    B00000,
    B00000
};

static byte arrowDown[8] = {
    B00000,
    B00000,
    B10001,
    B11011,
    B01110,
    B00100,
    B00000
};

static byte arrowLoading[8] = {
    B11011,
    B10001,
    B01110,
    B01010,
    B01010,
    B01110,
    B10001,
    B11011
};
