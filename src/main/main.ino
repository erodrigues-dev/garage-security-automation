#include <Arduino.h>
#include <RCSwitch.h>

#include "sdcard-util.h";
#include "settings.h";

#define RX 16
#define SIREN 27
#define SENSOR 35

SdcardUtil *sdcard_util;
Settings settings = Settings(*sdcard_util);

RCSwitch rc = RCSwitch();

bool armed = false;
bool fired = false;

void setup()
{
  Serial.begin(115200);

  pinMode(SIREN, OUTPUT);
  pinMode(SENSOR, INPUT_PULLDOWN);

  rc.enableReceive(RX);

  Serial.println("ESP32 initialized");
  Serial.println("Version 0.0.1");

  initialize_default_state();

  settings.initialize();
}

void loop()
{
  handle_presence_sensor();
  handle_remote_control();
  handle_fired();
}

void initialize_default_state()
{
  armed = false;
  fired = false;

  digitalWrite(SIREN, LOW);
}

void handle_remote_control()
{

  ulong code = readCode();

  if (code == 0)
    return;

  bool codeIsValid = verifyCode(code);

  if (codeIsValid)
    control_system();
}

ulong readCode()
{
  if (!rc.available())
    return 0;

  ulong code = rc.getReceivedValue();
  rc.resetAvailable();

  Serial.print("read code: ");
  Serial.print(code);
  Serial.println("");

  return code;
}

bool verifyCode(ulong code)
{
  ulong btn1 = 181455653;

  return code == btn1;
}

void control_system()
{
  armed = !armed;
  fired = false;

  if (armed)
  {
    Serial.println("System ARMED");
  }
  else
  {
    Serial.println("System DISARMED");
  }

  control_leds();
  control_siren();
}

void control_leds()
{
}

void control_siren()
{
  bool siren_active = digitalRead(SIREN);
  if (siren_active)
  {
    digitalWrite(SIREN, LOW);
    delay(300);
  }

  if (armed)
    siren_long_touch();
  else
    siren_two_touchs();
}

void siren_two_touchs()
{
  digitalWrite(SIREN, HIGH);
  delay(300);
  digitalWrite(SIREN, LOW);
  delay(300);
  digitalWrite(SIREN, HIGH);
  delay(300);
  digitalWrite(SIREN, LOW);
}

void siren_long_touch()
{
  digitalWrite(SIREN, HIGH);
  delay(600);
  digitalWrite(SIREN, LOW);
}

void siren_active(bool active)
{
  digitalWrite(SIREN, active);
}

void handle_presence_sensor()
{
  if (!armed)
    return;

  int value = digitalRead(SENSOR);

  bool active = value == 0;

  if (active && !fired)
  {
    fired = true;
    Serial.println("Sensor - FIRED");
  }
}

void handle_fired()
{
  siren_active(fired);
}
