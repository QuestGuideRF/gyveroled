#include <GyverOLED.h>
GyverOLED<SSH1106_128x64> oled;
void setup() {
  oled.init();
  oled.clear();
}
void loop() {
  for (byte i = 0; i < 100; i += 5) {
    oled.clear();
    oled.setCursorXY(0, 0);
    drawBattery(i);
    oled.update();
    delay(50);
  }
  for (int i = 100; i > 0; i -= 5) {
    oled.clear();
    oled.setCursorXY(0, 0);
    drawBattery(i);
    oled.update();
    delay(50);
  }
}
void drawBattery(byte percent) {
  oled.drawByte(0b00111100);
  oled.drawByte(0b00111100);
  oled.drawByte(0b11111111);
  for (byte i = 0; i < 100 / 8; i++) {
    if (i < (100 - percent) / 8) oled.drawByte(0b10000001);
    else oled.drawByte(0b11111111);
  }
  oled.drawByte(0b11111111);
}