const int mouseLeftButton = 3;
const int mouseRightButton =4;

int responseDelay = 10;     // response delay of the mouse, in ms

void setup() {
  pinMode(mouseLeftButton, INPUT);
  pinMode(mouseRightButton, INPUT);

  digitalWrite(mouseLeftButton, HIGH);
  digitalWrite(mouseRightButton, HIGH);

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
