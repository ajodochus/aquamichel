#include <neotimer.h>
#include <Arduino.h>



// Function prototype
unsigned long startTime;
int countdownTime = 10000; 
int timer_current_time = 0;
Neotimer timer = Neotimer(countdownTime);

void countdown_start(){
    timer.set(countdownTime);
    timer.start();
    startTime = millis();
}

void check_countdown(){
    if (timer.waiting()) {
        Serial.print("Timer: ");
        timer_current_time = timer.stop() / 1000;
        Serial.println(timer_current_time);
        timer.restart();
    }
    if (timer.done()) {
        Serial.println("Timer done!");
        countdown_start();
    } 
}



