#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // 16×2 I²C LCD, change 0x27 if needed

// ── Pin map ────────────────────────────────
const int SOUND_PIN  = 2;   // LM393 D0
const int WHITE_LED  = 3;   // White LED (+ 220 Ω → GND)
const int BUZZER_PIN = 6;   // Passive buzzer (+)

// ── Timing constants ───────────────────────
const unsigned long CLAP_WINDOW   = 800;   // ms allowed between claps
const unsigned long DEBOUNCE_TIME = 50;    // ignore bounce (ms)

unsigned long lastClapTime = 0;
int  clapCount      = 0;
bool prevSoundState = LOW;

// ────────────────────────────────────────────
void setup()
{
  pinMode(SOUND_PIN, INPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);          // ← Serial uses begin()
  lcd.init();                  // ← LCD uses init()
  lcd.backlight();

  lcd.setCursor(0, 0); lcd.print("Sound system");
  lcd.setCursor(0, 1); lcd.print("ready...");
  Serial.println(F("Sound‑based LED system ready."));

  // Take a baseline so no phantom clap
  prevSoundState = digitalRead(SOUND_PIN);
}

// ────────────────────────────────────────────
void loop()
{
  bool soundNow = digitalRead(SOUND_PIN);

  // rising edge ⇒ one clap
  if (soundNow == HIGH && prevSoundState == LOW) {
    unsigned long now = millis();
    if (now - lastClapTime > DEBOUNCE_TIME) {
      clapCount++;
      lastClapTime = now;
      Serial.print(F("Clap detected → count = "));
      Serial.println(clapCount);
    }
  }
  prevSoundState = soundNow;

  // after the timeout, act on the pattern
  if (clapCount > 0 && millis() - lastClapTime > CLAP_WINDOW) {
    if (clapCount == 1) {
      setWhiteLED(true);   // ON
    } else if (clapCount == 2) {
      setWhiteLED(false);  // OFF
    } else {
      Serial.println(F("Ignored: need 1 or 2 claps"));
    }
    clapCount = 0;
  }
}

// ────────────────────────────────────────────
void setWhiteLED(bool turnOn)
{
  beepTwice();
  digitalWrite(WHITE_LED, turnOn ? HIGH : LOW);

  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("White LED");
  lcd.setCursor(0, 1); lcd.print(turnOn ? "is ON " : "is OFF");

  Serial.println(turnOn ? F("★ White LED ON") : F("★ White LED OFF"));
}

// ────────────────────────────────────────────
void beepTwice()
{
  for (byte i = 0; i < 2; i++) {
    tone(BUZZER_PIN, 1000, 200);   // 1 kHz, 200 ms
    delay(300);                    // gap between beeps
  }
}
