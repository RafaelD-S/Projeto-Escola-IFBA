#include "../school.h"

void excluirDisciplina(procedimentoMatricula *disciplina) {
  int temDisciplina = false;
  system("clear");
  for (int i = disciplinaQtd - 1; i >= 0; i--) {
    if (disciplina[i].codigo == 0)
      continue;

    else {
      temDisciplina = true;
      printf("[%d] ", i + 1);
      puts(disciplina[i].nome);
    }
  }

  if (!temDisciplina) {
    printf("\n\nNÃO HÁ DISCIPLINAS PARA EXCLUIR\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    int disciplinaExcluida;
    printf("\nQual disciplina você gostaria de remover? (selecione o id): ");
    scanf("%d", &disciplinaExcluida);
    getchar();

    if (disciplina[disciplinaExcluida - 1].codigo == 0 || disciplinaExcluida == 0 || disciplinaExcluida >= disciplinaQtd) {
      printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
      getchar();
    } 
    else {
      disciplina[disciplinaExcluida - 1].codigo = 0;
      printf("\n\nDisciplina excluída com sucesso\n(Aperte Enter para continuar)\n\n");
      getchar();

      // reorganização da lista
      for (int j = 0; j < disciplinaQtd - 1; j++) {
        strcpy(disciplina[j].nome, disciplina[j + 1].nome);
        disciplina[j].codigo = disciplina[j + 1].codigo;
        disciplina[j].semestre = disciplina[j + 1].semestre;
        strcpy(disciplina[j].professor, disciplina[j + 1].professor);
        for (int k = 0; k < usuariosQtd; k++) {
          disciplina[j].alunos[k] = disciplina[j + 1].alunos[k];        
        }
      }
    }
  }
}

