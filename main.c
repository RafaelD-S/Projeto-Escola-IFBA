#include <stdio.h>
#include <stdlib.h>
#include <string.h> // função pra atribuir nome
#include <stdbool.h>
#define nomeTamanho 35
#define disciplinaQtd 50
#define usuariosQtd 100

int main() {

  struct rgInfoPessoa {
    int matricula;
    char nome[nomeTamanho];
    char sexo;
    int dtNasc;
    long int cpf;
  };

  struct procedimentoMatricula {
    char nome[nomeTamanho];
    int codigo = 0;
    int semestre;
    char professor[nomeTamanho];
  };

  struct rgInfoPessoa alunos[usuariosQtd] = {0};
  struct rgInfoPessoa prof[usuariosQtd] = {0};
  struct procedimentoMatricula disciplina[disciplinaQtd] = {0};

  char nome1[nomeTamanho] = "Rafael";     // Aluno
  char nome5[nomeTamanho] = "Luana";      // Aluno 2
  char nome2[nomeTamanho] = "Romilson";   // Professor 1
  char nome3[nomeTamanho] = "Magno";      // Professor 2
  char nome4[nomeTamanho] = "Matemática"; // disciplina

  // Exemplos de uso para não ter que gerar um novo todo teste
  alunos[0].matricula = 123;
  alunos[0].sexo = 'F';
  strcpy(alunos[0].nome, nome1); // nome do aluno
  alunos[0].dtNasc = 999999;
  alunos[0].cpf = 12345678912;

  alunos[1].matricula = 123;
  alunos[1].sexo = 'M';
  strcpy(alunos[1].nome, nome5); // nome do aluno
  alunos[1].dtNasc = 999999;
  alunos[1].cpf = 12345678912;

  // Professor 1
  prof[0].matricula = 123;
  prof[0].sexo = 'F';
  strcpy(prof[0].nome, nome2); // nome do professor 1
  prof[0].dtNasc = 999999;
  prof[0].cpf = 12345678912;

  // Professor 2
  prof[1].matricula = 123;
  prof[1].sexo = 'M';
  strcpy(prof[1].nome, nome3); // nome do professor 2
  prof[1].dtNasc = 999999;
  prof[1].cpf = 12345678912;

  strcpy(disciplina[0].nome, nome4); // nome da matéria
  disciplina[0].codigo = 2;
  disciplina[0].semestre = 1;
  strcpy(disciplina[0].professor, nome3); // nome do professor 2

  while (true) {
    system("clear");
    int escolha = 0;
    printf("Bem vindo ao Projeto Escola. Digite uma das seguintes opções:\n\n");
    printf("[1] - Cadastro de Alunos\n");
    printf("[2] - Cadastro de Professores\n");
    printf("[3] - Cadastro de Disciplinas\n");
    printf("[4] - Relatórios\n");
    printf("\nInsira qualquer outra tecla para finalizar\n");
    printf("\n=> ");
    scanf("%d", &escolha);
    getchar();

    // Cadastro de alunos
    if (escolha == 1) {
      while (true) {
        int escolhaAluno = 0;
        system("clear");
        printf("\nCADASTRO DE ALUNO");
        printf("\nEscolha o que deseja fazer:\n\n");
        printf("[1] - Incluir um novo aluno\n");
        printf("[2] - Exluir um aluno\n");
        printf("[3] - Atualizar algum aluno\n");
        printf("\nInsira qualquer outra tecla para voltar\n");
        printf("\n=> ");
        scanf("%d", &escolhaAluno);
        getchar();

        // Adionar um novo aluno
        if (escolhaAluno == 1) {
          int i = 0;
          for (; i < usuariosQtd; i++) {
            if (alunos[i].matricula == 0)
              break;
          }

          while (true) {
            int jaTemMatricula = 0;
            system("clear");
            printf("\n\nQual a matricula do aluno?: ");
            scanf("%d", &alunos[i].matricula);
            getchar();

            for (int j = usuariosQtd - 1; j >= 0; j--) {
              if (alunos[j].matricula == alunos[i].matricula && i != j)
                jaTemMatricula = 1;
              else {
                continue;
              }
            }
            if (jaTemMatricula && alunos[i].matricula != 0) {
              printf("\n\nJá existe um aluno com essa matricula. Tente "
                     "novamente. \n(Aperte Enter para continuar)\n\n");
              getchar();
              continue;
            }

            if (alunos[i].matricula > 0)
              break;

            printf("Matricula inválida. Tente novamente. \n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o nome do aluno?: ");
            fgets(alunos[i].nome, 30, stdin);

            // Capitalização do Aluno
            for (int j = 97; j < 122; j++) {
              if (alunos[i].nome[0] == j) {
                alunos[i].nome[0] = alunos[i].nome[0] - 32;
                break;
              }
            }

            if (strlen(alunos[i].nome) > 1)
              break;
            printf("Nome inválido. Tente novamente. \n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o gênero do aluno? [M / F /  N]: ");
            alunos[i].sexo = getchar();

            if (alunos[i].sexo == 'M' || alunos[i].sexo == 'F' ||
                alunos[i].sexo == 'N')
              break;
            system("clear");
            printf("Gênero inválido. Tente novamente.\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual a data de nascimento do aluno? [DDMMAAAA]: ");
            scanf("%d", &alunos[i].dtNasc);
            getchar();

            if (alunos[i].dtNasc > 9999999 && alunos[i].dtNasc < 99999999)
              break;
            printf("Data de nascimento inválida. Tente novamente.\n(Aperte "
                   "Enter para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o CPF do aluno?: ");
            scanf("%ld", &alunos[i].cpf);
            getchar();

            if (alunos[i].cpf > 9999999999 && alunos[i].cpf < 99999999999)
              break;
            printf("CPF inválido. Tente novamente.\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }
        }
        // Excluir um dos alunos
        else if (escolhaAluno == 2) {
          int temAluno = 0;
          system("clear");
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (alunos[i].matricula == 0)
              continue;
            else {
              temAluno = 1;
              printf("[%d] ", i + 1);
              puts(alunos[i].nome);
            }
          }
          if (!temAluno) {
            printf("\n\nNÃO HÁ ALUNOS PARA EXCLUIR\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            int alunoExcluido;
            printf("\nQual aluno você gostaria de remover? (selecione o id): ");
            scanf("%d", &alunoExcluido);
            getchar();

            if (alunos[alunoExcluido - 1].matricula == 0) {
              printf("\n\nEsse aluno não existe\n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              alunos[alunoExcluido - 1].matricula = 0;
              printf("\n\nAluno excluído com sucesso\n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            }
          }
        }
        // Atualizar algum aluno
        else if (escolhaAluno == 3) {
          int temAluno = 0;
          system("clear");
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (alunos[i].matricula == 0) {
              continue;
            } else {
              temAluno = 1;
              printf("[%d] ", i + 1);
              puts(alunos[i].nome);
            }
          }
          if (!temAluno) {
            printf("\n\nNÃO HÁ ALUNOS PARA ATUALIZAR\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            int alunoEscolhido;
            printf("\n\nQual aluno deseja atualizar: ");
            scanf("%d", &alunoEscolhido);
            getchar();

            if (alunos[alunoEscolhido - 1].matricula == 0) {
              printf("\n\nEsse aluno não existe \n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              int escolhaAtualizarAluno = 0;
              system("clear");
              printf("\nQue mudança deseja fazer:\n\n");

              printf("[1] - Mudar a matrícula\n");
              printf("[2] - Mudar o nome\n");
              printf("[3] - Mudar o gênero\n");
              printf("[4] - Mudar a data de nascimento\n");
              printf("[5] - Mudar o CPF\n");
              printf("\nInsira qualquer outra tecla para voltar\n");
              printf("\n=> ");
              scanf("%d", &escolhaAtualizarAluno);
              getchar();

              // Escolher uma nova matricula para um aluno escolhido
              if (escolhaAtualizarAluno == 1) {
                while (true) {
                  int jaTemMatricula = 0;
                  system("clear");
                  printf("\n\nInforme a nova matricula do aluno?: ");
                  scanf("%d", &alunos[alunoEscolhido - 1].matricula);
                  getchar();

                  for (int j = usuariosQtd - 1; j >= 0; j--) {
                    if (alunos[j].matricula ==
                            alunos[alunoEscolhido - 1].matricula &&
                        alunoEscolhido - 1 != j)
                      jaTemMatricula = 1;
                    else {
                      continue;
                    }
                  }
                  if (jaTemMatricula &&
                      alunos[alunoEscolhido - 1].matricula != 0) {
                    printf("\n\nJá existe um aluno com essa matricula. Tente "
                           "novamente. \n(Aperte Enter para continuar)\n\n");
                    getchar();
                    continue;
                  }

                  if (alunos[alunoEscolhido - 1].matricula > 0)
                    break;
                  printf("Matricula inválida. Tente novamente.\n(Aperte Enter "
                         "para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher um novo nome para um aluno escolhido
              else if (escolhaAtualizarAluno == 2) {
                while (true) {
                  system("clear");
                  printf("\n\nInforme o novo nome: ");
                  fgets(alunos[alunoEscolhido - 1].nome, 30, stdin);

                  // Capitalização do Aluno
                  for (int j = 97; j < 122; j++) {
                    if (alunos[alunoEscolhido - 1].nome[0] == j) {
                      alunos[alunoEscolhido - 1].nome[0] =
                          alunos[alunoEscolhido - 1].nome[0] - 32;
                      break;
                    }
                  }

                  if (strlen(alunos[alunoEscolhido - 1].nome) > 1)
                    break;
                  printf("Nome inválido. Tente novamente.\n(Aperte Enter para "
                         "continuar)\n\n");
                  getchar();
                }
              }
              // Escolher um novo genero para um aluno escolhido
              else if (escolhaAtualizarAluno == 3) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha o novo gênero: ");
                  alunos[alunoEscolhido - 1].sexo = getchar();

                  if (alunos[alunoEscolhido - 1].sexo == 'M' ||
                      alunos[alunoEscolhido - 1].sexo == 'F' ||
                      alunos[alunoEscolhido - 1].sexo == 'N')
                    break;
                  printf("Gênero inválido. Tente novamente.\n(Aperte Enter "
                         "para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher uma nova data de nascimento para um aluno escolhido
              else if (escolhaAtualizarAluno == 4) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha a nova data de nascimento: ");
                  scanf("%d", &alunos[alunoEscolhido - 1].dtNasc);
                  getchar();

                  if (alunos[alunoEscolhido - 1].dtNasc > 9999999 &&
                      alunos[alunoEscolhido - 1].dtNasc < 99999999)
                    break;
                  printf("Data de nascimento inválida. Tente "
                         "novamente.\n(Aperte Enter para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher um novo cpf para um aluno escolhido
              else if (escolhaAtualizarAluno == 5) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha um novo cpf: ");
                  scanf("%ld", &alunos[alunoEscolhido - 1].cpf);
                  getchar();

                  if (alunos[alunoEscolhido - 1].cpf > 9999999999 &&
                      alunos[alunoEscolhido - 1].cpf < 99999999999)
                    break;
                  printf("CPF inválido. Tente novamente.\n(Aperte Enter para "
                         "continuar)\n\n");
                  getchar();
                }
              }
            }
          }
        } else
          break;
      }
    }
    // Cadastro de professor
    else if (escolha == 2) {
      while (true) {
        int escolhaProf = 0;
        system("clear");
        printf("\nCADASTRO DE PROFESSOR");
        printf("\nEscolha o que deseja fazer:\n\n");
        printf("[1] - Incluir um novo professor\n");
        printf("[2] - Exluir um professor\n");
        printf("[3] - Atualizar algum professor\n");
        printf("\nInsira qualquer outra tecla para voltar\n");
        printf("\n=> ");
        scanf("%d", &escolhaProf);
        getchar();

        // Adionar um novo professor
        if (escolhaProf == 1) {
          int i = 0;
          for (; i < usuariosQtd; i++) {
            if (prof[i].matricula == 0)
              break;
          }

          while (true) {
            system("clear");
            printf("\n\nQual a matricula do professor?: ");
            scanf("%d", &prof[i].matricula);
            getchar();

            int jaTemMatricula = 0;
            for (int j = usuariosQtd - 1; j >= 0; j--) {
              if (prof[j].matricula == prof[i].matricula && i != j)
                jaTemMatricula = 1;
              else {
                continue;
              }
            }

            if (jaTemMatricula && prof[i].matricula != 0) {
              printf("\n\nJá existe um professor com essa matricula. Tente "
                     "novamente. \n(Aperte Enter para continuar)\n\n");
              getchar();
              continue;
            }

            if (prof[i].matricula > 0)
              break;
            printf("Matricula inválida. Tente novamente.\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o nome do professor?: ");
            fgets(prof[i].nome, 30, stdin);

            // Capitalização do Professor
            for (int j = 97; j < 122; j++) {
              if (prof[i].nome[0] == j) {
                prof[i].nome[0] = prof[i].nome[0] - 32;
                break;
              }
            }

            if (strlen(prof[i].nome) > 1)
              break;
            printf("Nome inválido. Tente novamente.\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o gênero do professor? [M / F /  N]: ");
            prof[i].sexo = getchar();

            if (prof[i].sexo == 'M' || prof[i].sexo == 'F' ||
                prof[i].sexo == 'N')
              break;
            printf("Gênero inválido. Tente novamente.\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual a data de nascimento do professor? [DDMMAAAA]: ");
            scanf("%d", &prof[i].dtNasc);
            getchar();

            if (prof[i].dtNasc > 9999999 && prof[i].dtNasc < 99999999)
              break;
            printf("Data de nascimento inválida. Tente novamente.\n( Enter "
                   "para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o CPF do professor?: ");
            scanf("%ld", &prof[i].cpf);
            getchar();

            if (prof[i].cpf > 9999999999 && prof[i].cpf < 99999999999)
              break;
            printf("CPF inválido. Tente novamente.\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }
        }
        // Excluir um dos professores
        else if (escolhaProf == 2) {
          int temProf = 0;
          system("clear");
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (prof[i].matricula == 0)
              continue;
            else {
              temProf = 1;
              printf("[%d] ", i + 1);
              puts(prof[i].nome);
            }
          }
          if (!temProf) {
            printf("\n\nNÃO HÁ PROFESSORES PARA EXCLUIR \n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            int profExcluido;
            printf("\nQual professor você gostaria de remover? (selecione o "
                   "id): ");
            scanf("%d", &profExcluido);
            getchar();

            if (prof[profExcluido - 1].matricula == 0) {
              printf("\n\nEsse professor não existe \n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              prof[profExcluido - 1].matricula = 0;
              printf("\n\nProfessor excluído com sucesso \n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            }
          }
        }
        // Atualizar algum professor
        else if (escolhaProf == 3) {
          int temProf = 0;
          system("clear");
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (prof[i].matricula == 0) {
              continue;
            } else {
              temProf = 1;
              printf("[%d] ", i + 1);
              puts(prof[i].nome);
            }
          }
          if (!temProf) {
            printf("\n\nNÃO HÁ PROFESSORES PARA ATUALIZAR \n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            int profEscolhido;
            printf("\n\nQual professor deseja atualizar: ");
            scanf("%d", &profEscolhido);
            getchar();

            if (prof[profEscolhido - 1].matricula == 0) {
              printf("\n\nEsse professor não existe \n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              int escolhaAtualizarProf = 0;
              system("clear");
              printf("\nQue mudança deseja fazer:\n\n");

              printf("[1] - Mudar a matrícula\n");
              printf("[2] - Mudar o nome\n");
              printf("[3] - Mudar o gênero\n");
              printf("[4] - Mudar a data de nascimento\n");
              printf("[5] - Mudar o CPF\n");
              printf("\nInsira qualquer outra tecla para voltar\n");
              printf("\n=> ");
              scanf("%d", &escolhaAtualizarProf);
              getchar();

              // Escolher uma nova matricula para um professor escolhido
              if (escolhaAtualizarProf == 1) {
                while (true) {
                  int jaTemMatricula = 0;
                  system("clear");
                  printf("\n\nInforme a nova matricula do professor?: ");
                  scanf("%d", &prof[profEscolhido - 1].matricula);
                  getchar();

                  for (int j = usuariosQtd - 1; j >= 0; j--) {
                    if (prof[j].matricula ==
                            prof[profEscolhido - 1].matricula &&
                        profEscolhido - 1 != j)
                      jaTemMatricula = 1;
                    else {
                      continue;
                    }
                  }
                  if (jaTemMatricula &&
                      prof[profEscolhido - 1].matricula != 0) {
                    printf(
                        "\n\nJá existe um professor com essa matricula. Tente "
                        "novamente. \n(Aperte Enter para continuar)\n\n");
                    getchar();
                    continue;
                  }

                  if (prof[profEscolhido - 1].matricula > 0)
                    break;
                  printf("Matricula inválida. Tente novamente.\n(Aperte Enter "
                         "para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher um novo nome para um professor escolhido
              else if (escolhaAtualizarProf == 2) {
                while (true) {
                  system("clear");
                  printf("\n\nInforme o novo nome: ");
                  fgets(prof[profEscolhido - 1].nome, 30, stdin);

                  // Capitalização do Professor
                  for (int j = 97; j < 122; j++) {
                    if (prof[profEscolhido - 1].nome[0] == j) {
                      prof[profEscolhido - 1].nome[0] =
                          prof[profEscolhido - 1].nome[0] - 32;
                      break;
                    }
                  }

                  if (strlen(prof[profEscolhido - 1].nome) > 1)
                    break;
                  printf("Nome inválido. Tente novamente.\n(Aperte Enter para "
                         "continuar)\n\n");
                  getchar();
                }
              }
              // Escolher um novo genero para um professor escolhido
              else if (escolhaAtualizarProf == 3) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha o novo gênero: ");
                  prof[profEscolhido - 1].sexo = getchar();

                  if (prof[profEscolhido - 1].sexo == 'M' ||
                      prof[profEscolhido - 1].sexo == 'F' ||
                      prof[profEscolhido - 1].sexo == 'N')
                    break;
                  printf("Gênero inválido. Tente novamente.\n(Aperte Enter "
                         "para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher uma nova data de nascimento para um professor
              // escolhido
              else if (escolhaAtualizarProf == 4) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha a nova data de nascimento: ");
                  scanf("%d", &prof[profEscolhido - 1].dtNasc);
                  getchar();

                  if (prof[profEscolhido - 1].dtNasc > 9999999 &&
                      prof[profEscolhido - 1].dtNasc < 99999999)
                    break;
                  printf("Data de nascimento inválida. Tente "
                         "novamente.\n(Aperte Enter para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher um novo cpf para um professor escolhido
              else if (escolhaAtualizarProf == 5) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha um novo cpf: ");
                  scanf("%ld", &prof[profEscolhido - 1].cpf);
                  getchar();

                  if (prof[profEscolhido - 1].cpf > 9999999999 &&
                      prof[profEscolhido - 1].cpf < 99999999999)
                    break;
                  printf("CPF inválido. Tente novamente.\n(Aperte Enter para "
                         "continuar)\n\n");
                  getchar();
                }
              }
            }
          }
        } else
          break;
      }
    }
    // Cadastro de disciplina
    else if (escolha == 3) {
      while (true) {
        int escolhaDisciplina = 0;
        system("clear");
        printf("\nCADASTRO DE DISCIPLINA");
        printf("\nEscolha o que deseja fazer:\n\n");
        printf("[1] - Incluir uma nova disciplina\n");
        printf("[2] - Exluir uma disciplina\n");
        printf("[3] - Atualizar alguma disciplina\n");
        printf("\nInsira qualquer outra tecla para voltar\n");
        printf("\n=> ");
        scanf("%d", &escolhaDisciplina);
        getchar();

        // Cadastro de uma nova disciplina
        if (escolhaDisciplina == 1) {
          int i = 0;
          for (; i <= disciplinaQtd; i++) {
            if (disciplina[i].codigo == 0)
              break;
          }

          system("clear");
          printf("\n\nQual o nome da disciplina?: ");
          fgets(disciplina[i].nome, 30, stdin);

          // Capitalização da Disciplina
          for (int j = 97; j < 122; j++) {
            if (disciplina[i].nome[0] == j) {
              disciplina[i].nome[0] = disciplina[i].nome[0] - 32;
              break;
            }
          }

          // verificação e cadastro do código da disciplina
           while (true) {
            system("clear");
            printf("\n\nQual o código da disciplina?: ");
            scanf("%d", &disciplina[i].codigo);
            getchar();
          
            int jaTemDisciplina = 0;
            for (int j = disciplinaQtd - 1; j >= 0; j--) {
              if (disciplina[j].codigo == disciplina[i].codigo && i != j)
                jaTemDisciplina = 1;
              else {
                continue;
              }
            }

            if (jaTemDisciplina && disciplina[i].codigo != 0) {
              printf("\n\nJá existe uma disciplina com esse código. Tente "
                     "novamente. \n(Aperte Enter para continuar)\n\n");
              getchar();
              continue;
            }

            if (disciplina[i].codigo > 0)
              break;
            
            printf("Código inválido. Tente novamente.\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }

          system("clear");
          printf("\n\nQual o semestre da disciplina? [Insira apenas o numero]: ");
          scanf("%d", &disciplina[i].semestre);
          getchar();

          // Cadastro do professor na disciplina
          system("clear");
          int temProf = 0;
          for (int j = usuariosQtd - 1; j >= 0; j--) {
            if (prof[j].matricula == 0) {
              continue;
            } else {
              temProf = 1;
              printf("[%d] ", j + 1);
              puts(prof[j].nome);
            }
          }

          if (!temProf) {
            printf("\n\nNÃO HÁ PROFESSORES PARA SELECIONAR \n(Aperte Enter "
                   "para continuar)\n\n");
            getchar();
          } else {
            int profSelecionado;
            printf("\n\nQual o nome do professor da disciplina? (selecione o "
                   "id): ");
            scanf("%d", &profSelecionado);
            getchar();

            if (prof[profSelecionado - 1].matricula == 0) {
              printf("\n\nEsse professor não existe \n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              for (int j = 0; j < nomeTamanho; j++) {
                disciplina[i].professor[j] = prof[profSelecionado - 1].nome[j];
              }
            }
          }
        }

        // Excluir uma disciplina existente
        else if (escolhaDisciplina == 2) {
          int temDisciplina = 0;
          system("clear");
          for (int i = disciplinaQtd - 1; i >= 0; i--) {
            if (disciplina[i].codigo == 0)
              continue;
            else {
              temDisciplina = 1;
              printf("[%d] ", i + 1);
              puts(disciplina[i].nome);
            }
          }

          if (!temDisciplina) {
            printf("\n\nNÃO HÁ DISCIPLINAS PARA EXCLUIR\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            int disciplinaExcluida;
            printf("\nQual disciplina você gostaria de remover? (selecione o "
                   "id): ");
            scanf("%d", &disciplinaExcluida);
            getchar();

            if (disciplina[disciplinaExcluida - 1].codigo == 0 || disciplinaExcluida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
              printf("\n\nEssa disciplina não existe\n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              disciplina[disciplinaExcluida - 1].codigo = 0;
              printf("\n\nDisciplina excluída com sucesso\n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            }
          }
        }
        
        // Atualizar alguma disciplina
        else if (escolhaDisciplina == 3) {
          int temDisciplina = 0;
          system("clear");
          for (int i = disciplinaQtd - 1; i >= 0; i--) {
            if (disciplina[i].codigo == 0)
              continue;
            else {
              temDisciplina = 1;
              printf("[%d] ", i + 1);
              puts(disciplina[i].nome);
            }
          }

          if (!temDisciplina) {
            printf("\n\nNÃO HÁ DISCIPLINAS PARA ATUALIZAR\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            int disciplinaEscolhida;
            printf("\n\nQual disciplina deseja atualizar: ");
            scanf("%d", &disciplinaEscolhida);
            getchar();

            if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
              printf("\n\nEssa disciplina não existe\n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              int escolhaAtualizarDisciplina = 0;
              system("clear");
              printf("\nQue mudança deseja fazer:\n\n");

              printf("[1] - Mudar o nome\n");
              printf("[2] - Mudar o código\n");
              printf("[3] - Mudar o semestre\n");
              printf("[4] - Mudar o nome do professor\n");
              printf("\nInsira qualquer outra tecla para voltar\n");
              printf("\n=> ");
              scanf("%d", &escolhaAtualizarDisciplina);
              getchar();

              // Escolher um novo nome para uma disciplina
              if (escolhaAtualizarDisciplina == 1) {
                system("clear");
                printf("Informe o novo nome para a disciplina: ");
                fgets(disciplina[disciplinaEscolhida - 1].nome, 30, stdin);

                // Capitalização da Disciplina
                for (int j = 97; j < 122; j++) {
                  if (disciplina[disciplinaEscolhida - 1].nome[0] == j) {
                    disciplina[disciplinaEscolhida - 1].nome[0] =
                        disciplina[disciplinaEscolhida - 1].nome[0] - 32;
                    break;
                  }
                }
              }
              // Escolher um novo código para a disciplina
              else if (escolhaAtualizarDisciplina == 2) {
                 int i = 0;
                 for (; i <= disciplinaQtd; i++) {
                     if (disciplina[i].codigo == 0)
                     break;
                 }
                 
                 while (true) {
                    system("clear");
                    printf("\n\nQual o código da disciplina?: ");
                    scanf("%d", &disciplina[i].codigo);
                    getchar();
          
                    int jaTemDisciplina = 0;
                    for (int j = disciplinaQtd - 1; j >= 0; j--) {
                      if (disciplina[j].codigo == disciplina[i].codigo && i != j)
                        jaTemDisciplina = 1;
                      else {
                        continue;
                      }
                    }
        
                    if (jaTemDisciplina && disciplina[i].codigo != 0) {
                      printf("\n\nJá existe uma disciplina com esse código. Tente "
                             "novamente. \n(Aperte Enter para continuar)\n\n");
                      getchar();
                      continue;
                    }
        
                    if (disciplina[i].codigo > 0)
                      break;
                    
                    printf("Código inválido. Tente novamente.\n(Aperte Enter para "
                           "continuar)\n\n");
                    getchar();
                 }
              }
              // Escolher um novo semestre para a disciplina
              else if (escolhaAtualizarDisciplina == 3) {
                system("clear");
                printf("Informe o novo semestre [Insira apenas numeros]: ");
                scanf("%d", &disciplina[disciplinaEscolhida - 1].semestre);
                getchar();
              }
              // Escolher um novo nome para o professor da disciplina
              else if (escolhaAtualizarDisciplina == 4) {
                system("clear");
                int temProf = 0;
                for (int j = usuariosQtd - 1; j >= 0; j--) {
                  if (prof[j].matricula == 0) {
                    continue;
                  } else {
                    temProf = 1;
                    printf("[%d] ", j + 1);
                    puts(prof[j].nome);
                  }
                }

                if (!temProf) {
                  printf("\n\nNÃO HÁ PROFESSORES PARA SELECIONAR\n(Aperte "
                         "Enter para continuar)\n\n");
                  getchar();
                } else {
                  int profSelecionado;
                  printf("\n\nInforme o nome do novo professor da disciplina "
                         "(selecione o id): ");
                  scanf("%d", &profSelecionado);
                  getchar();

                  if (prof[profSelecionado - 1].matricula == 0) {
                    printf("\n\nEsse professor não existe\n(Aperte Enter para "
                           "continuar)\n\n");
                    getchar();
                  } else {
                    for (int j = 0; j < nomeTamanho; j++) {
                      disciplina[disciplinaEscolhida - 1].professor[j] =
                          prof[profSelecionado - 1].nome[j];
                    }
                  }
                }
              }
            }
          }
        } else
          break;
      }
    }
    // Relatórios
    else if (escolha == 4) {
      while (true) {

        system("clear");
        int escolhaRelatorio = 0;
        printf("\nRELATÓRIO");
        printf("\nDigite uma das seguintes opções:\n\n");
        printf("[1] - Listar todos os alunos\n");             // Rafael X
        printf("[2] - Listar todos os professores\n");        // Rafael X
        printf("[3] - Listar todas as disciplinas\n");        // Luana
        printf("[4] - Listar uma disciplina com detalhes\n"); // Luana
        printf("[5] - Listar alunos por gênero\n");           // Rafael X
        printf("[6] - Listar alunos ordenados por nome\n");   // Rafael
        printf(
            "[7] - Listar alunos ordenados por data de nascimento\n"); // Rafael
        printf("[8] - Listar professores por gênero\n");               // Rafael X
        printf("[9] - Listar professores ordenados por nome\n");       // Rafael
        printf(
            "[10] - Listar professores ordenados por data de nascimento\n"); // Rafael
        printf("[11] - Listar aniversariantes do mês\n"); // Luana
        printf("[12] - Pesquisar pesssoas\n");            // Rafael
        printf(
            "[13] - Listar alunos matriculados em menos de 3 disciplinas\n"); // Luana
        printf("[14] - Listar disciplinas que extrapolam 40 vagas\n"); // Luana
        printf("\nInsira qualquer outra tecla para finalizar\n");
        printf("\n=> ");
        scanf("%d", &escolhaRelatorio);
        getchar();

        // Listar todos os alunos
        if (escolhaRelatorio == 1) {
          int temAluno = 0;
          system("clear");
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (alunos[i].matricula == 0)
              continue;
            else {
              temAluno = 1;
              printf("[%d] ", i + 1);
              puts(alunos[i].nome);
            }
          }
          if (!temAluno) {
            printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }
          printf("\n\nAlunos listados com sucessos\n(Aperte Enter para "
                 "continuar)\n\n");
          getchar();
        }
        // Listar todos os professores
        else if (escolhaRelatorio == 2) {
          int temProfessor = 0;
          system("clear");
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (prof[i].matricula == 0)
              continue;
            else {
              temProfessor = 1;
              printf("[%d] ", i + 1);
              puts(prof[i].nome);
            }
          }
          if (!temProfessor) {
            printf("\n\nNÃO HÁ PROFESSORES DISPONÍVEIS\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          }
          printf("\n\nProfessores listados com sucessos\n(Aperte Enter para "
                 "continuar)\n\n");
          getchar();
        }
        // Listar todas as disciplinas
        else if (escolhaRelatorio == 3) {
          printf("%d", escolhaRelatorio);
        }
        // Listar uma disciplina com detalhes
        else if (escolhaRelatorio == 4) {
          printf("%d", escolhaRelatorio);
        }
        // Listar alunos por gênero
        else if (escolhaRelatorio == 5) {
          system("clear");
          int temAluno = 0;
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (alunos[i].matricula == 0)
              continue;
            else {
              temAluno = 1;
            }
          }

          if (!temAluno) {
            printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            printf("\nAlunos do gênero Masculino");
            for (int i = usuariosQtd - 1; i >= 0; i--) {
              if (alunos[i].matricula == 0)
                continue;
              else if (alunos[i].sexo == 'M') {
                printf("\n- ");
                puts(alunos[i].nome);
              }
            }

            printf("\nAlunos do gênero Feminino");
            for (int i = usuariosQtd - 1; i >= 0; i--) {
              if (alunos[i].matricula == 0)
                continue;
              else if (alunos[i].sexo == 'F') {
                printf("\n- ");
                puts(alunos[i].nome);
              }
            }

            printf("\nAlunos que desejaram não informar");
            for (int i = usuariosQtd - 1; i >= 0; i--) {
              if (alunos[i].matricula == 0)
                continue;
              else if (alunos[i].sexo == 'N') {
                printf("\n-");
                puts(alunos[i].nome);
              }
            }
          }
          printf("\n\n\n(Aperte Enter para continuar)");
          getchar();
        }
        // Listar alunos ordenados por nome
        else if (escolhaRelatorio == 6) {
          printf("%d", escolhaRelatorio);
        }
        // Listar alunos ordenados por data de nascimento
        else if (escolhaRelatorio == 7) {
          printf("%d", escolhaRelatorio);
        }
        // Listar professores por gênero
        else if (escolhaRelatorio == 8) {
          system("clear");
          int temProfessor = 0;
          for (int i = usuariosQtd - 1; i >= 0; i--) {
            if (prof[i].matricula == 0)
              continue;
            else {
              temProfessor = 1;
            }
          }

          if (!temProfessor) {
            printf("\n\nNÃO HÁ PROFESSORES DISPONÍVEIS\n(Aperte Enter para "
                   "continuar)\n\n");
            getchar();
          } else {
            printf("\nProfessores do gênero Masculino");
            for (int i = usuariosQtd - 1; i >= 0; i--) {
              if (prof[i].matricula == 0)
                continue;
              else if (prof[i].sexo == 'M') {
                printf("\n- ");
                puts(prof[i].nome);
              }
            }

            printf("\nProfessores do gênero Feminino");
            for (int i = usuariosQtd - 1; i >= 0; i--) {
              if (prof[i].matricula == 0)
                continue;
              else if (prof[i].sexo == 'F') {
                printf("\n- ");
                puts(prof[i].nome);
              }
            }

            printf("\nProfessores que desejaram não informar");
            for (int i = usuariosQtd - 1; i >= 0; i--) {
              if (prof[i].matricula == 0)
                continue;
              else if (prof[i].sexo == 'N') {
                printf("\n-");
                puts(prof[i].nome);
              }
            }
          }
          printf("\n\n\n(Aperte Enter para continuar)");
          getchar();
        }
        // Listar professores ordenados por nome
        else if (escolhaRelatorio == 9) {
          printf("%d", escolhaRelatorio);
        }
        // Listar professores ordenados por data de nascimento
        else if (escolhaRelatorio == 10) {
          printf("%d", escolhaRelatorio);
        }
        // Listar aniversariantes do mês
        else if (escolhaRelatorio == 11) {
          printf("%d", escolhaRelatorio);
        }
        // Pesquisar pesssoas
        else if (escolhaRelatorio == 12) {
          printf("%d", escolhaRelatorio);
        }
        // Listar alunos matriculados em menos de 3 disciplinas
        else if (escolhaRelatorio == 13) {
          printf("%d", escolhaRelatorio);
        }
        // Listar disciplinas que extrapolam 40 vagas
        else if (escolhaRelatorio == 14) {
          printf("%d", escolhaRelatorio);
        } else {
          break;
        }
      }
    } else {
      printf("Finalizado");
      break;
    }
  }
}