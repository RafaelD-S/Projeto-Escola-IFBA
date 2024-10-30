#include "../school.h"
#include "./atualizacoes/atualizacoesModulos.h"

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
      printf("ATUALIZAR PESSOA");
      const char *opcoes[] = {
          "Mudar a matrícula",
          "Mudar o nome",
          "Mudar o gênero",
          "Mudar a data de nascimento",
          "Mudar o CPF"
      };
      int escolhaAtualizarPessoa = listarOpcoes(opcoes, 5);

      if (escolhaAtualizarPessoa == 1) {
        atualizarMatricula(pessoas, pessoaEscolhida);
      }
      else if (escolhaAtualizarPessoa == 2) {
        atualizarNome(pessoas, pessoaEscolhida);
      }
      else if (escolhaAtualizarPessoa == 3) {
        atualizarGenero(pessoas, pessoaEscolhida);
      }
      else if (escolhaAtualizarPessoa == 4) {
        atualizarDataDeNascimento(pessoas, pessoaEscolhida);
      }
      else if (escolhaAtualizarPessoa == 5) {
        atualizarCpf(pessoas, pessoaEscolhida);
      }
    }
  }
}