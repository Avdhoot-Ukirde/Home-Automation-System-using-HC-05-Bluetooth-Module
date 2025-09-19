char command; // Variable to store incoming Bluetooth command
int relayPin = 8; // Relay module control pin

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(relayPin, OUTPUT); // Set relay pin as output
  digitalWrite(relayPin, LOW); // Keep relay OFF initially
  Serial.println("Bluetooth Relay Control Ready");
}

void loop() {
  // Check if data is available from HC-05
  if (Serial.available()) {
    command = Serial.read();

    // Turn ON bulb
    if (command == '1') {
      digitalWrite(relayPin, HIGH); // Relay ON
      Serial.println("BULB ON");
    }

    // Turn OFF bulb
    else if (command == '0') {
      digitalWrite(relayPin, LOW); // Relay OFF
      Serial.println("BULB OFF");
    }
  }
}
