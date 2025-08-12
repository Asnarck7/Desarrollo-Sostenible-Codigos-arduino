// C++ code
//
int datoGas = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  datoGas = analogRead(A1);

  // Imprimir el valor leído
  Serial.print("Valor registrado: ");
  Serial.println(datoGas);

  // Verificar los rangos y mostrar mensajes
  if (datoGas == 487) {
    Serial.println("Nivel 0: Estamos bien");
  }
  else if (datoGas >= 525.3 && datoGas < 563.6) {
    Serial.println("Nivel 1: Estamos bien");
  }
  else if (datoGas >= 563.6 && datoGas < 601.9) {
    Serial.println("Mas o menos");
  }
  else if (datoGas >= 601.9 && datoGas < 640.2) {
    Serial.println("Estamos un poco mal");
  }
  else if (datoGas >= 640.2 && datoGas < 678.5) {
    Serial.println("Estamos mal");
  }
  else if (datoGas >= 678.5 && datoGas < 716.8) {
    Serial.println("Estamos muy mal");
  }
  else if (datoGas >= 716.8 && datoGas < 755.1) {
    Serial.println("ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 755.1 && datoGas < 793.4) {
    Serial.println("ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 793.4 && datoGas < 831.7) {
    Serial.println("ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 831.7 && datoGas < 870) {
    Serial.println("ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 870) {
    Serial.println("ESTAMOS EN PELIGRO EXTREMO");
  }

  // Pausa para evitar lecturas demasiado rápidas
  delay(500);
}

