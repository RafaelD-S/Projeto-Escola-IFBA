#include "./atualizacoesModulos.h"

void atualizarMatricula(rgInfoPessoa *pessoa, int pessoaEscolhida) {
  while (true) {
    int jaTemMatricula = false;
    system("clear");
    printf("\n\nInforme a nova matricula: ");
    scanf("%d", &pessoa[pessoaEscolhida - 1].matricula);
    getchar();

    for (int j = usuariosQtd - 1; j >= 0; j--) {
      if (pessoa[j].matricula == pessoa[pessoaEscolhida - 1].matricula && pessoaEscolhida - 1 != j)
        jaTemMatricula = true;

      else
        continue;
    }

    if (jaTemMatricula && pessoa[pessoaEscolhida - 1].matricula != 0) {
      printf("\nJá existe alguém com essa matricula. Tente novamente. \n(Aperte Enter para continuar)\n");
      getchar();
      continue;
    }

    if (pessoa[pessoaEscolhida - 1].matricula > 0)
      break;

    printf("Matricula inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}



