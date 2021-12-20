#include <Wire.h>
#include "RTClib.h"

int led = 7;

RTC_DS3231 rtc;

char dias[7][12] = {"Domingo","Segunda", "Terca", "Quarta", 
"Quinta", "Sexta", "Sabado"};
void setup() {
    Serial.begin(9600);
    if(!rtc.begin()){
        Serial.println("RTC NAO INICIALIZADO");
        while(1);
    }
    //rtc.adjust(DateTime(2021, 12, 18, 9, 50, 00));
    delay(100);
    pinMode(led, OUTPUT);
}

void loop() {
    DateTime agora = rtc.now();
    Serial.print("Data: ");
    Serial.print(agora.day(), DEC);
    Serial.print("/");
    Serial.print(agora.month(), DEC);
    Serial.print("/");
    Serial.print(agora.year(), DEC);
    Serial.print(" / Dia da semana: ");
    Serial.print(dias[agora.dayOfTheWeek()]);
    Serial.print(" / Horas: ");
    Serial.print(agora.hour(), DEC);
    Serial.print(':');
    Serial.print(agora.minute(),DEC);
    Serial.print(':');
    Serial.print(agora.second(), DEC);
    Serial.println();
    delay(1000);
    if ( agora.minute() == 44){
      digitalWrite(led, HIGH);
      }
      else {
        digitalWrite(led, LOW);
        }
}
