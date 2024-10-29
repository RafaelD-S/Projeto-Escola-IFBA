#include "relatorios.h"

void pesquisarPessoas(rgInfoPessoa *alunos, rgInfoPessoa *prof) {
  system("clear");
  int temPessoa = false;
  for (int i = usuariosQtd - 1; i >= 0; i--) {
    if (alunos[i].matricula == 0 && prof[i].matricula == 0 )
      continue;

    else {
      temPessoa = true;
      break;
    }
  }

  if (!temPessoa) {
    printf("\n\nNÃO HÁ PESSOAS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {
    int existePessoa = false;
    char escolhaNome[nomeTamanho];

    while (true) {
      system("clear");
      printf("\n\nBuscar por (min 3 letras): ");
      fgets(escolhaNome, 30, stdin);

      for (int j = 97; j < 122; j++) {
        if (escolhaNome[0] == j) {
          escolhaNome[0] = escolhaNome[0] - 32;
          break;
        }
      }

      if (strlen(escolhaNome) > 3) {
        escolhaNome[strcspn(escolhaNome, "\n")] = '\0';
        break;
      
      }

      printf("\n\nBusca inválida. Tente novamente. \n(Aperte Enter para continuar)\n\n");
      getchar();
    }

    system("clear");
    for (int i = 0; i < usuariosQtd; i++) {
      char *encontradoAluno = strstr(alunos[i].nome, escolhaNome);
      if (encontradoAluno) {
        printf("- Discente: ");
        puts(alunos[i].nome);
        existePessoa = true;
      }

      char *encontradoProf = strstr(prof[i].nome, escolhaNome);
      if (encontradoProf) {
        printf("- Docente: ");
        puts(prof[i].nome);
        existePessoa = true;
      }
    }

    if (!existePessoa) {
      printf("\n\nNÃO HÁ PESSOAS COM ESSE NOME\n(Aperte Enter para continuar)\n\n");
      getchar();
    }
    else {
      printf("\n\n(Aperte Enter para continuar)\n\n");
      getchar();
    }
  }
}

