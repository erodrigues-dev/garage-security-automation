#include <Arduino.h>
#include <RCSwitch.h>

#define led 2
#define rx 16

RCSwitch rc = RCSwitch();

bool armed = false;

void setup(){
    Serial.begin(115200);

    pinMode(led, OUTPUT);
    rc.enableReceive(rx);

    Serial.println("ESP32 initialized");
}

void loop(){
    
    handleRC();
}

void handleRC(){

    if(!rc.available()) return;

    ulong code = rc.getReceivedValue();

    Serial.print("button pressed: ");
    Serial.print(code);
    Serial.println("");

    if(verifyCode(code)) {

        digitalWrite(led, !armed);
        armed = !armed;

        if(armed) Serial.println("System security ARMED");
        else Serial.println("System security DISARMED");
    }

    rc.resetAvailable();
}

bool verifyCode(ulong code) {
    ulong btn1 = 143618853;

    return code == btn1;
}