# Running-Man-Game-using-Touch-Sensor-And-Arduino
Components Required
Arduino Uno or Nano
16x2 LCD Display (with I2C module for easier wiring)
Touch Sensor (e.g., TTP223)
Jumper Wires
Breadboard (optional)
Wiring Connections
LCD Display (I2C)

VCC -> 5V
GND -> GND
SDA -> A4 (on Arduino Uno)
SCL -> A5 (on Arduino Uno)
Touch Sensor

VCC -> 5V
GND -> GND
OUT -> Pin 2 (or any digital pin)
Explanation of the Code
Libraries: The code uses the Wire and LiquidCrystal_I2C libraries to control the LCD.

Game Variables:
playerPosition: Tracks the position of the player on the LCD.
obstaclePosition: Tracks the position of the obstacle.
gameOver: A flag to indicate if the game is over.

Setup Function:
Initializes the LCD and sets the touch sensor pin as input.
Displays the initial game message.

Loop Function:
Moves the obstacle left across the screen.
Checks for touch input to move the player.
Calls drawGame() to update the LCD display.
Checks for collisions between the player and the obstacle. If a collision occurs, the game is marked as over, and a "Game Over" message is displayed.

Draw Game Function:
Clears the LCD and draws the player and obstacle based on their positions.

Reset Game Function:
Resets the game variables and displays the initial message again.
