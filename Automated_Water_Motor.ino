// Pin definitions
const int ultrasonicTrigPin = 2; // Ultrasonic sensor trigger pin
const int ultrasonicEchoPin = 3; // Ultrasonic sensor echo pin
const int ledPin = 13;           // LED control pin (digital pin 13)
const int relayControlPin = 12;  // Relay control pin (digital pin 12)

// Variables
long duration;
int distance;

void setup() {
  pinMode(ultrasonicTrigPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayControlPin, OUTPUT);

  digitalWrite(ledPin, LOW);      // Initialize LED as OFF
  digitalWrite(relayControlPin, LOW); // Initialize relay as OFF

  Serial.begin(9600);
}

void loop() {
  // Generate a pulse to trigger the ultrasonic sensor
  digitalWrite(ultrasonicTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicTrigPin, LOW);

  // Measure the time taken for the echo to return
  duration = pulseIn(ultrasonicEchoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if an object is close (adjust the threshold as needed)
  if (distance < 7) {
    // Turn off the LED and the relay
    digitalWrite(ledPin, LOW);
    digitalWrite(relayControlPin, LOW);
  } else {
    // Turn on the LED and the relay
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH);
    
  }

  delay(500); // Add a delay to avoid rapid toggling of the LED and relay states
}
