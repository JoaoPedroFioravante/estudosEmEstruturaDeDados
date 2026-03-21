typedef struct lista Lista;

Lista*criarLista();
int adicionarInicio(Lista*lista, int valor);
int adicionarFim(Lista*lista, int valor);
int adicionarApos(Lista*lista, int valor, int elemento);
int remover(Lista*lista, int valor);
void mostrarListaDoInicioAoFim(Lista*lista);
void mostrarListaDoFimAoInicio(Lista*lista);
void freeLista(Lista*lista);