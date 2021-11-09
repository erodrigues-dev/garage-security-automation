#include "settings.h"

Settings::Settings(SdcardUtil &sdcard)
{
  _sdcard = sdcard;
}

void Settings::initialize(){
  _sdcard.print_info();
}

void Settings::get_authorized_codes()
{
  Serial.println("Lendo codigos no SD_CARD");
}