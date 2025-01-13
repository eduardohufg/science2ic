#include <Wire.h>

const int sensorPin = 3;  // Pin del sensor 
long duration;            // Duración del pulso SIG
int distance;             // Distancia calculada en cm

void setup() {
  Wire.begin(8);  // Inicializa I2C como esclavo con dirección 8
  Wire.onRequest(requestEvent);  // Define qué hacer cuando el maestro solicita datos
  
  pinMode(sensorPin, OUTPUT); 
}

void loop() {

  pinMode(sensorPin, OUTPUT); 
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);


  pinMode(sensorPin, INPUT); 
  duration = pulseIn(sensorPin, HIGH);


  distance = duration * 0.034 / 2;

  delay(100); 
}

void requestEvent() {
  // Enviar la distancia medida al maestro
  Wire.write(distance >> 8);     // Envía el byte alto
  Wire.write(distance & 0xFF);  // Envía el byte bajo
}