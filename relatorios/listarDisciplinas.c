#include "relatorios.h"

void listarDisciplinas(procedimentoMatricula *disciplina) {
  int temDisciplina = false;
  system("clear");
  for (int i = 0; i < disciplinaQtd; i++) {
    if (disciplina[i].codigo == 0)
      continue;

    else {
      temDisciplina = true;
      puts(disciplina[i].nome);
      printf("- Código: %d\n- Semestre: %d\n- Professor: ", disciplina[i].codigo, disciplina[i].semestre);
      if (disciplina[i].professor[0] != '\0')
        puts(disciplina[i].professor);
      else
        printf("Não há professor cadastrado");
      printf("\n\n");
    }
  }

  if (!temDisciplina) {
    printf("NÃO HÁ DISCIPLINAS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  }

  printf("Disciplinas listadas com sucessos\n(Aperte Enter para continuar)\n\n");
  getchar();
}