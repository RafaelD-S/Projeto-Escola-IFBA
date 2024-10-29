#include "./atualizacesModulos.h"

void atualizarCpf(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("\n\nEscolha um novo cpf: ");
    scanf("%ld", &pessoa[pessoaEscolhida - 1].cpf);
    getchar();

    if (pessoa[pessoaEscolhida - 1].cpf > 9999999999 && pessoa[pessoaEscolhida - 1].cpf < 99999999999)
      break;

    printf("CPF inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}



