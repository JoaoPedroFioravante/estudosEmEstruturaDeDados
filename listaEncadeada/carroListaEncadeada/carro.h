typedef struct carro Carro;

Carro * criarCarro(char*marca, char*placa, int ano);
char* getPlacaCarro(Carro*carro);
void freeCarro(Carro * carro);