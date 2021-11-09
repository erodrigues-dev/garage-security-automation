#ifndef settings_h
#define settings_h

#include <Arduino.h>
#include "sdcard-util.h"

class Settings
{
public:
    Settings(SdcardUtil &sdcard_util);
    void initialize();
    void get_authorized_codes();
private:
    SdcardUtil _sdcard;
};

#endif