#include "relatorios.h"

void listarDisciplinasQuarentaVagas(procedimentoMatricula *disciplina) {
  int temDisciplina = false;
  system("clear");
  for (int i = disciplinaQtd - 1; i >= 0; i--) {
    if (disciplina[i].codigo == 0)
      continue;

    else {
      temDisciplina = true;
      break;
    }
  }

  if (!temDisciplina) {
    printf("\n\nNÃO HÁ DISCIPLINAS CADASTRADAS\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    int disciplinaCheia = false;
    for (int i = 0; i < disciplinaQtd; i++) {
      int alunos = 0;
      for (int j = 0; j < usuariosQtd; j++) {
        if (disciplina[i].alunos[j] != 0) {
          alunos++;
        }
      }
      if (alunos > 40) {
        disciplinaCheia = true;
        puts(disciplina[i].nome);
        printf("- Professor: ");
        puts(disciplina[i].professor);
        printf("- Quantidade de Alunos: %d", alunos);
        printf("\n\n");
      }
    }

    if (!disciplinaCheia) {
      printf("NÃO HÁ DISCIPLINAS COM MAIS DE 40 ALUNOS CADASTRADOS\n(Aperte Enter para continuar)\n\n");
      getchar();
    } else {
      printf("(Aperte Enter para continuar)\n\n");
      getchar();
    }
  }
}