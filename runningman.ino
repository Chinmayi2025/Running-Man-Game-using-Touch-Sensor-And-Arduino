#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TOUCH_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address if necessary

int playerPosition = 0; // Player's position on the LCD
int obstaclePosition = 15; // Initial position of the obstacle
bool gameOver = false;

void setup() {
    lcd.begin();
    lcd.backlight();
    pinMode(TOUCH_PIN, INPUT);
    lcd.clear();
    lcd.print("Running Man Game");
    delay(2000);
    lcd.clear();
}

void loop() {
    if (!gameOver) {
        // Move the obstacle
        obstaclePosition--;
        if (obstaclePosition < 0) {
            obstaclePosition = 15; // Reset obstacle position
        }

        // Check for touch input
        if (digitalRead(TOUCH_PIN) == HIGH) {
            playerPosition = 1; // Move player to the right
        } else {
            playerPosition = 0; // Player stays in the initial position
        }

        // Draw the game state
        drawGame();

        // Check for collision
        if (playerPosition == obstaclePosition) {
            gameOver = true;
            lcd.clear();
            lcd.print("Game Over!");
            delay(2000);
            resetGame();
        }

        delay(500); // Control the speed of the game
    }
}

void drawGame() {
    lcd.clear();
    // Draw the player
    for (int i = 0; i < 16; i++) {
        if (i == playerPosition) {
            lcd.print("P"); // Player character
        } else if (i == obstaclePosition) {
            lcd.print("X"); // Obstacle character
        } else {
            lcd.print(" "); // Empty space
        }
    }
}

void resetGame() {
    playerPosition = 0;
    obstaclePosition = 15;
    gameOver = false;
    lcd.clear();
    lcd.print("Running Man Game");
    delay(2000);
    lcd.clear();
}