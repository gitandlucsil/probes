#include "DHT.h" //Biblioteca retirada de https://github.com/adafruit/DHT-sensor-library
/*Definicoes e estruturas para trabalhar com sensor DHT11*/
#define DHTPIN_1 A1
#define DHTPIN_2 A2
#define DHTTYPE DHT11
DHT dht_1(DHTPIN_1, DHTTYPE);
DHT dht_2(DHTPIN_2, DHTTYPE);
/*Estrutura de dado para trabalhar com os sensores, responsavel pelo envio da informação para o servidor*/
typedef struct probe_t{
  int id;
  char *descriptor;
  int value;
};
/*Instanciação dos sensores*/
probe_t p1;
probe_t p2;
probe_t p3;
probe_t p4;
/*Função responsável para recuperar os valores dos sensores, recebendo como parametro o id e o endereco de memoria em que se deseja atualizar o valor*/
void readFromProbes(int id, int *value)
{
  switch(id)
  {
    case 1:
      *value = (int) dht_1.readTemperature();
      break;
    case 2:
      *value = (int) dht_1.readHumidity();
      break;
    case 3:
      *value = (int) dht_2.readTemperature();
      break;
    case 4:
      *value = (int) dht_2.readHumidity();
      break; 
  }
}
/*Função que transforma os objetos JSON em String*/
void mountJSON(String *json_to_mount)
{
  *json_to_mount += "[{'id:";
  *json_to_mount += p1.id;
  *json_to_mount += ", read_value: ";
  *json_to_mount += p1.value;
  *json_to_mount += "},";
  *json_to_mount += "{";
  *json_to_mount += p2.id;
  *json_to_mount += ", read_value: ";
  *json_to_mount += p2.value;
  *json_to_mount += "},";
  *json_to_mount += "{";
  *json_to_mount += p3.id;
  *json_to_mount += ", read_value: ";
  *json_to_mount += p3.value;
  *json_to_mount += "},";
  *json_to_mount += "{";
  *json_to_mount += p4.id;
  *json_to_mount += ", read_value: ";
  *json_to_mount += p4.value;
  *json_to_mount += "}]";
}
void setup()
{
    /*Inicializa a serial*/
  Serial.begin(9600);
  /*Inicializa os modulos DHT11*/
  dht_1.begin();
  dht_2.begin();
  /*Inicializa as estrutras dos sensores*/
  p1.id = 1;
  p1.descriptor = (char *)"T1";
  p2.id = 2;
  p2.descriptor = (char *)"U1";
  p3.id = 3;
  p3.descriptor = (char *)"T2";
  p4.id = 4;
  p4.descriptor = (char *)"U2";
}

void loop()
{
  /*Realiza as leituras dos sensores*/
  readFromProbes(p1.id,&p1.value);
  readFromProbes(p2.id,&p2.value);
  readFromProbes(p3.id,&p3.value);
  readFromProbes(p4.id,&p4.value);
  String json;
  mountJSON(&json);
  Serial.print(json);
  Serial.flush();
  delay(120000);
}

