#include "DHT.h" //Biblioteca retirada de https://github.com/adafruit/DHT-sensor-library

#define DHTPIN_1 A1
#define DHTPIN_2 A2
#define DHTPIN_3 A4
#define DHTPIN_4 A5
#define DHTTYPE DHT11

DHT dht_1(DHTPIN_1, DHTTYPE);
DHT dht_2(DHTPIN_2, DHTTYPE);
DHT dht_3(DHTPIN_3, DHTTYPE);
/*DHT dht_4(DHTPIN_4, DHTTYPE);*/

void setup() {
  Serial.begin(9600);
  dht_1.begin();
  dht_2.begin();
  dht_3.begin();
  /*dht_4.begin();*/
}

void loop() {
  float h_1 = dht_1.readHumidity();
  float t_1 = dht_1.readTemperature();
  float h_2 = dht_2.readHumidity();
  float t_2 = dht_2.readTemperature();
  float h_3 = dht_3.readHumidity();
  float t_3 = dht_3.readTemperature();
  /*float h_4 = dht_4.readHumidity();
  float t_4 = dht_4.readTemperature();*/
  
  delay(2000);
  if(isnan(t_1) || isnan(h_1)){
    Serial.println("Falha ao ler do sensor DHT 1!");
  }else{
    Serial.print("Umidade Sensor 1: ");
    Serial.print(h_1);
    Serial.print(" %");
    Serial.print("Temperatura Sensor 1: ");
    Serial.print(t_1);
    Serial.print(" ºC");
    Serial.print("\n");
  }
  if(isnan(t_2) || isnan(h_2)){
    Serial.println("Falha ao ler do sensor DHT 2!");
  }else{
    Serial.print("Umidade Sensor 2: ");
    Serial.print(h_2);
    Serial.print(" %");
    Serial.print("Temperatura Sensor 2: ");
    Serial.print(t_2);
    Serial.print(" ºC");
    Serial.print("\n");
  }
  if(isnan(t_3) || isnan(h_3)){
    Serial.println("Falha ao ler do sensor DHT 3!");
  }else{
    Serial.print("Umidade Sensor 3: ");
    Serial.print(h_3);
    Serial.print(" %");
    Serial.print("Temperatura Sensor 3: ");
    Serial.print(t_3);
    Serial.print(" ºC");
    Serial.print("\n");
  }
  /*if(isnan(t_4) || isnan(h_4)){
    Serial.println("Falha ao ler do sensor DHT 4!");
  }else{
    Serial.print("Umidade Sensor 4: ");
    Serial.print(h_4);
    Serial.print(" %");
    Serial.print("Temperatura Sensor 4: ");
    Serial.print(t_4);
    Serial.print(" ºC");
    Serial.print("\n");
  }*/
}
