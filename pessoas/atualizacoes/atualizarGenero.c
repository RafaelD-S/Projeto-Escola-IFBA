#include "./atualizacoesModulos.h"

void atualizarGenero(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("Escolha o novo gênero: ");
    pessoa[pessoaEscolhida - 1].sexo = getchar();

    if (validarGenero(pessoa, pessoaEscolhida - 1))
      break;
  }
}