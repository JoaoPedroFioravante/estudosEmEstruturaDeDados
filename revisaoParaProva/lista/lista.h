typedef struct lista Lista;

Lista* createLista();
int addLista(int num, Lista*lista, int index);
int delLista(int index, Lista*lista);
int searchLista(int num, Lista*lista);
int elementInIndex(int index, Lista*lista, int *num);
void exibirLista(Lista*lista);
void freeLista(Lista*lista);