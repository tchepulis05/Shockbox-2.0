int Sensor = 8; //Initializes the sensor on pin 8
int Relay = 7; //Initializes the relay on pin 7
int OpLEDG = 6; //Initializes the green operator LED on pin 6
int OpLEDR = 5; //Initializes the red operator LED on pin 5
int Status; //Initializes a variable to store the status of the sensor

void setup() {
  pinMode(Sensor, INPUT); //Sets the sensor as an input
  pinMode(Relay, OUTPUT); //Sets the relay as an output
  pinMode(OpLEDG, OUTPUT); //Sets the green operator LED as an output
  pinMode(OpLEDR, OUTPUT); //Sets the red operator LED as an output
  digitalWrite(OpLEDG, HIGH); //Turns on the green operator LED
}

void loop() {
  Status = digitalRead(Sensor); //Sets the current status of the sensor as the variable Status
  if (Status == 1) { //If the sensor is activated
    Shock(); //Run the Shock sequence
  }
  else { //If the sensor is not activated
    digitalWrite(Relay, LOW); //Opens the relay
  }
  delay(50); //Waits 50ms
}

void Shock() {
  digitalWrite(Relay, HIGH); //Closes the relay
  digitalWrite(OpLEDG, LOW); //Turns off the green operator LED
  digitalWrite(OpLEDR, HIGH); //Turns on the red operator LED
  delay(3000); //Waits 3s
  digitalWrite(Relay, LOW); //Opens the relay
  digitalWrite(OpLEDG, HIGH); //Turns the green operator LED on
  digitalWrite(OpLEDR, LOW); //Turns the red operator LED off
}
