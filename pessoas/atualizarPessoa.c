#include "../school.h"

void atualizarPessoas(rgInfoPessoa *pessoas) {
  if (listarPessoas(pessoas)) {
    int pessoaEscolhida;
    printf("\n\nEscreva o id da pessoa que você deseja atualizar: ");
    scanf("%d", &pessoaEscolhida);
    getchar();

    if (pessoas[pessoaEscolhida - 1].matricula == 0) {
      printf("\n\nEssa pessoa não está registrada \n(Aperte Enter para continuar)\n\n");
      getchar();
    } 
    else {
      system("clear");
      printf("ATUALIZAR ALUNO");
      const char *opcoes[] = {
          "Mudar a matrícula",
          "Mudar o nome",
          "Mudar o gênero",
          "Mudar a data de nascimento",
          "Mudar o CPF"
      };
      int escolhaAtualizarAluno = listarOpcoes(opcoes, 5);

      // Escolher uma nova matricula para um aluno escolhido
      if (escolhaAtualizarAluno == 1) {
        while (true) {
          int jaTemMatricula = false;
          system("clear");
          printf("\n\nInforme a nova matricula do aluno?: ");
          scanf("%d", &pessoas[pessoaEscolhida - 1].matricula);
          getchar();

          for (int j = usuariosQtd - 1; j >= 0; j--) {
            if (pessoas[j].matricula == pessoas[pessoaEscolhida - 1].matricula && pessoaEscolhida - 1 != j)
              jaTemMatricula = true;

            else
              continue;
          }

          if (jaTemMatricula && pessoas[pessoaEscolhida - 1].matricula != 0) {
            printf("\n\nJá existe um aluno com essa matricula. Tente novamente. \n(Aperte Enter para continuar)\n\n");
            getchar();
            continue;
          }

          if (pessoas[pessoaEscolhida - 1].matricula > 0)
            break;

          printf("Matricula inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
      }
      // Escolher um novo nome para um aluno escolhido
      else if (escolhaAtualizarAluno == 2) {
        while (true) {
          system("clear");
          printf("\n\nInforme o novo nome: ");
          fgets(pessoas[pessoaEscolhida - 1].nome, 30, stdin);

          // Capitalização do Aluno
          for (int j = 97; j < 122; j++) {
            if (pessoas[pessoaEscolhida - 1].nome[0] == j) {
              pessoas[pessoaEscolhida - 1].nome[0] = pessoas[pessoaEscolhida - 1].nome[0] - 32;
              break;
            }
          }

          if (strlen(pessoas[pessoaEscolhida - 1].nome) > 1)
            break;

          printf("Nome inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
      }
      // Escolher um novo genero para um aluno escolhido
      else if (escolhaAtualizarAluno == 3) {
        while (true) {
          system("clear");
          printf("\n\nEscolha o novo gênero: ");
          pessoas[pessoaEscolhida - 1].sexo = getchar();

          if (pessoas[pessoaEscolhida - 1].sexo == 'M' ||
              pessoas[pessoaEscolhida - 1].sexo == 'F' || 
              pessoas[pessoaEscolhida - 1].sexo == 'N')
            break;

          printf("Gênero inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
      }
      // Escolher uma nova data de nascimento para um aluno escolhido
      else if (escolhaAtualizarAluno == 4) {
        while (true) {
          system("clear");
          printf("\n\nEscolha a nova data de nascimento: ");
          scanf("%d", &pessoas[pessoaEscolhida - 1].dtNasc);
          getchar();

          if (pessoas[pessoaEscolhida - 1].dtNasc > 9999999 && pessoas[pessoaEscolhida - 1].dtNasc < 99999999)
            break;

          printf("Data de nascimento inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
      }
      // Escolher um novo cpf para um aluno escolhido
      else if (escolhaAtualizarAluno == 5) {
        while (true) {
          system("clear");
          printf("\n\nEscolha um novo cpf: ");
          scanf("%ld", &pessoas[pessoaEscolhida - 1].cpf);
          getchar();

          if (pessoas[pessoaEscolhida - 1].cpf > 9999999999 && pessoas[pessoaEscolhida - 1].cpf < 99999999999)
            break;

          printf("CPF inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
      }
    }
  }
}