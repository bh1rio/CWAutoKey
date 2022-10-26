#include "Mouse.h"

const int mouseLeftButton = 12;
const int mouseRightButton =11;

int responseDelay = 10;     // response delay of the mouse, in ms

void setup() {
  pinMode(mouseLeftButton, INPUT_PULLUP);
  pinMode(mouseRightButton, INPUT_PULLUP);

  Mouse.begin();
}

void loop() {
  // read the buttons:
  int clickLeftState = digitalRead(mouseLeftButton);
  int clickRightState = digitalRead(mouseRightButton);

  // if the mouse button is pressed:
  if (clickLeftState == LOW) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  if (clickRightState == LOW) {
    if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT);
    }
  }
  else {
    if (Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.release(MOUSE_RIGHT);
    }
  }

  // a delay so the mouse doesn't move too fast:
  delay(responseDelay);
}
