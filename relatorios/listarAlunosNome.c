#include "relatorios.h"

void listarAlunosNome(rgInfoPessoa *alunos) {
  system("clear");
  int temAluno = false;
  for (int i = 0; i < usuariosQtd; i++) {
    if (alunos[i].matricula == 0)
      continue;

    else 
      temAluno = true;
  }

  if (!temAluno) {
    printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    char alunosNome[usuariosQtd][nomeTamanho] = {'\0'};  
    for (int i = 0; i < usuariosQtd; i++) {
      if (alunos[i].nome[0] != '\0')
        strcpy(alunosNome[i], alunos[i].nome);
    }

    for (int i = 0; i < usuariosQtd; i++) {
      for (int j = 0; j < usuariosQtd; j++) {
        if (alunosNome[j + 1][0] != '\0') {
          int ordenacao = strcmp(alunosNome[j], alunosNome[j + 1]);

          if (ordenacao > 0) {
            char aux[nomeTamanho];
            strcpy(aux, alunosNome[j]);
            strcpy(alunosNome[j], alunosNome[j + 1]);
            strcpy(alunosNome[j + 1], aux);
          }
          else 
            continue;
        }
        else 
          continue;
      }
    }

    for (int i = 0; i < usuariosQtd; i++) {
      if (alunosNome[i][0] != '\0') {
        printf("%d. ", i + 1);
        puts(alunosNome[i]);
      }
    }
    printf("\n\n(Aperte Enter para continuar)");
    getchar();
  }
}