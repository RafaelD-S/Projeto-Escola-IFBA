#include "../school.h"
#include "../utils/validadores.h"

void registrarPessoas(rgInfoPessoa *pessoas) {
  
  int i = 0;
  for (; i < usuariosQtd; i++) {
    if (pessoas[i].matricula == 0)
      break;
  }

  while (true) {
    int jaTemMatricula = false;
    system("clear");
    printf("Informe a matrícula: ");
    scanf("%ld", &pessoas[i].matricula);
    getchar();

    if (validarMatricula(pessoas, i))
      break;
  }

  while (true) {
    system("clear");
    printf("Informe o nome: ");
    fgets(pessoas[i].nome, nomeTamanho, stdin);

    if (validarNome(pessoas, i))
      break;
  }

  while (true) {
    system("clear");
    printf("Informe o gênero [M / F /  N]: ");
    pessoas[i].sexo = getchar();

    if (validarGenero(pessoas, i)) {
      break;
    }
  }

  while (true) {
    system("clear");
    printf("Informe a data de nascimento [DDMMAAAA]: ");
    scanf("%d", &pessoas[i].dtNasc);
    getchar();

    if (validarDataDeNascimento(pessoas, i))
      break;
  }

  while (true) {
    system("clear");
    printf("Informe o cpf?: ");
    scanf("%ld", &pessoas[i].cpf);
    getchar();

  if (validarCpf(pessoas, i))
    break;
  }
}