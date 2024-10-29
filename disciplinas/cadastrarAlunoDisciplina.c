#include "../school.h"

void cadastrarAlunoDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *alunos) {
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
    printf("\n\nNÃO HÁ DISCIPLINAS PARA CADASTRO\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    int disciplinaEscolhida;
    printf("\n\nQual disciplina deseja cadastrar o aluno? (selecione o id): ");
    scanf("%d", &disciplinaEscolhida);
    getchar();

    if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
      printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
      getchar();
    } 
    else {
      system("clear");
      int temAluno = false;
      for (int j = 0; j < usuariosQtd; j++) {
        if (alunos[j].matricula == 0)
            continue;

        else {
          temAluno = true;
          printf("[%d] ", j + 1);
          puts(alunos[j].nome);
        }
      }

      if (!temAluno) {
        printf("\n\nNÃO HÁ ALUNOS PARA SELECIONAR \n(Aperte Enter para continuar)\n\n");
        getchar();
      } 
      else {
        int alunoSelecionado;
        printf("\n\nQual o nome do aluno que será cadastrado? (selecione o id): ");
        scanf("%d", &alunoSelecionado);
        getchar();

        if (alunos[alunoSelecionado - 1].matricula == 0) {
          printf("\n\nEsse aluno não existe \n(Aperte Enter para continuar)\n\n");
          getchar();      
        } 
        else {
          int jaTemAluno = false;
          for (int i = 0; i < usuariosQtd; i++) {
            if (disciplina[disciplinaEscolhida - 1].alunos[i] == alunos[alunoSelecionado - 1].matricula) 
              jaTemAluno = true;
          }
          if (jaTemAluno) {
            printf("\n\nEsse aluno já foi cadastrado\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
          else {
            for (int k = 0; k < usuariosQtd; k++) {
              if (disciplina[disciplinaEscolhida - 1].alunos[k] == 0) {
                disciplina[disciplinaEscolhida - 1].alunos[k] = alunos[alunoSelecionado - 1].matricula;
                break;
              }
            }
          }
        }
      }
    }
  }
}