#include "./atualizacoesModulos.h"

void atualizarNome(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("\n\nInforme o novo nome: ");
    fgets(pessoa[pessoaEscolhida - 1].nome, 30, stdin);

    // Capitalização do Aluno
    for (int j = 97; j < 122; j++) {
      if (pessoa[pessoaEscolhida - 1].nome[0] == j) {
        pessoa[pessoaEscolhida - 1].nome[0] = pessoa[pessoaEscolhida - 1].nome[0] - 32;
        break;
      }
    }

    if (strlen(pessoa[pessoaEscolhida - 1].nome) > 1)
      break;

    printf("Nome inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}