typedef struct carro Carro;

Carro * criarCarro(char*marca, char*placa, int ano);
void getPlacaCarro(Carro*carro, char*placa);
void freeCarro(Carro * carro);