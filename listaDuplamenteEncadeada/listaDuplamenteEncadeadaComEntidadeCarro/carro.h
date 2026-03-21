typedef struct carro Carro;

Carro*criarCarro(char*placa, char*marca, int ano);
int getPlaca(Carro*carro, char*placa);
void freeCarro(Carro*carro);