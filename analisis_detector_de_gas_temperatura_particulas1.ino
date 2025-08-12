int datoGas = 0;
float temperatura = 0;
int offset = 102;
int ppm = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Leer la temperatura
  temperatura = analogRead(A0);
  temperatura = (temperatura - offset) / 2.05;
  Serial.print("La temperatura es: ");
  Serial.println(temperatura);

  // Leer y procesar el sensor de gas
  leerSensorGas();

  // Pausa para evitar lecturas demasiado rápidas
  delay(2000);
}

void leerSensorGas()
{
  // Leer el valor del sensor de gas
  datoGas = analogRead(A1);

  // Convertir el valor de lectura a ppm usando interpolación lineal
  if (datoGas <= 487) ppm = 0;
  else if (datoGas <= 525) ppm = map(datoGas, 487, 525, 0, 1000);
  else if (datoGas <= 563) ppm = map(datoGas, 525, 563, 1000, 2000);
  else if (datoGas <= 601) ppm = map(datoGas, 563, 601, 2000, 3000);
  else if (datoGas <= 640) ppm = map(datoGas, 601, 640, 3000, 4000);
  else if (datoGas <= 678) ppm = map(datoGas, 640, 678, 4000, 5000);
  else if (datoGas <= 716) ppm = map(datoGas, 678, 716, 5000, 6000);
  else if (datoGas <= 755) ppm = map(datoGas, 716, 755, 6000, 7000);
  else if (datoGas <= 793) ppm = map(datoGas, 755, 793, 7000, 8000);
  else if (datoGas <= 831) ppm = map(datoGas, 793, 831, 8000, 9000);
  else if (datoGas <= 870) ppm = map(datoGas, 831, 870, 9000, 10000);

  // Mostrar los resultados
  Serial.print("La particula por millon es: ");
  Serial.println(ppm);
  Serial.print("Valor registrado de gas: ");
  Serial.println(datoGas);

  // Verificar los rangos y mostrar la calidad del gas
  if (datoGas == 487) {
    Serial.println("La calidad del gas es: Nivel 0 - Estamos bien");
  }
  else if (datoGas >= 525 && datoGas < 563) {
    Serial.println("La calidad del gas es: Nivel 1 - Estamos bien");
  }
  else if (datoGas >= 563 && datoGas < 601) {
    Serial.println("La calidad del gas es: Mas o menos");
  }
  else if (datoGas >= 601 && datoGas < 640) {
    Serial.println("La calidad del gas es: Estamos un poco mal");
  }
  else if (datoGas >= 640 && datoGas < 678) {
    Serial.println("La calidad del gas es: Estamos mal");
  }
  else if (datoGas >= 678 && datoGas < 716) {
    Serial.println("La calidad del gas es: Estamos muy mal");
  }
  else if (datoGas >= 716 && datoGas < 755) {
    Serial.println("La calidad del gas es: ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 755 && datoGas < 793) {
    Serial.println("La calidad del gas es: ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 793 && datoGas < 831) {
    Serial.println("La calidad del gas es: ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 831 && datoGas < 870) {
    Serial.println("La calidad del gas es: ESTAMOS EN PELIGRO");
  }
  else if (datoGas >= 870) {
    Serial.println("La calidad del gas es: ESTAMOS EN PELIGRO EXTREMO");
  }
}


