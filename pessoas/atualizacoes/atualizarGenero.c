#include "./atualizacesModulos.h"

void atualizarGenero(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    system("clear");
    printf("\n\nEscolha o novo gênero: ");
    pessoa[pessoaEscolhida - 1].sexo = getchar();

    if (pessoa[pessoaEscolhida - 1].sexo == 'M' ||
        pessoa[pessoaEscolhida - 1].sexo == 'F' || 
        pessoa[pessoaEscolhida - 1].sexo == 'N')
      break;

    printf("Gênero inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}