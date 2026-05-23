typedef struct arvore Arvore;

Arvore * createArvore();
void addValorArvore(Arvore * arvore, int valor);
void removeValorArvore(Arvore * arvore, int valor);
void exibirArvoreDfsPreOrdem(Arvore * arvore);
void exibirArvoreEmOrdem(Arvore * arvore);
void exibirArvorePosOrdem(Arvore * arvore);