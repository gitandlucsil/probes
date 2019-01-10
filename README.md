# dashboard-temperature
Leitura de sensores a partir de um controlador, enviando as respostas em formato JSON.

No exemplo do código, é utilizado um sensor de temperatura do modelo DHT11 como exemplo prático, porém as estruturas e funções definidas são para uso geral, independente do sesor.

A estrtura que armazena as informações dos sensores é da seguinte forma:

struct probe{
  int id;
  char *descriptor;
  int value;
};

Sendo, "id" o identificador do sesnor, "descriptor" uma string para descrever o sensor e "value" o valor de leitura no formato inteiro.

A saída é dada em uma mensagem JSON no seguinte formato:
[{"probesidf":{"id_value":1,"description":"T1"},"read_value":25},{"probesidf":{"id_value":2,"description":"U1"},"read_value":72},{"probesidf":{"id_value":3,"description":"T2"},"read_value":26},{"probesidf":{"id_value":4,"description":"U2"},"read_value":68}]
