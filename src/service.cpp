#include <neotimer.h>
#include <Arduino.h>
#include "component_display.h"
#include "server.h"


// Function prototype
void countdown_start();
void timer_update_msg();
unsigned long startTime;
int countdownTime = 10000; 
int timer_current_time = 0;
Neotimer timer = Neotimer(countdownTime);


void service_loop() {
    display_first_line = server_msg;
    timer_update_msg();
    display_second_line = String(timer_current_time);
    display_show_message();
}


void countdown_start(){
    timer.set(countdownTime);
    timer.start();
    startTime = millis();
}
void timer_update_msg(){
    if (timer.waiting()) {
        //Serial.print("Timer: ");
        timer_current_time = timer.stop() / 1000;
        //Serial.println(timer_current_time);
        timer.restart();
    }
    if (timer.done()) {
        //Serial.println("Timer done!");
        countdown_start();
    } 
}



