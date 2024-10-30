#include "../school.h"

void atualizarDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *prof) {
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
    printf("\n\nNÃO HÁ DISCIPLINAS PARA ATUALIZAR\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    int disciplinaEscolhida;
    printf("\n\nQual disciplina deseja atualizar: ");
    scanf("%d", &disciplinaEscolhida);
    getchar();

    if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0 || disciplinaEscolhida >= disciplinaQtd) {
      printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
      getchar();
    } 
    else {
      system("clear");
      printf("Que mudança deseja fazer\n");
      const char *opcoes[] = {
        "Mudar o nome",
        "Mudar o código",
        "Mudar o semestre",
        "Mudar o professor da disciplina",
      };
      int escolhaAtualizarDisciplina = listarOpcoes(opcoes, 4);;

      // Escolher um novo nome para uma disciplina
      if (escolhaAtualizarDisciplina == 1) {
        while (true) {
          system("clear");
          printf("Informe o novo nome para a disciplina: ");
          fgets(disciplina[disciplinaEscolhida - 1].nome, nomeTamanho, stdin);

          // Capitalização da Disciplina
          for (int j = 97; j < 122; j++) {
            if (disciplina[disciplinaEscolhida - 1].nome[0] == j) {
              disciplina[disciplinaEscolhida - 1].nome[0] = disciplina[disciplinaEscolhida - 1].nome[0] - 32;
              break;
            }
          }            

          if (strlen(disciplina[disciplinaEscolhida - 1].nome) > 1)
            break;

          printf("Nome inválido. Tente novamente. \n(Aperte Enter para continuar)\n\n");
          getchar();              
        }                
      }
      // Escolher um novo código para a disciplina
      else if (escolhaAtualizarDisciplina == 2) {
        while (true) {
          system("clear");
          printf("\n\nQual o código da disciplina?: ");
          scanf("%d", &disciplina[disciplinaEscolhida - 1].codigo);
          getchar();

          int jaTemDisciplina = false;
          for (int j = disciplinaQtd - 1; j >= 0; j--) {
            if (disciplina[j].codigo == disciplina[disciplinaEscolhida - 1].codigo && disciplinaEscolhida - 1 != j)
              jaTemDisciplina = true;

            else {
              continue;
            }
          }

          if (jaTemDisciplina && disciplina[disciplinaEscolhida - 1].codigo != 0) {
            printf("\n\nJá existe uma disciplina com esse código. Tente novamente. \n(Aperte Enter para continuar)\n\n");
            getchar();
            continue;
          }

          if (disciplina[disciplinaEscolhida - 1].codigo > 0)
            break;

          printf("Código inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
      }
      // Escolher um novo semestre para a disciplina
      else if (escolhaAtualizarDisciplina == 3) {
        while (true) {
          system("clear");
          printf("Informe o novo semestre [Insira apenas numeros]: ");
          scanf("%d", &disciplina[disciplinaEscolhida - 1].semestre);
          getchar();

          if (disciplina[disciplinaEscolhida - 1].semestre > 0)
            break;

          printf("Semestre inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
          getchar();
        }

      }
      // Escolher um novo nome para o professor da disciplina
      else if (escolhaAtualizarDisciplina == 4) {
        while (true) {
          system("clear");
          int temProf = false;
          for (int j = usuariosQtd - 1; j >= 0; j--) {
            if (prof[j].matricula == 0)
              continue;

            else {
              temProf = true;
              printf("[%d] ", j + 1);
              puts(prof[j].nome);
            }
          }

          if (!temProf) {
            printf("\n\nNÃO HÁ PROFESSORES PARA SELECIONAR \n(Aperte Enter para continuar)\n\n");
            getchar();


            disciplina[disciplinaEscolhida - 1].codigo = 0;
            break;  
          } 
          else {
            int profSelecionado;
            printf("\n\nQual o nome do professor da disciplina? (selecione o id): ");
            scanf("%d", &profSelecionado);
            getchar();

            if (prof[profSelecionado - 1].matricula == 0) {
              printf("\n\nEsse professor não existe \n(Aperte Enter para continuar)\n\n");
              getchar();      
            } 
            else {
              for (int j = 0; j < nomeTamanho; j++) {
                disciplina[disciplinaEscolhida - 1].professor[j] = prof[profSelecionado - 1].nome[j];
              }
              break;
            }
          }              
        }
      }
    }
  }
}