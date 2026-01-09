#define RED_PIN   7
#define GREEN_PIN 6
#define BLUE_PIN  5

#define LDR_PIN 2

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  ledcAttachPin(RED_PIN, 0);
  ledcAttachPin(GREEN_PIN, 1);
  ledcAttachPin(BLUE_PIN, 2);

  ledcSetup(0, 5000, 8); 
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
}

void loop() {
  int light = analogRead(LDR_PIN);

  int brightness = map(light, 0, 4095, 255, 0);
  brightness = constrain(brightness, 0, 255);


  setColor(brightness, 0, 0);   // red glow
  delay(20);
}

void setColor(int r, int g, int b) {
  ledcWrite(0, 255 - r);
  ledcWrite(1, 255 - g);
  ledcWrite(2, 255 - b);
}
