#include "relatorios.h"

void listarProf(rgInfoPessoa *prof) {
  if (listarPessoas(prof)) {
    printf("\n\nProfessores listados com sucesso\n(Aperte Enter para continuar)\n\n");
    getchar();
  } else {
    printf("\n\nNÃO HÁ PROFESSORES DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}

