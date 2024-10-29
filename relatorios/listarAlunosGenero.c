#include "relatorios.h"

void listarAlunosGenero(rgInfoPessoa *alunos) {
  if (listarPessoas(alunos)) {
    printf("\nAlunos do gênero Masculino");
    for (int i = usuariosQtd - 1; i >= 0; i--) {
      if (alunos[i].matricula == 0)
        continue;

      else if (alunos[i].sexo == 'M') {
        printf("\n- ");
        puts(alunos[i].nome);
      }
    }

    printf("\nAlunos do gênero Feminino");
    for (int i = usuariosQtd - 1; i >= 0; i--) {
      if (alunos[i].matricula == 0)
        continue;

      else if (alunos[i].sexo == 'F') {
        printf("\n- ");
        puts(alunos[i].nome);
      }
    }

    printf("\nAlunos que desejaram não informar");
    for (int i = usuariosQtd - 1; i >= 0; i--) {
      if (alunos[i].matricula == 0)
        continue;

      else if (alunos[i].sexo == 'N') {
        printf("\n-");
        puts(alunos[i].nome);
      }
    }
  } else {
    printf("Não há alunos disponíveis");
  }
  printf("\n\n\n(Aperte Enter para continuar)");
  getchar();
}