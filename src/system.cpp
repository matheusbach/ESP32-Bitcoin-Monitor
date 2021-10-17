#include "Arduino.h"
#include "time.h"

const char ntpServer[] = "pool.ntp.org";
const long gmtOffset_sec = -10800;
const int daylightOffset_sec = 0;

void SyncSystemTime()
{
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}