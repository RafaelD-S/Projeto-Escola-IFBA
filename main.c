#include "school.h"

int main() {

  rgInfoPessoa alunos[usuariosQtd] = {0};
  rgInfoPessoa prof[usuariosQtd] = {0};
  struct procedimentoMatricula disciplina[disciplinaQtd] = {0};

  char nome1[nomeTamanho] = "Rafael";     // Aluno
  char nome5[nomeTamanho] = "Luana";      // Aluno 2
  char nome2[nomeTamanho] = "Romilson";   // Professor 1
  char nome3[nomeTamanho] = "Magno";      // Professor 2
  char nome4[nomeTamanho] = "Matemática"; // disciplina
  char nome6[nomeTamanho] = "Lógica de Programação"; // disciplina 2

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

  strcpy(disciplina[1].nome, nome6); // nome da matéria
  disciplina[1].codigo = 1;
  disciplina[1].semestre = 1;
  strcpy(disciplina[1].professor, nome2); // nome do professor 2

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
            int jaTemMatricula = false;
            system("clear");
            printf("\n\nQual a matricula do aluno?: ");
            scanf("%d", &alunos[i].matricula);
            getchar();

            for (int j = usuariosQtd - 1; j >= 0; j--) {
              if (alunos[j].matricula == alunos[i].matricula && i != j)
                jaTemMatricula = true;

              else 
                continue;
            }

            if (jaTemMatricula && alunos[i].matricula != 0) {
              printf("\n\nJá existe um aluno com essa matricula. Tente novamente. \n(Aperte Enter para continuar)\n\n");
              getchar();
              continue;
            }

            if (alunos[i].matricula > 0)
              break;

            printf("Matricula inválida. Tente novamente. \n(Aperte Enter para continuar)\n\n");
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

            printf("Nome inválido. Tente novamente. \n(Aperte Enter para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o gênero do aluno? [M / F /  N]: ");
            alunos[i].sexo = getchar();

            if (alunos[i].sexo == 'M' || alunos[i].sexo == 'F' || alunos[i].sexo == 'N')
              break;

            system("clear");
            printf("Gênero inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual a data de nascimento do aluno? [DDMMAAAA]: ");
            scanf("%d", &alunos[i].dtNasc);
            getchar();

            if (alunos[i].dtNasc > 9999999 && alunos[i].dtNasc < 99999999)
              break;

            printf("Data de nascimento inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o CPF do aluno?: ");
            scanf("%ld", &alunos[i].cpf);
            getchar();

            if (alunos[i].cpf > 9999999999 && alunos[i].cpf < 99999999999)
              break;

            printf("CPF inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
        }
        // Excluir um dos alunos
        else if (escolhaAluno == 2) {
          if (listaPessoas(alunos)) {
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
          } else {
            printf(
                "Não foi há alunos disponíveis. (Aperte Enter para continuar)");
            getchar();
          }
        }
        // Atualizar algum aluno
        else if (escolhaAluno == 3) {
          if (listaPessoas(alunos)) {
            int alunoEscolhido;
            printf("\n\nQual aluno deseja atualizar: ");
            scanf("%d", &alunoEscolhido);
            getchar();

            if (alunos[alunoEscolhido - 1].matricula == 0) {
              printf("\n\nEsse aluno não existe \n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              int escolhaAtualizarAluno;

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
                  int jaTemMatricula = false;
                  system("clear");
                  printf("\n\nInforme a nova matricula do aluno?: ");
                  scanf("%d", &alunos[alunoEscolhido - 1].matricula);
                  getchar();

                  for (int j = usuariosQtd - 1; j >= 0; j--) {
                    if (alunos[j].matricula == alunos[alunoEscolhido - 1].matricula && alunoEscolhido - 1 != j)
                      jaTemMatricula = true;

                    else
                      continue;
                  }

                  if (jaTemMatricula && alunos[alunoEscolhido - 1].matricula != 0) {
                    printf("\n\nJá existe um aluno com essa matricula. Tente novamente. \n(Aperte Enter para continuar)\n\n");
                    getchar();
                    continue;
                  }

                  if (alunos[alunoEscolhido - 1].matricula > 0)
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
                  fgets(alunos[alunoEscolhido - 1].nome, 30, stdin);

                  // Capitalização do Aluno
                  for (int j = 97; j < 122; j++) {
                    if (alunos[alunoEscolhido - 1].nome[0] == j) {
                      alunos[alunoEscolhido - 1].nome[0] = alunos[alunoEscolhido - 1].nome[0] - 32;
                      break;
                    }
                  }

                  if (strlen(alunos[alunoEscolhido - 1].nome) > 1)
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
                  alunos[alunoEscolhido - 1].sexo = getchar();

                  if (alunos[alunoEscolhido - 1].sexo == 'M' || alunos[alunoEscolhido - 1].sexo == 'F' || alunos[alunoEscolhido - 1].sexo == 'N')
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
                  scanf("%d", &alunos[alunoEscolhido - 1].dtNasc);
                  getchar();

                  if (alunos[alunoEscolhido - 1].dtNasc > 9999999 && alunos[alunoEscolhido - 1].dtNasc < 99999999)
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
                  scanf("%ld", &alunos[alunoEscolhido - 1].cpf);
                  getchar();

                  if (alunos[alunoEscolhido - 1].cpf > 9999999999 && alunos[alunoEscolhido - 1].cpf < 99999999999)
                    break;

                  printf("CPF inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
                  getchar();
                }
              }
            }
          }
        } 
        else
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

            int jaTemMatricula = false;
            for (int j = usuariosQtd - 1; j >= 0; j--) {
              if (prof[j].matricula == prof[i].matricula && i != j)
                jaTemMatricula = true;

              else
                continue;
            }

            if (jaTemMatricula && prof[i].matricula != 0) {
              printf("\n\nJá existe um professor com essa matricula. Tente novamente. \n(Aperte Enter para continuar)\n\n");
              getchar();
              continue;
            }

            if (prof[i].matricula > 0)
              break;

            printf("Matricula inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
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

            printf("Nome inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o gênero do professor? [M / F /  N]: ");
            prof[i].sexo = getchar();

            if (prof[i].sexo == 'M' || prof[i].sexo == 'F' || prof[i].sexo == 'N')
              break;

            printf("Gênero inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual a data de nascimento do professor? [DDMMAAAA]: ");
            scanf("%d", &prof[i].dtNasc);
            getchar();

            if (prof[i].dtNasc > 9999999 && prof[i].dtNasc < 99999999)
              break;

            printf("Data de nascimento inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
            getchar();
          }

          while (true) {
            system("clear");
            printf("\n\nQual o CPF do professor?: ");
            scanf("%ld", &prof[i].cpf);
            getchar();

            if (prof[i].cpf > 9999999999 && prof[i].cpf < 99999999999)
              break;

            printf("CPF inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
        }
        // Excluir um dos professores
        else if (escolhaProf == 2) {
          if (listaPessoas(prof)) {
            int profExcluido;
            printf("\nQual Professor você gostaria de remover? (selecione o id): ");
            scanf("%d", &profExcluido);
            getchar();

            if (prof[profExcluido - 1].matricula == 0) {
              printf("\n\nEsse Professor não existe\n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            } else {
              prof[profExcluido - 1].matricula = 0;
              printf("\n\nProfessor excluído com sucesso\n(Aperte Enter para "
                     "continuar)\n\n");
              getchar();
            }
          } else {
            printf(
                "Não foi há Professor disponíveis. (Aperte Enter para continuar)");
            getchar();
          }
        }
        // Atualizar algum professor
        else if (escolhaProf == 3) {
          if (listaPessoas(prof)) {
            int profEscolhido;
            printf("\n\nQual professor deseja atualizar: ");
            scanf("%d", &profEscolhido);
            getchar();

            if (prof[profEscolhido - 1].matricula == 0) {
              printf("\n\nEsse professor não existe \n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              int escolhaAtualizarProf;
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
                  int jaTemMatricula = false;
                  system("clear");
                  printf("\n\nInforme a nova matricula do professor?: ");
                  scanf("%d", &prof[profEscolhido - 1].matricula);
                  getchar();

                  for (int j = usuariosQtd - 1; j >= 0; j--) {
                    if (prof[j].matricula == prof[profEscolhido - 1].matricula && profEscolhido - 1 != j)
                      jaTemMatricula = true;

                    else
                      continue;
                  }

                  if (jaTemMatricula && prof[profEscolhido - 1].matricula != 0) {
                    printf("\n\nJá existe um professor com essa matricula. Tente novamente. \n(Aperte Enter para continuar)\n\n");
                    getchar();
                    continue;
                  }

                  if (prof[profEscolhido - 1].matricula > 0)
                    break;

                  printf("Matricula inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
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
                      prof[profEscolhido - 1].nome[0] = prof[profEscolhido - 1].nome[0] - 32;
                      break;
                    }
                  }

                  if (strlen(prof[profEscolhido - 1].nome) > 1)
                    break;

                  printf("Nome inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher um novo genero para um professor escolhido
              else if (escolhaAtualizarProf == 3) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha o novo gênero: ");
                  prof[profEscolhido - 1].sexo = getchar();

                  if (prof[profEscolhido - 1].sexo == 'M' || prof[profEscolhido - 1].sexo == 'F' || prof[profEscolhido - 1].sexo == 'N')
                    break;

                  printf("Gênero inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
                  getchar();
                }
              }
              // Escolher uma nova data de nascimento para um professor escolhido
              else if (escolhaAtualizarProf == 4) {
                while (true) {
                  system("clear");
                  printf("\n\nEscolha a nova data de nascimento: ");
                  scanf("%d", &prof[profEscolhido - 1].dtNasc);
                  getchar();

                  if (prof[profEscolhido - 1].dtNasc > 9999999 && prof[profEscolhido - 1].dtNasc < 99999999)
                    break;

                  printf("Data de nascimento inválida. Tente novamente.\n(Aperte Enter para continuar)\n\n");
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

                  if (prof[profEscolhido - 1].cpf > 9999999999 && prof[profEscolhido - 1].cpf < 99999999999)
                    break;

                  printf("CPF inválido. Tente novamente.\n(Aperte Enter para continuar)\n\n");
                  getchar();
                }
              }
            }
          }
        } 
        else
          break;
      }
    }
    // Cadastro de disciplina
    else if (escolha == 3) {
      while (true) {
        int escolhaDisciplina;
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

          // verificação e cadastro do nome da disciplina
          while (true) {
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
        // Excluir uma disciplina existente
        else if (escolhaDisciplina == 2) {
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
            printf("\n\nNÃO HÁ DISCIPLINAS PARA EXCLUIR\n(Aperte Enter para continuar)\n\n");
            getchar();
          } 
          else {
            int disciplinaExcluida;
            printf("\nQual disciplina você gostaria de remover? (selecione o id): ");
            scanf("%d", &disciplinaExcluida);
            getchar();

            if (disciplina[disciplinaExcluida - 1].codigo == 0 || disciplinaExcluida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
              printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              disciplina[disciplinaExcluida - 1].codigo = 0;
              printf("\n\nDisciplina excluída com sucesso\n(Aperte Enter para continuar)\n\n");
              getchar();
            }
          }
        }        
        // Atualizar alguma disciplina
        else if (escolhaDisciplina == 3) {
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

            if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
              printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              int escolhaAtualizarDisciplina;
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
                while (true) {
                  system("clear");
                  printf("Informe o novo nome para a disciplina: ");
                  fgets(disciplina[disciplinaEscolhida - 1].nome, 30, stdin);
        
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
        else
          break;
      }
    }
    // Relatórios
    else if (escolha == 4) {
      while (true) {
        int escolhaRelatorio;
        system("clear");
        printf("\nRELATÓRIO");
        printf("\nDigite uma das seguintes opções:\n\n");
        printf("[1] - Listar todos os alunos\n");             // Rafael X
        printf("[2] - Listar todos os professores\n");        // Rafael X
        printf("[3] - Listar todas as disciplinas\n");        // Luana
        printf("[4] - Listar uma disciplina com detalhes\n"); // Luana
        printf("[5] - Listar alunos por gênero\n");           // Rafael X
        printf("[6] - Listar alunos ordenados por nome\n");   // Rafael
        printf("[7] - Listar alunos ordenados por data de nascimento\n"); // Rafael
        printf("[8] - Listar professores por gênero\n");               // Rafael X
        printf("[9] - Listar professores ordenados por nome\n");       // Rafael
        printf("[10] - Listar professores ordenados por data de nascimento\n"); // Rafael
        printf("[11] - Listar aniversariantes do mês\n"); // Luana
        printf("[12] - Pesquisar pesssoas\n");            // Rafael
        printf("[13] - Listar alunos matriculados em menos de 3 disciplinas\n"); // Luana
        printf("[14] - Listar disciplinas que extrapolam 40 vagas\n"); // Luana
        printf("\nInsira qualquer outra tecla para finalizar\n");
        printf("\n=> ");
        scanf("%d", &escolhaRelatorio);
        getchar();

        // Listar todos os alunos
        if (escolhaRelatorio == 1) {
          if (listaPessoas(alunos)) {
            printf("\n\nAlunos listados com sucessos\n(Aperte Enter para continuar)\n\n");
            getchar();
          } else {
            printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
        }
        // Listar todos os professores
        else if (escolhaRelatorio == 2) {
          if (listaPessoas(prof)) {
            printf("\n\nAlunos listados com sucessos\n(Aperte Enter para continuar)\n\n");
            getchar();
          } else {
            printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
        }
        // Listar todas as disciplinas
        else if (escolhaRelatorio == 3) {
          int temDisciplina = false;
          system("clear");
          for (int i = 0; i < disciplinaQtd; i++) {
            if (disciplina[i].codigo == 0)
              continue;

            else {
              temDisciplina = true;
              puts(disciplina[i].nome);
              printf("- código: %d\n- semestre: %d\n- professor:", disciplina[i].codigo, disciplina[i].semestre);
              puts(disciplina[i].professor);
              printf("\n\n");
            }
          }

          if (!temDisciplina) {
            printf("NÃO HÁ DISCIPLINAS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
            getchar();
          }

          printf("Disciplinas listadas com sucessos\n(Aperte Enter para continuar)\n\n");
          getchar();
        }
        // Listar uma disciplina com detalhes
        else if (escolhaRelatorio == 4) {
          printf("%d", escolhaRelatorio);
        }
        // Listar alunos por gênero
        else if (escolhaRelatorio == 5) {
          if (listaPessoas(alunos)) {
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
          } else {
            printf("Não há alunos disponíveis");
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
          if (listaPessoas(prof)) {
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
          } else {
            printf("Não há professores disponíveis");
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
        } 
        else
          break;
      }
    } 
    else {
      printf("Finalizado");
      break;
    }
  }
}