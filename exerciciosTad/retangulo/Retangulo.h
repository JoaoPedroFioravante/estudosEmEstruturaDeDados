typedef struct retangulo Retangulo;

/*criarRetangulo, calcularArea, calcularPerimetro,
liberarRetangulo*/

Retangulo* criarRetangulo(int altura, int largura);
int calcularArea(Retangulo* retangulo);
int calcularPerimetro(Retangulo* retangulo);
void liberarRetangulo(Retangulo* retangulo);

