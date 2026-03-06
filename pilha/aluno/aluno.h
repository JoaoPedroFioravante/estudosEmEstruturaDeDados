typedef struct aluno Aluno;

Aluno *createStudent(char*name, char*id);
void getId(Aluno*al, char*id);
void getName(Aluno*al, char*name);
void freeStudent(Aluno*al);
