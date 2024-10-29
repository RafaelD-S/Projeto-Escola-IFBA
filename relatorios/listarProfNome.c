#include "relatorios.h"

void listarProfNome(rgInfoPessoa *prof) {
    system("clear");
  int temProfessor = false;
  for (int i = 0; i < usuariosQtd; i++) {
    if (prof[i].matricula == 0)
      continue;

    else 
      temProfessor = true;
  }

  if (!temProfessor) {
    printf("\n\nNÃO HÁ PROFESSORES DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    char profNome[usuariosQtd][nomeTamanho] = {'\0'};  
    for (int i = 0; i < usuariosQtd; i++) {
      if (prof[i].nome[0] != '\0')
        strcpy(profNome[i], prof[i].nome);
    }

    for (int i = 0; i < usuariosQtd; i++) {
      for (int j = 0; j < usuariosQtd; j++) {
        if (profNome[j + 1][0] != '\0') {
          int ordenacao = strcmp(profNome[j], profNome[j + 1]);

          if (ordenacao > 0) {
            char aux[nomeTamanho];
            strcpy(aux, profNome[j]);
            strcpy(profNome[j], profNome[j + 1]);
            strcpy(profNome[j + 1], aux);
          }
          else 
            continue;
        }
        else 
          continue;
      }
    }

    for (int i = 0; i < usuariosQtd; i++) {
      if (profNome[i][0] != '\0') {
        printf("- ");
        puts(profNome[i]);
      }
    }
  }
  printf("\n\n(Aperte Enter para continuar)");
  getchar();
}