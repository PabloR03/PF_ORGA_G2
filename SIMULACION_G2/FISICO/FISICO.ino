#include <Stepper.h>
//VUELTA
int vuelta = 2048;
//LECTURA BRAILLE
const int puntosBraille[6] = {1, 4, 2, 5, 3, 6};
const int numPuntos = 6;
int lecturaPuntos[numPuntos];
//PINES MOTORES
Stepper motorX(2048, 13, 11, 12, 10);
Stepper motorY(2048, 9, 7, 8, 6);
//SENSOR CENTRAL
const int S0_C = 49;
const int S1_C = 50;
const int S2_C = 51;
const int S3_C = 52;
const int OUT_C = 53;

int rojo_central;
int verde_central;
int azul_central;


void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < numPuntos; ++i) {
    lecturaPuntos[i] = 0;
  }

  motorX.setSpeed(10);
  motorY.setSpeed(10);
  
  pinMode(5, INPUT);

  //PIN SENSOR CENTRAL
  pinMode(S0_C, OUTPUT);
  pinMode(S1_C, OUTPUT);
  pinMode(S2_C, OUTPUT);
  pinMode(S3_C, OUTPUT);
  pinMode(OUT_C, INPUT);
  digitalWrite(S0_C, HIGH);
  digitalWrite(S1_C, HIGH);
}

