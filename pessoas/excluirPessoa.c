#include "../school.h"

void excluirPessoas(rgInfoPessoa *pessoas, procedimentoMatricula *disciplina) {
  if (listarPessoas(pessoas)) {
    int pessoaExcluida;
    printf("\nQual pessoa você gostaria de remover? (selecione o id): ");
    scanf("%d", &pessoaExcluida);
    getchar();

    if (pessoas[pessoaExcluida - 1].matricula == 0) {
      printf("\n\nEssa pessoa não existe\n(Aperte Enter para continuar)\n\n");
      getchar();
    } else {
      // excluir a pessoa na disciplina
        for (int i = 0; i < disciplinaQtd; i++) {
          for (int j = 0; j < usuariosQtd; j++) {
            if (disciplina[i].alunos[j] == pessoas[pessoaExcluida - 1].matricula) {
              disciplina[i].alunos[j] = 0;
              break;
            }
            if (strcmp(disciplina[i].professor, pessoas[pessoaExcluida - 1].nome) == 0) {
              for (int k = 0; k < nomeTamanho; k++) {
                disciplina[i].professor[k] = '\0';
              }
              break;
            }
          }
        }
      
      pessoas[pessoaExcluida - 1].matricula = 0;
      printf("\n\nPessoa excluída com sucesso\n(Aperte Enter para continuar)\n\n");
      getchar();

      // reorganização da lista
      for (int j = pessoaExcluida - 1; j < usuariosQtd - 1; j++) {
        pessoas[j].matricula = pessoas[j + 1].matricula;
        strcpy(pessoas[j].nome, pessoas[j + 1].nome);
        pessoas[j].sexo = pessoas[j + 1].sexo;
        pessoas[j].dtNasc = pessoas[j + 1].dtNasc;
        pessoas[j].cpf = pessoas[j + 1].cpf;
      }

    }
  } else {
    printf("Não há pessoas disponíveis.\n(Aperte Enter para continuar)\n\n");
    getchar();
  }
}