#include <Wire.h>
#include <SSD1306Wire.h>
#include <component_display.h>
#define I2C_SDA 21
#define I2C_SCL 22

SSD1306Wire display(0x3c, I2C_SDA, I2C_SCL); // I2C address 0x3c for 128x64 OLED display
//I2C device found at address 0x20  !
//I2C device found at address 0x3C  !
String display_first_line = "first line"; // Placeholder for the first line of text
String display_second_line = "---"; // Placeholder for the second line of text  
String display_third_line = ":::"; // Placeholder for the third line of text

void display_setup(){ 
    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    display_first_line = "start WiFi ...";
    display_refresh();
    display.display();
}

void display_refresh(){
  display.clear();
  display.drawString(0, 0, display_first_line);
  display.drawString(0, 20, display_second_line);
  display.drawString(0, 40, display_third_line);
  display.display();
}

void display_set_first_line(String text) {
  display_first_line = text;
}

void display_set_second_line(String text) {
  display_second_line = text;
}

void display_set_third_line(String text) {
  display_third_line = text;
}
