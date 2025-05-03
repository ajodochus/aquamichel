
#include <Wire.h>
#include <SSD1306Wire.h>
#include <component_display.h>
#define I2C_SDA 21
#define I2C_SCL 22

SSD1306Wire display(0x3c, I2C_SDA, I2C_SCL); // I2C address 0x3c for 128x64 OLED display

String display_first_line = "first line"; // Placeholder for the first line of text
String display_second_line = "second line"; // Placeholder for the second line of text  
String display_third_line = "third line"; // Placeholder for the third line of text

void display_setup(){ 
    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Connect to Server");
    display.display();
}

void display_show_message(){
  display.clear();
  display.drawString(0, 0, display_first_line);
  display.drawString(0, 20, display_second_line);
  display.drawString(0, 40, display_third_line);
  display.display();
}
