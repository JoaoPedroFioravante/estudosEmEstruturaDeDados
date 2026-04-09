typedef struct lista Lista;

Lista * createLista();
int adicionarNoFim(Lista*lista, int num);
int adicionarNoInicio(Lista*lista, int num);
int adicionarApos(Lista*lista, int numProcurado, int num);
int removerElemento(Lista*lista, int num);
void exibirLista(Lista*lista);
void freeLista(Lista*lista);