#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <vector>
#include <string>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

std::vector<int> pos1 = {10, 1};
std::vector<int> pos2 = {21, 8};
int direction = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextWrap(false);
  display.clearDisplay();
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  if (pos1[0] + pos2[0] == SCREEN_WIDTH) { // Main check!!
    switch (direction) {
      case 0:
        direction = 3;
        break;
      case 1:
        direction = 2;
        break;
    }
  }
  if (pos1[0] == 0) {
    switch (direction) {
      case 3:
        direction = 0;
        break;
      case 2:
        direction = 1;
        break;
    }
  }
  if (pos1[1] + pos2[1] == SCREEN_HEIGHT) {
    switch (direction) {
      case 3:
        direction = 2;
        break;
      case 0:
        direction = 1;
        break;
    }
  }
  if (pos1[1] == 0) {
    switch (direction) {
      case 2:
        direction = 3;
        break;
      case 1:
        direction = 0;
        break;
    }
  } // End of the Main check!!

  switch (direction) { // Processing of DR-UR-UL-DL
    case 0:
      pos1[0] += 1;
      pos1[1] += 1;
      break;
    case 1:
      pos1[0] += 1;
      pos1[1] -= 1;
      break;
    case 2:
      pos1[0] -= 1;
      pos1[1] -= 1;
      break;
    case 3:
      pos1[0] -= 1;
      pos1[1] += 1;
      break;
  } // Processing of ts not
  display.setCursor(pos1[0], pos1[1]);
  display.println("DVD");
  display.display();
  delay(40);
  display.clearDisplay();
}
