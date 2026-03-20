typedef struct listaEncadeada ListaEncadeada;

ListaEncadeada *criarLista();
int adicionarNoFim(ListaEncadeada *lista, int valor);
int adicionarNoInicio(ListaEncadeada *lista, int valor);
int adicionarAposElemento(ListaEncadeada *lista, int valor, int elemento);
int remover(ListaEncadeada *lista, int valor);
int buscar(ListaEncadeada *lista, int valor);
void exibirLista(ListaEncadeada *lista);
void freeLista(ListaEncadeada*lista);