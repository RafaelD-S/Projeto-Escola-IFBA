#include "../school.h"

void excluirAlunoDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *alunos) {
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
    printf("\n\nNÃO HÁ DISCIPLINAS CADASTRADAS\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    int disciplinaEscolhida;
    printf("\n\nQual disciplina deseja remover o cadastro do aluno? (selecione o id): ");
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
        if (disciplina[disciplinaEscolhida - 1].alunos[j] == 0)
          continue;

        else {
          temAluno = true;
          for (int k = 0; k < usuariosQtd; k++) {
            if (disciplina[disciplinaEscolhida - 1].alunos[j] == alunos[k].matricula) {
              printf("[%d] ", j + 1);
              puts(alunos[k].nome);
              break;
            }
          }
        }
      }

      if (!temAluno) {
        printf("\n\nNÃO HÁ ALUNOS PARA SELECIONAR \n(Aperte Enter para continuar)\n\n");
        getchar();
      } 
      else {
        int alunoSelecionado;
        printf("\n\nQual o nome do aluno que terá o cadastro removido? (selecione o id): ");
        scanf("%d", &alunoSelecionado);
        getchar();

        if (disciplina[disciplinaEscolhida - 1].alunos[alunoSelecionado - 1] == 0) {
          printf("\n\nEsse aluno não existe \n(Aperte Enter para continuar)\n\n");
          getchar();      
        } 
        else {
          for (int i = 0; i < nomeTamanho; i++) {
            disciplina[disciplinaEscolhida - 1].alunos[alunoSelecionado - 1] = 0;
          }
          printf("\n\nCadastro excluído com sucesso\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
      }
    }
  }
}

