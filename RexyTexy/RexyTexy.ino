#include <GyverMAX7219.h> // Only for MAX7219

int RLx = 0;
int RLy = 0;
char receivedChar;

// CHANGEABLE PART!
int protocol = 0; // Protocol
// 0 - MAX7219

#define RLwidth 32 // Width
#define RLheight 16 // Height

#if protocol == 0
  #define CLK 8
  #define CS 7
  #define DIN 6
#endif
// DO NOT MODIFY BELOW THIS LINE!

#if protocol == 0
  MAX7219<RLwidth / 8, RLheight / 8, CS, DIN, CLK> mx;
#endif

void draw(float dx, float dy, int state) {
  RLx = round(dx * RLwidth) - 1;
  RLy = round(dy * RLheight) - 1;
  #if protocol == 0
    mx.dot(RLx, RLy, state);
    mx.update();
  #endif
}

void setup() {
  Serial.begin(9600);
  #if protocol == 0
    mx.begin();
    mx.setBright(5);
  #endif

  draw(0.5, 0.5, 1);
}

void loop() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    processCommand(receivedChar); // Call the function to process the received command
  }
}

void processCommand(char command) {
  // Process the received command here
  // You can add your own logic to handle different commands

  // Example: If the command starts with "XY", set the point at the specified coordinates
  if (command == 'X') {
    if (Serial.available() > 0) {
      int x = Serial.parseFloat();
      int y = Serial.parseFloat();
      int state = Serial.parseInt();
      // Set the point at the specified coordinates using your desired method
      // For example, you can use a library or directly control the display
      draw(x, y, state);
    }
  }
}
