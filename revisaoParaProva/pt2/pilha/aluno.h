typedef struct aluno Aluno;

//criarAluno, obterProntuario, obterNome, liberarAluno
Aluno* criarAluno(char*nome, char*prontuario);
int obterProntuario(Aluno * aluno, char*prontuario);
int obterNome(Aluno*aluno, char*nome);
void liberarAluno(Aluno*aluno);
