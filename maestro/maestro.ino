#include <Wire.h>

const int slaveAddress = 8;  // Dirección del esclavo
int distance = 0;           

void setup() {
  Wire.begin();  // Inicializa I2C como maestro
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(slaveAddress, 2);  // Solicita 2 bytes del esclavo

  if (Wire.available() == 2) {
    // Leer el valor recibido (16 bits)
    int highByte = Wire.read();
    int lowByte = Wire.read();
    distance = (highByte << 8) | lowByte;

    // Imprime
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}