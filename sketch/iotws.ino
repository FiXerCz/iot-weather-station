// include libraries here


// button on board - use for whatever 
#define BUTTON_PIN      33

// analog value from gas sensor
#define GAS_SENSOR_PIN  35

// pins for LCD
#define LCD_RS          27
#define LCD_EN          25
#define LCD_D4          32
#define LCD_D5          17
#define LCD_D6          16
#define LCD_D7          15

bool ledState;

void setup() {
  // init serial output (ability to write below to Serial Monitor)
  Serial.begin(115200);

  // init button with pull-resistor (you don't need this, unless you want to use the button for some action)
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // There is a BUILTIN LED on the board - set it as output pin 
  // We can "read" from output pins, we can "write" to input pins
  // pinMode can change pin's state between input/output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.printf("Switching the LED %s\n", ledState ? "on" : "off");
  digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW); // HIGH and LOW are predefined constants for 1 and 0
  ledState = !ledState;
  
  // wait for 5 seconds before running loop() again 
  Serial.println("Waiting for 5 seconds...");
  delay(5000);
}
