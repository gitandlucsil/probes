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

[{"id":1,"value":26},{"id":2,"value":74},{"id":3,"value":27},{"id":4,"value":70}]
