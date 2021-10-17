
#include "FreeRTOS.h"
#include "header.h"

void CreateRoutineTasks()
{
    xTaskCreatePinnedToCore(CheckNetworkConnection, "CheckNetworkConnection", 4096, NULL, 4, NULL, 0);
    xTaskCreatePinnedToCore(UpdatePrices, "UpdatePrices", 6144, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(OledAnimateBTC, "Animate", 8192, NULL, 3, NULL, 1);
}