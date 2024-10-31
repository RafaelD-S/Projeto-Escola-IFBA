#include "./atualizacoesModulos.h"

void atualizarNome(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("Informe o novo nome: ");
    fgets(pessoa[pessoaEscolhida - 1].nome, nomeTamanho, stdin);

    if (validarNome(pessoa, pessoaEscolhida - 1))
      break;
  }
}