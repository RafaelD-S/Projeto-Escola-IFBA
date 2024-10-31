#include "./atualizacoesModulos.h"

void atualizarCpf(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("Escolha um novo cpf: ");
    scanf("%ld", &pessoa[pessoaEscolhida - 1].cpf);
    getchar();

    if (validarCpf(pessoa, pessoaEscolhida - 1))
      break;
  }
}