typedef struct lista Lista;

Lista*criarLista();
int addNum(Lista*lista, int index, int num);
int delIndex(Lista*lista, int index);
int buscarNum(Lista*lista, int num);
void exibir(Lista*lista);
void freeLista(Lista*lista);