void loop() {
  
  int estado = digitalRead(5);
  
  if (estado == HIGH) {
    Serial.println("INICIA ESCANEO");

    //LECTURA PRIMER PUNTO
    delay(2000);
    rojo_central = get_rojo_central();
    delay(100);
    verde_central = get_verde_central();
    delay(100);
    azul_central = get_azul_central();
    delay(100);
    Serial.print("Lectura 1 - Rojo: ");
    Serial.print(rojo_central);
    Serial.print(", Verde: ");
    Serial.print(verde_central);
    Serial.print(", Azul: ");
    Serial.println(azul_central);

    if (rojo_central < 10 && verde_central < 10 && azul_central < 10) {
      lecturaPuntos[0] = 0;
    } else if (rojo_central > 15 && verde_central > 20 && azul_central > 20) {
      lecturaPuntos[0] = 1;
    }
    Serial.println(lecturaPuntos[0]);
    delay(2000);
    //+Y
    for (int i = 0; i < 1500; i++) {
      motorX.step(-1);
      motorY.step(1);
    }
    delay(2000);

    //LECTURA SEGUNDO PUNTO
    rojo_central = get_rojo_central();
    delay(100);
    verde_central = get_verde_central();
    delay(100);
    azul_central = get_azul_central();
    delay(100);

    Serial.print("Lectura 2 - Rojo: ");
    Serial.print(rojo_central);
    Serial.print(", Verde: ");
    Serial.print(verde_central);
    Serial.print(", Azul: ");
    Serial.println(azul_central);
    if (rojo_central < 10 && verde_central < 10 && azul_central < 10) {
      lecturaPuntos[1] = 0;
    } else if (rojo_central > 15 && verde_central > 20 && azul_central > 20) {
      lecturaPuntos[1] = 1;
    }
    Serial.println(lecturaPuntos[1]);
    delay(2000);

    //-Y
    for (int i = 0; i < 1500; i++) {
      motorX.step(1);
      motorY.step(-1);
    }
    delay(2000);
    //-X
    for (int i = 0; i < 1400; i++) {
      motorX.step(-1);
      motorY.step(-1);
    }
    delay(2000);

    //LECTURA TERCER PUNTO
    rojo_central = get_rojo_central();
    delay(100);
    verde_central = get_verde_central();
    delay(100);
    azul_central = get_azul_central();
    delay(100);

    Serial.print("Lectura 3 - Rojo: ");
    Serial.print(rojo_central);
    Serial.print(", Verde: ");
    Serial.print(verde_central);
    Serial.print(", Azul: ");
    Serial.println(azul_central);

    if (rojo_central < 10 && verde_central < 10 && azul_central < 10) {
      lecturaPuntos[2] = 0;
    } else if (rojo_central > 15 && verde_central > 20 && azul_central > 20) {
      lecturaPuntos[2] = 1;
    }
    Serial.println(lecturaPuntos[2]);
    delay(2000);

    //+Y
    for (int i = 0; i < 1500; i++) {
      motorX.step(-1);
      motorY.step(1);
    }
    delay(2000);

    //LECTURA CUARTO PUNTO
    rojo_central = get_rojo_central();
    delay(100);
    verde_central = get_verde_central();
    delay(100);
    azul_central = get_azul_central();
    delay(100);

    Serial.print("Lectura 4 - Rojo: ");
    Serial.print(rojo_central);
    Serial.print(", Verde: ");
    Serial.print(verde_central);
    Serial.print(", Azul: ");
    Serial.println(azul_central);
    if (rojo_central < 10 && verde_central < 10 && azul_central < 10) {
      lecturaPuntos[3] = 0;
    } else if (rojo_central > 15 && verde_central > 20 && azul_central > 20) {
      lecturaPuntos[3] = 1;
    }
    Serial.println(lecturaPuntos[3]);
    delay(2000);

    //-Y
    for (int i = 0; i < 1500; i++) {
      motorX.step(1);
      motorY.step(-1);
    }
    delay(2000);
    //-X
    for (int i = 0; i < 1400; i++) {
      motorX.step(-1);
      motorY.step(-1);
    }
    delay(2000);

    //LECTURA QUINTO PUNTO
    rojo_central = get_rojo_central();
    delay(100);
    verde_central = get_verde_central();
    delay(100);
    azul_central = get_azul_central();
    delay(100);

    Serial.print("Lectura 5 - Rojo: ");
    Serial.print(rojo_central);
    Serial.print(", Verde: ");
    Serial.print(verde_central);
    Serial.print(", Azul: ");
    Serial.println(azul_central);
    if (rojo_central < 10 && verde_central < 10 && azul_central < 10) {
      lecturaPuntos[4] = 0;
    } else if (rojo_central > 15 && verde_central > 20 && azul_central > 20) {
      lecturaPuntos[4] = 1;
    }
    Serial.println(lecturaPuntos[4]);
    delay(2000);

    //+Y
    for (int i = 0; i < 1500; i++) {
      motorX.step(-1);
      motorY.step(1);
    }
    delay(2000);

    //LECTURA SEXTO PUNTO
    rojo_central = get_rojo_central();
    delay(100);
    verde_central = get_verde_central();
    delay(100);
    azul_central = get_azul_central();
    delay(100);
    Serial.print("Lectura 6 - Rojo: ");
    Serial.print(rojo_central);
    Serial.print(", Verde: ");
    Serial.print(verde_central);
    Serial.print(", Azul: ");
    Serial.println(azul_central);
    if (rojo_central < 10 && verde_central < 10 && azul_central < 10) {
      lecturaPuntos[5] = 0;
    } else if (rojo_central > 15 && verde_central > 20 && azul_central > 20) {
      lecturaPuntos[5] = 1;
    }
    Serial.println(lecturaPuntos[5]);
    delay(2000);

    //-Y
    for (int i = 0; i < 1500; i++) {
      motorX.step(1);
      motorY.step(-1);
    }
    delay(2000);
    //+X
    for (int i = 0; i < 2800; i++) {
      motorX.step(1);
      motorY.step(1);
    }
    delay(2000);

    
    int letra = determinarLetra(lecturaPuntos);
    Serial.println("---------");
    Serial.println(letra);
    Serial.println("&&&&&&&&&&&");
  }
}

//SENSOR CENTRAL
int get_rojo_central() {
  digitalWrite(S2_C, LOW);
  digitalWrite(S3_C, LOW);
  return pulseIn(OUT_C, digitalRead(OUT_C) == HIGH ? LOW : HIGH);
}

