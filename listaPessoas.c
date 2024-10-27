#include "school.h"

int listaPessoas(rgInfoPessoa *pessoasLista) {

  int temAluno = false;
  system("clear");
  for (int i = usuariosQtd - 1; i >= 0; i--) {
    if (pessoasLista[i].matricula == 0)
      continue;

    else {
      temAluno = true;
      printf("[%d] ", i + 1);
      puts(pessoasLista[i].nome);
    }
  }

  return temAluno;
}