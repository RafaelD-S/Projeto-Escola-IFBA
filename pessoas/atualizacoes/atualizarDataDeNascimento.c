#include "./atualizacoesModulos.h"

void atualizarDataDeNascimento(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("Escolha a nova data de nascimento: ");
    scanf("%d", &pessoa[pessoaEscolhida - 1].dtNasc);
    getchar();

    if (validarDataDeNascimento(pessoa, pessoaEscolhida - 1))
      break;
  }
}



