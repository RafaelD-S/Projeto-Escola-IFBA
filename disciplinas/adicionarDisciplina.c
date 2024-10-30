#include "../school.h"

void adicionarDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *prof) {
  int i = 0;
  for (; i <= disciplinaQtd; i++) {
    if (disciplina[i].codigo == 0)
      break;
  }

  // verificação e cadastro do nome da disciplina
  while (true) {
    system("clear");
    printf("\n\nQual o nome da disciplina?: ");
    fgets(disciplina[i].nome, nomeTamanho, stdin);

    // Capitalização da Disciplina
    for (int j = 97; j < 122; j++) {
      if (disciplina[i].nome[0] == j) {
        disciplina[i].nome[0] = disciplina[i].nome[0] - 32;
        break;
      }
    }              

    if (strlen(disciplina[i].nome) > 1)
      break;

    printf("Nome inválido. Tente novamente. \n(Aperte Enter para continuar)\n\n");
    getchar();              
  }

  // verificação e cadastro do código da disciplina
  while (true) {
    system("clear");
    printf("\n\nQual o código da disciplina?: ");
    scanf("%d", &disciplina[i].codigo);
    getchar();

    int jaTemDisciplina = false;
    for (int j = disciplinaQtd - 1; j >= 0; j--) {
      if (disciplina[j].codigo == disciplina[i].codigo && i != j)
        jaTemDisciplina = true;

      else
        continue;
    }

    if (jaTemDisciplina && disciplina[i].codigo != 0) {
      printf("\n\nJá existe uma disciplina com esse código. Tente novamente. \n(Aperte Enter para continuar)\n\n");
      getchar();
      continue;
    }

    if (disciplina[i].codigo > 0)
      break;

    printf("Código inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }

  // verificação e cadastro do semestre
  while (true) {
    system("clear");
    printf("\n\nQual o semestre da disciplina? [Insira apenas o numero]: ");
    scanf("%d", &disciplina[i].semestre);
    getchar();

    if (disciplina[i].semestre > 0)
      break;

    printf("Semestre inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }

  // verificação e cadastro do professor na disciplina
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

      disciplina[i].codigo = 0;
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
          disciplina[i].professor[j] = prof[profSelecionado - 1].nome[j];
        }
        break;
      }
    }              
  }
}