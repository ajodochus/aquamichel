#include <neotimer.h>
#include <Arduino.h>


// Function prototype
unsigned long startTime;
int countdownTime = 10000; 
Neotimer timer = Neotimer(countdownTime);

void countdown_start(){
    timer.set(countdownTime);
    timer.start();
    startTime = millis();
}

void check_countdown(){
    if (timer.waiting()) {
        Serial.print("Timer: ");
        Serial.println(timer.stop() / 1000);
        timer.restart();
    }
    if (timer.done()) {
        Serial.println("Timer done!");
        countdown_start();
    } 
}



