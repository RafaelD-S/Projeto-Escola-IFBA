#include "../school.h"

void excluirPessoas(rgInfoPessoa *pessoas) {
  if (listarPessoas(pessoas)) {
    int pessoaExcluida;
    printf("\nQual pessoa você gostaria de remover? (selecione o id): ");
    scanf("%d", &pessoaExcluida);
    getchar();

    if (pessoas[pessoaExcluida - 1].matricula == 0) {
      printf("\n\nEssa pessoa não existe\n(Aperte Enter para continuar)\n\n");
      getchar();
    } else {
      pessoas[pessoaExcluida - 1].matricula = 0;
      printf("\n\nPessoa excluída com sucesso\n(Aperte Enter para continuar)\n\n");
      getchar();
    }
  } else {
    printf("Não há pessoas disponíveis.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}