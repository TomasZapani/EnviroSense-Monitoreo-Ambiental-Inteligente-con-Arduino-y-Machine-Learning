#include <DHT.h>  // Librería para el sensor de humedad y temperatura

// Definir pines para cada sensor
int LDRPin = A0;      // Sensor de luz (LDR) conectado a A0
int MQ2Pin = A1;      // Sensor de gas (MQ2) conectado a A1
#define DHTPIN 2      // Sensor DHT (humedad y temperatura) conectado al pin digital 2
#define DHTTYPE DHT11 // Definir el tipo de sensor DHT (puede ser DHT11 o DHT22)

DHT dht(DHTPIN, DHTTYPE);  // Inicializa el sensor DHT

void setup() {
  Serial.begin(9600);      // Inicia la comunicación serial a 9600 baudios
  dht.begin();             // Inicializa el sensor DHT
}

void loop() {
  // Lectura del LDR y del MQ2
  int valorLDR = analogRead(LDRPin);
  int valorMQ2 = analogRead(MQ2Pin);

  // Lectura de humedad y temperatura
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Verificar si la lectura del DHT falló
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer del sensor DHT");
  } else {
    // Imprimir todos los valores en el Monitor Serial
    Serial.print("LDR (luz): ");
    Serial.print(valorLDR);
    Serial.print("  |  MQ2 (gas): ");
    Serial.print(valorMQ2);
    Serial.print("  |  Humedad: ");
    Serial.print(humedad);
    Serial.print("%  |  Temp: ");
    Serial.print(temperatura);
    Serial.println("°C");
  }
  
  delay(1000);  // Espera 1 segundo entre lecturas
}
