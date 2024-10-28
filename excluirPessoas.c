#include "school.h"

void excluirPessoas(rgInfoPessoa *pessoas) {
  if (listaPessoas(pessoas)) {
    int pessoaExcluida;
    printf("\nQual aluno você gostaria de remover? (selecione o id): ");
    scanf("%d", &pessoaExcluida);
    getchar();

    if (pessoas[pessoaExcluida - 1].matricula == 0) {
      printf("\n\nEsse aluno não existe\n(Aperte Enter para "
             "continuar)\n\n");
      getchar();
    } else {
      pessoas[pessoaExcluida - 1].matricula = 0;
      printf("\n\nAluno excluído com sucesso\n(Aperte Enter para "
             "continuar)\n\n");
      getchar();
    }
  } else {
    printf(
        "Não foi há pessoas disponíveis. (Aperte Enter para continuar)");
    getchar();
  }
}