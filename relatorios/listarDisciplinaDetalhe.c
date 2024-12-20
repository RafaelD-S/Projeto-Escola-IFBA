#include "relatorios.h"

void listarDisciplinaDetalhe(procedimentoMatricula *disciplina, rgInfoPessoa *alunos) {
  int temDisciplina = false;
  system("clear");
  for (int i = 0; i < disciplinaQtd; i++) {
    if (disciplina[i].codigo == 0)
      continue;

    else {
      temDisciplina = true;
      printf("[%d] ", i + 1);
      puts(disciplina[i].nome);
    }
  }

  if (!temDisciplina) {
    printf("NÃO HÁ DISCIPLINAS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
  else {
    int disciplinaEscolhida;
    printf("\n\nQual disciplina deseja visualizar? (selecione o id): ");
    scanf("%d", &disciplinaEscolhida);
    getchar();

    if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0 || disciplinaEscolhida >= disciplinaQtd) {
      printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
      getchar();
    } 
    else {
      system("clear");
      puts(disciplina[disciplinaEscolhida - 1].nome);
      printf("- Código: %d\n- Semestre: %d\n- Professor: ", disciplina[disciplinaEscolhida - 1].codigo, disciplina[disciplinaEscolhida - 1].semestre);
      if (disciplina[disciplinaEscolhida - 1].professor[0] != '\0')  
        puts(disciplina[disciplinaEscolhida - 1].professor);
      else
        printf("Não há professor cadastrado\n");

      if (disciplina[disciplinaEscolhida - 1].alunos[0] != 0) {
        printf("- Alunos Cadastrados na Disciplina: \n");

        for (int j = 0; j < usuariosQtd; j++) {
          for (int k = 0; k < usuariosQtd; k++) {
            if (disciplina[disciplinaEscolhida - 1].alunos[j] == alunos[k].matricula && disciplina[disciplinaEscolhida - 1].alunos[j] != 0) {
              printf("  %d. ", j + 1);
              puts(alunos[k].nome);
              break;
            } 
          }
        }

        printf("\n\n");
      } 
      else {
        printf("- Não há alunos cadastrados nessa disciplina\n\n\n");
      }

      printf("(Aperte Enter para continuar)\n\n");
      getchar();
    }
  }
}