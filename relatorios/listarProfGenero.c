#include "relatorios.h"

void listarProfGenero(rgInfoPessoa *prof) {
  if (listarPessoas(prof)) {
    printf("\nProfessores do gênero Masculino");
    for (int i = usuariosQtd - 1; i >= 0; i--) {
      if (prof[i].matricula == 0)
        continue;

      else if (prof[i].sexo == 'M') {
        printf("\n- ");
        puts(prof[i].nome);
      }
    }

    printf("\nProfessores do gênero Feminino");
    for (int i = usuariosQtd - 1; i >= 0; i--) {
      if (prof[i].matricula == 0)
        continue;

      else if (prof[i].sexo == 'F') {
        printf("\n- ");
        puts(prof[i].nome);
      }
    }

    printf("\nProfessores que desejaram não informar");
    for (int i = usuariosQtd - 1; i >= 0; i--) {
      if (prof[i].matricula == 0)
        continue;

      else if (prof[i].sexo == 'N') {
        printf("\n-");
        puts(prof[i].nome);
      }
    }
  } else {
    printf("Não há professores disponíveis");
  }

  printf("\n\n\n(Aperte Enter para continuar)");
  getchar();
}
