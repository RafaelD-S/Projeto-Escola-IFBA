#include "../school.h"

void registrarPessoas(rgInfoPessoa *pessoas) {
  
  int i = 0;
  for (; i < usuariosQtd; i++) {
    if (pessoas[i].matricula == 0)
      break;
  }

  while (true) {
    int jaTemMatricula = false;
    system("clear");
    printf("\n\nInforme a matrícula: ");
    scanf("%ld", &pessoas[i].matricula);
    getchar();

    for (int j = usuariosQtd - 1; j >= 0; j--) {
      if (pessoas[j].matricula == pessoas[i].matricula && i != j)
        jaTemMatricula = true;

      else 
        continue;
    }

    if (jaTemMatricula && pessoas[i].matricula != 0) {
      printf("\n\nJá existe alguém com essa matricula. Tente novamente. \n(Aperte Enter para continuar)\n\n");
      getchar();
      continue;
    }

    if (pessoas[i].matricula > 0)
      break;

    printf("Matricula inválida. Tente novamente. \n(Aperte Enter para continuar)\n\n");
    getchar();
  }

  while (true) {
    system("clear");
    printf("\n\nInforme o nome: ");
    fgets(pessoas[i].nome, 30, stdin);

    // Capitalização do Aluno
    for (int j = 97; j < 122; j++) {
      if (pessoas[i].nome[0] == j) {
        pessoas[i].nome[0] = pessoas[i].nome[0] - 32;
        break;
      }
    }

    if (strlen(pessoas[i].nome) > 1)
      break;

    printf("Nome inválido. Tente novamente. \n(Aperte Enter para continuar)\n\n");
    getchar();
  }

  while (true) {
    system("clear");
    printf("\n\nInforme o gênero [M / F /  N]: ");
    pessoas[i].sexo = getchar();

    if (pessoas[i].sexo == 'M' || pessoas[i].sexo == 'F' || pessoas[i].sexo == 'N')
      break;

    system("clear");
    printf("Gênero inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }

  while (true) {
    system("clear");
    printf("\n\nInforme a data de nascimento [DDMMAAAA]: ");
    scanf("%d", &pessoas[i].dtNasc);
    getchar();

    if (pessoas[i].dtNasc > 9999999 && pessoas[i].dtNasc < 99999999)
      break;

    printf("Data de nascimento inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }

  while (true) {
    system("clear");
    printf("\n\nInforme o cpf?: ");
    scanf("%ld", &pessoas[i].cpf);
    getchar();

    if (pessoas[i].cpf > 9999999999 && pessoas[i].cpf < 99999999999)
      break;

    printf("CPF inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}