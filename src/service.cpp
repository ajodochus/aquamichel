#include <neotimer.h>
#include <Arduino.h>
#include "component_display.h"
#include "server.h"
#include "component_push_button.h"
#include "watersensor.h"


// Function prototype
void timer_10s_start();
void timer_10s_loop();
unsigned long startTime;
int countdownTime = 10000; 
int service_timer_10s_current = 0;
Neotimer timer_10_seconds = Neotimer(countdownTime);


void service_loop() {
    component_push_button_loop();
    timer_10s_loop();
}


void timer_10s_start(){
    timer_10_seconds.set(countdownTime);
    timer_10_seconds.start();
    startTime = millis();
}
void timer_10s_loop(){
    if (timer_10_seconds.waiting()) {
        //Serial.print("Timer: ");
        service_timer_10s_current = timer_10_seconds.stop() / 1000;
        //Serial.println(timer_current_time);
        timer_10_seconds.restart();
    }
    if (timer_10_seconds.done()) {
        //Serial.println("Timer done!");
        timer_10s_start();

    } 
}



