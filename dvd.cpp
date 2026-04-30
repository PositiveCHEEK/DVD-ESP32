#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <vector>
#include <string>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

std::vector<int> cache = {10, 1};
int direction = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextWrap(false);
  display.clearDisplay();
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  if (cache[0] == SCREEN_WIDTH) { // Main check!!
    switch (direction) {
      case 0:
        direction = 3;
        break;
      case 1:
        direction = 2;
        break;
    }
  }
  if (cache[0] == 0) {
    switch (direction) {
      case 3:
        direction = 0;
        break;
      case 2:
        direction = 1;
        break;
    }
  }
  if (cache[1] == SCREEN_HEIGHT) {
    switch (direction) {
      case 3:
        direction = 2;
        break;
      case 0:
        direction = 1;
        break;
    }
  }
  if (cache[1] == 0) {
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
      cache[0] += 1;
      cache[1] += 1;
      break;
    case 1:
      cache[0] += 1;
      cache[1] -= 1;
      break;
    case 2:
      cache[0] -= 1;
      cache[1] -= 1;
      break;
    case 3:
      cache[0] -= 1;
      cache[1] += 1;
      break;
  } // Processing of ts not
  display.setCursor(cache[0], cache[1]);
  display.println("DVD"); // Change this to wtvr you like
  display.display();
  delay(40); // FPS
  display.clearDisplay();
}
