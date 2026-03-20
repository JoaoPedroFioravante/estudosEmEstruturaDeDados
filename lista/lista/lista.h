#define MAXSIZE 10

typedef struct list List;

List * createList();
int addElement(List*list, int element, int pos);
int removeElement(List*list, int pos, int*elementRemoved);
int removeValue(List*list, int value);
int searchElement(List*list, int value, int*pos);
void displayList(List*list);
void freeList(List*list);
