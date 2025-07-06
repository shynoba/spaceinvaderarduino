#include <LedControl.h>
#include <LiquidCrystal.h>

// MAX7219
LedControl lc(11, 13, 10, 1); // DIN, CLK, CS, 1 afficheur

// LCD1602 (sans I2C)
LiquidCrystal lcd(8, 7, 6, 5, 4, 3); // RS, E, D4, D5, D6, D7

// Joystick
const int joyX = A3;

// Vaisseau
int playerX = 3;
const int playerY = 7;

// Tir
int bulletX = -1;
int bulletY = -1;
bool bulletActive = false;

// Aliens
const int maxAliens = 3;
int alienX[maxAliens];
int alienY[maxAliens];

// Timer
unsigned long lastAlienMove = 0;
int alienSpeed = 1000;

// Score
int score = 0;

// État du jeu
bool gameStarted = false;

void setup() {
  // LCD
  lcd.begin(16, 2);
  lcd.print("Space Invader");
  lcd.setCursor(0, 1);
  lcd.print("Move to play!");

  // MAX7219
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  showS(); // Affiche "S" en attente

  // Initialisation aléatoire
  randomSeed(analogRead(A0));
}

void loop() {
  if (!gameStarted) {
    int xVal = analogRead(joyX);
    if (xVal < 400 || xVal > 600) {
      gameStarted = true;
      lcd.clear();
      lcd.print("Score: 0");
      spawnAliens();
      delay(300); // évite double déclenchement
    }
    return;
  }

  readJoystick();
  moveBullet();
  moveAliens();
  drawGame();
  checkGameOver();
  updateScore();
  delay(100);
}

void readJoystick() {
  int xVal = analogRead(joyX);
  if (xVal < 400 && playerX > 0) {
    playerX--;
  } else if (xVal > 600 && playerX < 7) {
    playerX++;
  }

  if (!bulletActive) {
    bulletX = playerX;
    bulletY = playerY - 1;
    bulletActive = true;
  }
}

void moveBullet() {
  if (bulletActive) {
    bulletY--;
    if (bulletY < 0) {
      bulletActive = false;
    } else {
      for (int i = 0; i < maxAliens; i++) {
        if (alienX[i] == bulletX && alienY[i] == bulletY) {
          alienX[i] = random(0, 8);
          alienY[i] = 0;
          bulletActive = false;
          score++;
        }
      }
    }
  }
}

void spawnAliens() {
  for (int i = 0; i < maxAliens; i++) {
    alienX[i] = random(0, 8);
    alienY[i] = i;
  }
}

void moveAliens() {
  if (millis() - lastAlienMove > alienSpeed) {
    lastAlienMove = millis();
    for (int i = 0; i < maxAliens; i++) {
      alienY[i]++;
      if (alienY[i] > 7) {
        alienX[i] = random(0, 8);
        alienY[i] = 0;
      }
    }
  }
}

void drawGame() {
  lc.clearDisplay(0);
  lc.setLed(0, playerY, playerX, true);
  if (bulletActive) {
    lc.setLed(0, bulletY, bulletX, true);
  }
  for (int i = 0; i < maxAliens; i++) {
    lc.setLed(0, alienY[i], alienX[i], true);
  }
}

void checkGameOver() {
  for (int i = 0; i < maxAliens; i++) {
    if (alienY[i] == playerY && alienX[i] == playerX) {
      gameOver();
    }
  }
}

void gameOver() {
  lc.clearDisplay(0);
  for (int i = 0; i < 3; i++) {
    lc.setRow(0, i, B11111111);
    delay(150);
  }
  delay(1000);
  playerX = 3;
  bulletActive = false;
  score = 0;
  lcd.clear();
  lcd.print("Space Invader");
  lcd.setCursor(0, 1);
  lcd.print("Move to play!");
  gameStarted = false;
  showS();
}

void updateScore() {
  lcd.setCursor(7, 0);
  lcd.print("Score:");
  lcd.setCursor(13, 0);
  lcd.print(score);
}

void showS() {
  byte S[8] = {
    B00111110,
    B01100000,
    B01100000,
    B00111100,
    B00000110,
    B00000110,
    B01111100,
    B00000000
  };
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, S[i]);
  }
}
