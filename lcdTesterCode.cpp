#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long frameCount = 0;
unsigned long lastFPSUpdate = 0;
unsigned long lastPrintTime = 0;
float fps = 0;
float maxFPS = 0;

const int maxRAM = 1024;

byte fullBlock[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void centerText(const char* msg, int row) {
  int len = strlen(msg);
  int padding = (16 - len) / 2;
  lcd.setCursor(padding, row);
  lcd.print(msg);
}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, fullBlock);

  lcd.clear();
  centerText("Loading...", 0);
  delay(1000);

  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.write(byte(0));  
    delay(154);
  }

  delay(500);
  lcd.clear();
}

void loop() {

  if (frameCount <= 10000) {
    lcd.setCursor(0, 0);
    lcd.print("Count: ");
    lcd.print(frameCount);
    lcd.print("    "); 
    frameCount++;
  }

  if (millis() - lastFPSUpdate >= 1000) {
    fps = (float)frameCount / ((millis() - lastPrintTime) / 1000.0);
    if (fps > maxFPS) maxFPS = fps;

    int usedRAM = random(300, maxRAM);

    lcd.setCursor(0, 1);
    lcd.print("FPS:");
    lcd.print(fps, 1);
    lcd.print(" RAM:");
    lcd.print(usedRAM);
    lcd.print("/");
    lcd.print(maxRAM);

    lastFPSUpdate = millis();
    lastPrintTime = millis();
    frameCount = 0;
  }
}
