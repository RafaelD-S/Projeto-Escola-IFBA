#include "relatorios.h"

void listarMenosQueTresDisciplinas(procedimentoMatricula *disciplina, rgInfoPessoa *alunos) {
  system("clear");
  int temDisciplina = false;
  for (int i = 0; i < disciplinaQtd; i++) {
    if (disciplina[i].codigo == 0)
      continue;

    else 
      temDisciplina = true;
  }

  if (!temDisciplina) {
    printf("NÃO HÁ DISCIPLINAS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
  else {
    int alunoEscolhido;
    int temAluno = false;

    for (int i = 0; i < usuariosQtd; i++) {
      if (alunos[i].matricula == 0) {
        continue;
      }
      else {
        temAluno = true;
        alunoEscolhido = alunos[i].matricula;
        int temCadastro = false;
        int count = 0;

        for (int j = 0; j < disciplinaQtd; j++) {
          if (disciplina[j].alunos[0] == 0)
            continue;

          else {            
            for (int k = 0; k < usuariosQtd; k++) {
              if (disciplina[j].alunos[k] == alunoEscolhido) {
                temCadastro = true;
                count++;
                break;
              }
            }
          }
        }


        if (count < 3 || !temCadastro) {
          for (int k = 0; k < usuariosQtd; k++) {
            if (alunoEscolhido == alunos[k].matricula) {
              printf("- ");
              puts(alunos[k].nome);
            }                
          }
        }
      }
    }

    if (!temAluno) {
      printf("NÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
      getchar();
    }
    else {
      printf("\n\n(Aperte Enter para continuar)");
      getchar();
    }
  }
}