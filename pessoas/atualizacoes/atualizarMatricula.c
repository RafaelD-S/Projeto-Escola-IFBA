#include "./atualizacoesModulos.h"

void atualizarMatricula(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    int jaTemMatricula = false;
    system("clear");
    printf("Informe a nova matricula: ");
    scanf("%ld", &pessoa[pessoaEscolhida - 1].matricula);
    getchar();

    if (validarMatricula(pessoa, pessoaEscolhida - 1))
      break;
  }
}



