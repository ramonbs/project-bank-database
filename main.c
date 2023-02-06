#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#define TOTAL 12


struct registroCliente{
    int numeroDaContaCorrente;
    char nomeDoCliente [50];
    float saldoAtualDaConta;
};

//Vetor declarado globalmente para funcionar com as diversas fun��es
struct registroCliente regCliente[TOTAL];

//Fun��o para cadastro de novos clientes
void cadastroNovosClientes(){
    int i;
    for(i = 0; i < TOTAL; i++){
        printf("\t\t\t\nCADASTRO DE NOVOS CLIENTES\n\n");
        printf("Digite o nome do cliente:............: ");
        scanf("%s", &regCliente[i].nomeDoCliente);
        fflush(stdin); //limpa o buffer

        printf("Digite o n�mero da conta:............: ");
        scanf("%d", &regCliente[i].numeroDaContaCorrente);
        fflush(stdin);

        printf("Digite o total � ser depositado na conta:............:R$ ");
        scanf("%f", &regCliente[i].saldoAtualDaConta);
        fflush(stdin);

        printf("PROCESSANDO...\n");
        sleep(1);
        printf("\t\t\tCliente registrado com sucesso!");
        sleep(1);

    }
    system("cls");
}

//Fun��o para consultar clientes cadastrado na op��o 1
void consultarClientes(){
    int i;
    printf("\t\nColetando dados dos clientes...\n");
    sleep(1);
    for(i = 0; i<  TOTAL; i++){
        printf("Nome do cliente.....: %s\n", regCliente[i].nomeDoCliente);
        printf("N�mero da conta.....: %d\n", regCliente[i].numeroDaContaCorrente);
        printf("Saldo atual da conta.....:R$ %.2f\n", regCliente[i].saldoAtualDaConta);
    }
    sleep(5);
    system("cls");
}


//Fun��o para consultar menor dos saldos entre os cadastrados
void encontrarMinimo() {
  int c, numeroConta, index = 0;
  float min;

  min = regCliente[0].saldoAtualDaConta;
  nome = regCliente[0].nomeDoCliente;
  numeroConta = regCliente[0].numeroDaContaCorrente;


  for (c = 0; c < TOTAL; c++){
    if (regCliente[c].saldoAtualDaConta < min){
      min = regCliente[c].saldoAtualDaConta;
      numeroConta = regCliente[c].numeroDaContaCorrente;
    }
  }

  printf("O menor saldo � no valor de: %.2f\n\n", min);
  printf("Conta: %d", numeroConta);
  sleep(3);
  system("cls");
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, opcao;
    float saldo;

    while(true)
    {
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\tBANCO UNINTER\n\n");
        printf("\t1. Cadastrar novos clientes\n");
        printf("\t2. Consultar todos os clientes\n");
        printf("\t3. Mostrar dados do cliente com menor saldo em conta corrente\n");
        printf("\t4. Sair\n\n");
        printf("Informe o n�mero da op��o desejada: \n\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        scanf("%d", &opcao); //Armazena os n�meros na declara��o opcao.

         //cases das op��es escolhidas anteriormente
        switch (opcao){
            case 1://op��o para cadastrar novos clientes
                cadastroNovosClientes();
                break;

            case 2://op��o para consultar todos os clientes
                consultarClientes();
                break;

            case 3://op��o para consultar o menor saldo entre as contas
                encontrarMinimo();
                break;

            case 4:
                exit(0);

            default:
                break;
        }
    }
}

