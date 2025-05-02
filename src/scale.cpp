#include <scale.h>
#include <Arduino.h>
#include "HX711.h"
HX711 scale;
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;
int scale_current_weight;


void scale_setup(){   
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(1030);
    scale.tare();
}
void scale_get_weight(){
    scale_current_weight = scale.get_units(10);
    Serial.println(scale_current_weight);
     if(scale_current_weight < 1){
        scale_current_weight = 0;
    }

};

void scale_tare(){
    scale.tare();
}