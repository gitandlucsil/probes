# probes
Leitura de sensores a partir de um controlador, enviando as respostas em formato JSON.

No exemplo do código, é utilizado um sensor de temperatura do modelo DHT11 como exemplo prático, porém as estruturas e funções definidas são para uso geral, independente do sesor.

A estrutura que armazena as informações dos sensores é da seguinte forma:

struct probe{
  int id;
  char *descriptor;
  int value;
};

Sendo, "id" o identificador do sensor, "descriptor" uma string para descrever o sensor e "value" o valor de leitura no formato inteiro.

A saída é dada em uma mensagem JSON no seguinte formato:
[{"id":1,"read_value":25},{"id":2,"read_value":62},{"id":3,"read_value":29},{"id":4,"read_value":52}]

Essa saída é enviada para a porta serial, na qual uma aplicação recebe tal JSON e envia os dados de leitura para uma Api Rest.