int get_verde_central() {
  digitalWrite(S2_C, HIGH);
  digitalWrite(S3_C, HIGH);
  return pulseIn(OUT_C, digitalRead(OUT_C) == HIGH ? LOW : HIGH);
}

int get_azul_central() {
  digitalWrite(S2_C, LOW);
  digitalWrite(S3_C, HIGH);
  return pulseIn(OUT_C, digitalRead(OUT_C) == HIGH ? LOW : HIGH);
}


//DEFINICION BRAILLE
int determinarLetra(int puntos[]) {
  if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 0 && puntos[3] == 0 && puntos[4] == 0 && puntos[5] == 0) {
    return 97; // 'a' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 0 && puntos[3] == 1 && puntos[4] == 0 && puntos[5] == 0) {
    return 98; // 'b' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 0 && puntos[3] == 0 && puntos[4] == 0 && puntos[5] == 0) {
    return 99; // 'c' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 0 && puntos[3] == 1 && puntos[4] == 0 && puntos[5] == 0) {
    return 100; // 'd' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 0 && puntos[3] == 0 && puntos[4] == 1 && puntos[5] == 0) {
    return 101; // 'e' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 0 && puntos[3] == 0 && puntos[4] == 1 && puntos[5] == 0) {
    return 102; // 'f' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 0 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 0) {
    return 103; // 'g' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 0 && puntos[3] == 0 && puntos[4] == 1 && puntos[5] == 1) {
    return 104; // 'h' en ASCII
  } else if (puntos[0] == 0 && puntos[1] == 1 && puntos[2] == 0 && puntos[3] == 1 && puntos[4] == 0 && puntos[5] == 0) {
    return 105; // 'i' en ASCII
  } else if (puntos[0] == 0 && puntos[1] == 1 && puntos[2] == 0 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 0) {
    return 106; // 'j' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 0 && puntos[4] == 0 && puntos[5] == 0) {
    return 107; // 'k' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 1 && puntos[3] == 0 && puntos[4] == 0 && puntos[5] == 0) {
    return 108; // 'l' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 0 && puntos[5] == 0) {
    return 109; // 'm' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 0) {
    return 110; // 'n' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 0 && puntos[4] == 1 && puntos[5] == 1) {
    return 111; // 'o' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 0 && puntos[5] == 0) {
    return 112; // 'p' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 0) {
    return 113; // 'q' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 1) {
    return 114; // 'r' en ASCII
  } else if (puntos[0] == 0 && puntos[1] == 1 && puntos[2] == 1 && puntos[3] == 0 && puntos[4] == 0 && puntos[5] == 0) {
    return 115; // 's' en ASCII
  } else if (puntos[0] == 0 && puntos[1] == 1 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 0 && puntos[5] == 0) {
    return 116; // 't' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 0 && puntos[4] == 0 && puntos[5] == 1) {
    return 117; // 'u' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 1 && puntos[3] == 0 && puntos[4] == 1 && puntos[5] == 0) {
    return 118; // 'v' en ASCII
  } else if (puntos[0] == 0 && puntos[1] == 1 && puntos[2] == 0 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 0) {
    return 119; // 'w' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 0 && puntos[5] == 1) {
    return 120; // 'x' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 1) {
    return 121; // 'y' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 0 && puntos[2] == 0 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 1) {
    return 122; // 'z' en ASCII
  } else if (puntos[0] == 1 && puntos[1] == 1 && puntos[2] == 1 && puntos[3] == 1 && puntos[4] == 1 && puntos[5] == 1) {
    return 1;
  } else if (puntos[0] == 0 && puntos[1] == 0 && puntos[2] == 0 && puntos[3] == 0 && puntos[4] == 0 && puntos[5] == 0) {
    return 0;
  }
}
