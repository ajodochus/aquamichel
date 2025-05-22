#include <neotimer.h>
#include <Arduino.h>
#include "component_display.h"
#include "server.h"
#include "component_push_button.h"
#include "watersensor.h"
#include "scale.h"


// Function prototype
void timer_10s_start();
void timer_10s_loop();
unsigned long startTime; // Consider if this is shared or if each timer needs its own.
int countdownTime = 10000;
int service_timer_10s_current = 0;
Neotimer timer_10_seconds = Neotimer(countdownTime);

// New 1-second timer variables
void timer_1s_start();
void timer_1s_loop();
int countdownTime_1s = 1000; // 1 second
int service_timer_1s_current = 0;
Neotimer timer_1_second = Neotimer(countdownTime_1s);
unsigned long startTime_1s; // Separate start time for 1s timer


void service_loop() {
    component_push_button_loop();
    timer_10s_loop();
    timer_1s_loop(); // Call the 1s timer loop
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

// New 1-second timer functions
void timer_1s_start(){
    timer_1_second.set(countdownTime_1s);
    timer_1_second.start();
    startTime_1s = millis(); // Use separate start time
}

void timer_1s_loop(){
    if (timer_1_second.waiting()) {
        service_timer_1s_current = timer_1_second.stop() / 1000; // This will always be 0 or 1
        timer_1_second.restart();
        // You might want to do something each second here
        // For example, Serial.println("1s tick");
    }
    if (timer_1_second.done()) {
        timer_1s_start(); // Restart the timer when done
        // This block will execute every 1 second
        // Serial.println("1s timer done, restarting.");
        display_first_line = String(server_msg);
        
        switch (cycle_display_state) {
            case 0: // Timer Display
                display_second_line = "Timer: " + String(service_timer_10s_current);
                break;
            case 1: // Watersensor Display
                display_second_line = "Water: " + String(watersensor_get_percentage()) + "%";
                break;
            case 2: // Scale Display
                display_second_line = "Weight: " + String(scale_current_weight) + "g";
                break;
        }
        display_refresh();
    }
}



