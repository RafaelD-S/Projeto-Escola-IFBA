#include "./atualizacoesModulos.h"

void atualizarDataDeNascimento(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("\n\nEscolha a nova data de nascimento: ");
    scanf("%d", &pessoa[pessoaEscolhida - 1].dtNasc);
    getchar();

    if (pessoa[pessoaEscolhida - 1].dtNasc > 9999999 && pessoa[pessoaEscolhida - 1].dtNasc < 99999999)
      break;

    printf("Data de nascimento inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}



