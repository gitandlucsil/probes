#include "DHT.h" //Biblioteca retirada de https://github.com/adafruit/DHT-sensor-library
#include "ArduinoJson.h" //Biblioteca retirada de https://github.com/bblanchon/ArduinoJson

#define DHTPIN_1 A1
#define DHTPIN_2 A2
#define DHTTYPE DHT11

DHT dht_1(DHTPIN_1, DHTTYPE);
DHT dht_2(DHTPIN_2, DHTTYPE);

struct probe_t_h{
  int humidity;
  int temperature;
};

probe_t_h probe1;
probe_t_h probe2;

void getUmidity(int *h_1, int *h_2)
{
  *h_1 = (int) dht_1.readHumidity();
  *h_2 = (int) dht_2.readHumidity();
}

void getTemperature(int *t_1, int *t_2)
{
  *t_1 = (int) dht_1.readTemperature();
  *t_2 = (int) dht_2.readTemperature();
}

DynamicJsonBuffer jsonBuffer;

void setup()
{
  Serial.begin(9600);
  dht_1.begin();
  dht_2.begin();
}

void loop() {
  
  getUmidity(&probe1.humidity,&probe2.humidity);
  getTemperature(&probe1.temperature,&probe2.temperature);
  JsonObject& json = jsonBuffer.createObject();
  json["temp_1"] = probe1.temperature;
  json["temp_2"] = probe2.temperature;
  json["hum_1"] = probe1.humidity;
  json["hum_2"] = probe2.humidity;
  json.printTo(Serial);
  delay(5000);
  /*int humidity_1 = (int) dht_1.readHumidity();
  int temperature_1 = (int) dht_1.readTemperature();
  int humidity_2 = (int) dht_2.readHumidity();
  int temperature_2 = (int) dht_2.readTemperature();
  int humidity_3 = (int) dht_3.readHumidity();
  int temperature_3 = (int) dht_3.readTemperature();*/
 
  /*if(isnan(probe1.temperature) || isnan(probe1.humidity)){
    Serial.println("Falha ao ler do sensor DHT 1!");
  }else{
    Serial.print("Umidade Sensor 1: ");
    Serial.print(probe1.humidity);
    Serial.print(" %");
    Serial.print("Temperatura Sensor 1: ");
    Serial.print(probe1.temperature);
    Serial.print(" ºC");
    Serial.print("\n");
  }
  if(isnan(probe2.temperature) || isnan(probe2.humidity)){
    Serial.println("Falha ao ler do sensor DHT 2!");
  }else{
    Serial.print("Umidade Sensor 2: ");
    Serial.print(probe2.humidity);
    Serial.print(" %");
    Serial.print("Temperatura Sensor 2: ");
    Serial.print(probe2.temperature);
    Serial.print(" ºC");
    Serial.print("\n");
  }
  if(isnan(probe3.temperature) || isnan(probe3.humidity)){
    Serial.println("Falha ao ler do sensor DHT 3!");
  }else{
    Serial.print("Umidade Sensor 3: ");
    Serial.print(probe3.humidity);
    Serial.print(" %");
    Serial.print("Temperatura Sensor 3: ");
    Serial.print(probe3.temperature);
    Serial.print(" ºC");
    Serial.print("\n");*/

}
