#include "relatorios.h"

void listarAlunos(rgInfoPessoa *alunos) {
  if (listarPessoas(alunos)) {
    printf("\n\nAlunos listados com sucesso\n(Aperte Enter para continuar)\n\n");
    getchar();
  } else {
    printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}

