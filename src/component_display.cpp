
#include <Wire.h>
#include <SSD1306Wire.h>
#include <component_display.h>
#define I2C_SDA 21
#define I2C_SCL 22

SSD1306Wire display(0x3c, I2C_SDA, I2C_SCL); // I2C address 0x3c for 128x64 OLED display

void display_setup(){ 
    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Connect to Server");
    display.display();
}

void display_show_message(String second_line){
  display.clear();
  display.drawString(0, 0, "first line");
  display.drawString(0, 20, second_line);
    display.drawString(0, 46, "third line");
  display.display();
}
