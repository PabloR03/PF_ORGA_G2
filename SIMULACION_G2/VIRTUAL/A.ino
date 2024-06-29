int contador = 0;

void setup() {
  Serial.begin(9600);
  // Configuración de los pines de salida
  for (int pin = 7; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
  for (int pin = 4; pin <= 6; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  // Configuración de los pines de entrada
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  pinMode(22, INPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'R') {
      // Leer los pines 14, 15, 16, 17, 20, 21, 22 y enviar los datos binarios
      String data = "";
      data += digitalRead(14);
      data += digitalRead(15);
      data += digitalRead(16);
      data += digitalRead(17);
      data += digitalRead(20);
      data += digitalRead(21);
      data += digitalRead(22);
      Serial.println(data);
    } else {
      digitalWrite(2, HIGH);
      setMemoryPosition(contador);
      contador = (contador + 1) % 8;
      delay(1000);

      String numero = Serial.readStringUntil('\n');
      int valor = numero.toInt();
      delay(1000);

      Serial.print("Valor recibido: ");
      Serial.println(valor);
      
      setBinaryOutput(valor);
      delay(1000);

      writePulse();
      delay(1000);

      resetPins();
      delay(1000);

      digitalWrite(2, LOW);
    }
  }
}

void setMemoryPosition(int pos) {
  for (int i = 0; i < 3; i++) {
    int pin = 6 - i;
    digitalWrite(pin, (pos & (1 << i)) ? HIGH : LOW);
  }
}

void setBinaryOutput(int valor) {
  for (int i = 0; i < 7; i++) {
    int pin = 13 - i;
    int bitValue = (valor & (1 << i)) ? HIGH : LOW;
    digitalWrite(pin, bitValue);

    // Debug: imprimir el estado de cada pin
    Serial.print("Pin ");
    Serial.print(pin);
    Serial.print(": ");
    Serial.println(bitValue == HIGH ? "HIGH" : "LOW");
  }
}

void writePulse() {
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
}

void resetPins() {
  for (int pin = 7; pin <= 13; pin++) {
    digitalWrite(pin, LOW);
  }
  for (int pin = 4; pin <= 6; pin++) {
    digitalWrite(pin, LOW);
  }
}
