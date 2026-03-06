typedef struct contaBancaria Conta;

/*criarConta, Depositar, Sacar, Transferir, obterNum,
obterSaldo, liberarConta*/

Conta* criarConta();
int depositar(Conta* conta, float valor);
int sacar(Conta* conta, float valor);
int transferir(Conta* contaEnvia, Conta* contaRecebe, float valor);
int obterNum(Conta* conta);
float getSaldo(Conta* conta);
void freeConta(Conta* conta);
