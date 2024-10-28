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
  alunos[0].dtNasc = 28032006;
  alunos[0].cpf = 12345678912;

  alunos[1].matricula = 123;
  alunos[1].sexo = 'M';
  strcpy(alunos[1].nome, nome5); // nome do aluno
  alunos[1].dtNasc = 18012006;
  alunos[1].cpf = 12345678912;

  // Professor 1
  prof[0].matricula = 123;
  prof[0].sexo = 'F';
  strcpy(prof[0].nome, nome2); // nome do professor 1
  prof[0].dtNasc = 18012006;
  prof[0].cpf = 12345678912;

  // Professor 2
  prof[1].matricula = 123;
  prof[1].sexo = 'M';
  strcpy(prof[1].nome, nome3); // nome do professor 2
  prof[1].dtNasc = 18122006;
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
    printf("Bem vindo ao Projeto Escola. Digite uma das seguintes opções:");
    const char *opcoes[] = {
        "Cadastro de Alunos",
        "Cadastro de Professores",
        "Cadastro de Disciplinas",
        "Relatório"
    };
    int escolha = listarOpcoes(opcoes, 4);

    // Cadastro de alunos
    if (escolha == 1) {
      while (true) {
        system("clear");
        printf("\nCADASTRO DE ALUNO");
        const char *opcoes[] = {
            "Incluir um novo aluno",
            "Excluir um aluno",
            "Atualizar algum aluno"
        };
        int escolhaAluno = listarOpcoes(opcoes, 3);

        // Adionar um novo aluno
        if (escolhaAluno == 1) {
          registrarPessoas(alunos);
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
            printf("\n\nQual aluno deseja atualizar? (selecione o id): ");
            scanf("%d", &alunoEscolhido);
            getchar();

            if (alunos[alunoEscolhido - 1].matricula == 0) {
              printf("\n\nEsse aluno não existe \n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              system("clear");
              printf("CADASTRO DE ALUNO\n");
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

                  if (alunos[alunoEscolhido - 1].sexo == 'M' ||
                      alunos[alunoEscolhido - 1].sexo == 'F' || 
                      alunos[alunoEscolhido - 1].sexo == 'N')
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

        system("clear");
        printf("CADASTRO DE PROFESSOR\n");
        const char *opcoes[] = {
          "Incluir um novo professor",
          "Excluir um professor",
          "Atualizar algum professor"
        };
        int escolhaProf = listarOpcoes(opcoes, 3);

        // Adionar um novo professor
        if (escolhaProf == 1) {
          registrarPessoas(prof);
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
            printf("\n\nQual professor deseja atualizar? (selecione o id): ");
            scanf("%d", &profEscolhido);
            getchar();

            if (prof[profEscolhido - 1].matricula == 0) {
              printf("\n\nEsse professor não existe \n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {

              system("clear");
              printf("Que mudança deseja fazer\n");
              const char *opcoes[] = {
                "Mudar a matrícula",
                "Mudar o nome",
                "Mudar o gênero",
                "Mudar a data de nascimento",
                "Mudar o CPF"
              };
              int escolhaAtualizarProf = listarOpcoes(opcoes, 5);

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
        system("clear");
        printf("CADASTRO DE DISCIPLINA\n");
        const char *opcoes[] = {
          "Incluir uma nova disciplina",
          "Excluir uma disciplina",
          "Atualizar alguma disciplina",
          "Cadastrar um aluno na disciplina",
          "Excluir o cadastro de um aluno na disciplina"
        };
        int escolhaDisciplina = listarOpcoes(opcoes, 5);

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
              system("clear");
              printf("Que mudança deseja fazer\n");
              const char *opcoes[] = {
                "Mudar o nome",
                "Mudar o código",
                "Mudar o semestre" 
                "Mudar o nome do professor",
              };
              int escolhaAtualizarDisciplina = listarOpcoes(opcoes, 4);;

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
        // Cadastrar um aluno em alguma disciplina
        else if (escolhaDisciplina == 4) {
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
            printf("\n\nNÃO HÁ DISCIPLINAS PARA CADASTRO\n(Aperte Enter para continuar)\n\n");
            getchar();
          } 
          else {
            int disciplinaEscolhida;
            printf("\n\nQual disciplina deseja cadastrar o aluno? (selecione o id): ");
            scanf("%d", &disciplinaEscolhida);
            getchar();

            if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
              printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              system("clear");
              int temAluno = false;
              for (int j = 0; j < usuariosQtd; j++) {
                if (alunos[j].matricula == 0)
                    continue;

                else {
                  temAluno = true;
                  printf("[%d] ", j + 1);
                  puts(alunos[j].nome);
                }
              }

              if (!temAluno) {
                printf("\n\nNÃO HÁ ALUNOS PARA SELECIONAR \n(Aperte Enter para continuar)\n\n");
                getchar();
              } 
              else {
                int alunoSelecionado;
                printf("\n\nQual o nome do aluno que será cadastrado? (selecione o id): ");
                scanf("%d", &alunoSelecionado);
                getchar();

                if (alunos[alunoSelecionado - 1].matricula == 0) {
                  printf("\n\nEsse aluno não existe \n(Aperte Enter para continuar)\n\n");
                  getchar();      
                } 
                else {
                  int jaTemAluno = false;
                  for (int i = 0; i < usuariosQtd; i++) {
                    if (disciplina[disciplinaEscolhida - 1].alunos[i] == alunos[alunoSelecionado - 1].matricula) 
                      jaTemAluno = true;
                  }
                  if (jaTemAluno) {
                    printf("\n\nEsse aluno já foi cadastrado\n(Aperte Enter para continuar)\n\n");
                    getchar();
                  }
                  else {
                    for (int k = 0; k < usuariosQtd; k++) {
                      if (disciplina[disciplinaEscolhida - 1].alunos[k] == 0) {
                        disciplina[disciplinaEscolhida - 1].alunos[k] = alunos[alunoSelecionado - 1].matricula;
                        break;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        // Excluir cadastro de um aluno em alguma disciplina
        else if (escolhaDisciplina == 5) {
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
            printf("\n\nNÃO HÁ DISCIPLINAS CADASTRADAS\n(Aperte Enter para continuar)\n\n");
            getchar();
          } 
          else {
            int disciplinaEscolhida;
            printf("\n\nQual disciplina deseja remover o cadastro do aluno? (selecione o id): ");
            scanf("%d", &disciplinaEscolhida);
            getchar();

            if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
              printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              system("clear");
              int temAluno = false;
              for (int j = 0; j < usuariosQtd; j++) {
                if (disciplina[disciplinaEscolhida - 1].alunos[j] == 0)
                  continue;

                else {
                  temAluno = true;
                  for (int k = 0; k < usuariosQtd; k++) {
                    if (disciplina[disciplinaEscolhida - 1].alunos[j] == alunos[k].matricula) {
                      printf("[%d] ", j + 1);
                      puts(alunos[k].nome);
                      break;
                    }
                  }
                }
              }

              if (!temAluno) {
                printf("\n\nNÃO HÁ ALUNOS PARA SELECIONAR \n(Aperte Enter para continuar)\n\n");
                getchar();
              } 
              else {
                int alunoSelecionado;
                printf("\n\nQual o nome do aluno que terá o cadastro removido? (selecione o id): ");
                scanf("%d", &alunoSelecionado);
                getchar();

                if (disciplina[disciplinaEscolhida - 1].alunos[alunoSelecionado - 1] == 0) {
                  printf("\n\nEsse aluno não existe \n(Aperte Enter para continuar)\n\n");
                  getchar();      
                } 
                else {
                  for (int i = 0; i < nomeTamanho; i++) {
                    disciplina[disciplinaEscolhida - 1].alunos[alunoSelecionado - 1] = 0;
                  }
                  printf("\n\nCadastro excluído com sucesso\n(Aperte Enter para continuar)\n\n");
                  getchar();
                  break;
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
        system("clear");
        printf("\nRELATÓRIOS");
        const char *opcoesRelatorio[] = {
            "Listar todos os alunos",                          // Rafael X
            "Listar todos os professores",                     // Rafael X
            "Listar todas as disciplinas",                     // Luana X
            "Listar uma disciplina com detalhes",              // Luana X
            "Listar alunos por gênero",                        // Rafael X
            "Listar alunos ordenados por nome",                // Rafael
            "Listar alunos ordenados por data de nascimento",  // Rafael
            "Listar professores por gênero",                   // Rafael X
            "Listar professores ordenados por nome",           // Rafael
            "Listar professores ordenados por data de nascimento", // Rafael
            "Listar aniversariantes do mês",                   // Luana
            "Pesquisar pessoas",                               // Rafael
            "Listar alunos matriculados em menos de 3 disciplinas", // Luana
            "Listar disciplinas que extrapolam 40 vagas"       // Luana
        };
        int escolhaRelatorio = listarOpcoes(opcoesRelatorio, 14);

        // Listar todos os alunos
        if (escolhaRelatorio == 1) {
          if (listaPessoas(alunos)) {
            printf("\n\nAlunos listados com sucesso\n(Aperte Enter para continuar)\n\n");
            getchar();
          } else {
            printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
        }
        // Listar todos os professores
        else if (escolhaRelatorio == 2) {
          if (listaPessoas(prof)) {
            printf("\n\nAlunos listados com sucesso\n(Aperte Enter para continuar)\n\n");
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
              printf("- Código: %d\n- Semestre: %d\n- Professor:", disciplina[i].codigo, disciplina[i].semestre);
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
          int temDisciplina = false;
          system("clear");
          for (int i = 0; i < disciplinaQtd; i++) {
            if (disciplina[i].codigo == 0)
              continue;

            else {
              temDisciplina = true;
              printf("[%d] ", i + 1);
              puts(disciplina[i].nome);
            }
          }

          if (!temDisciplina) {
            printf("NÃO HÁ DISCIPLINAS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
          else {
            int disciplinaEscolhida;
            printf("\n\nQual disciplina deseja visualizar? (selecione o id): ");
            scanf("%d", &disciplinaEscolhida);
            getchar();

            if (disciplina[disciplinaEscolhida - 1].codigo == 0 || disciplinaEscolhida == 0) { // código tá vazando e deixando o 0 passar, tentarei consertar no futuro
              printf("\n\nEssa disciplina não existe\n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              system("clear");
              puts(disciplina[disciplinaEscolhida - 1].nome);
              printf("- Código: %d\n- Semestre: %d\n- Professor: ", disciplina[disciplinaEscolhida - 1].codigo, disciplina[disciplinaEscolhida - 1].semestre);
              puts(disciplina[disciplinaEscolhida - 1].professor);

              if (disciplina[disciplinaEscolhida - 1].alunos[0] != 0) {
                printf("- Alunos Cadastrados na Disciplina: \n");

                for (int j = 0; j < usuariosQtd; j++) {
                  for (int k = 0; k < usuariosQtd; k++) {
                    if (disciplina[disciplinaEscolhida - 1].alunos[j] == alunos[k].matricula && disciplina[disciplinaEscolhida - 1].alunos[j] != 0) {
                      printf("  %d. ", j + 1);
                      puts(alunos[k].nome);
                      break;
                    } 
                  }
                }

                printf("\n\n");
              } 
              else {
                printf("- Não há alunos cadastrados nessa disciplina\n\n\n");
              }

              printf("(Aperte Enter para continuar)\n\n");
              getchar();
            }
          }
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
                    int escolhaMes;
          while (true) {
            system("clear");
            int temPessoa = false;
            for (int i = usuariosQtd - 1; i >= 0; i--) {
              if (alunos[i].matricula == 0 && prof[i].matricula == 0 )
                continue;

              else 
                temPessoa = true;
            }

            if (!temPessoa) {
              printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
              getchar();
            } 
            else {
              system("clear");
              printf("\nANIVERSARIANTES DO MÊS");
              printf("\nEscolha um mês para ver os aniversariantes:\n\n");
              printf("[1] - Janeiro\n");
              printf("[2] - Fevereiro\n");
              printf("[3] - Março\n");
              printf("[4] - Abril\n");
              printf("[5] - Maio\n");
              printf("[6] - Junho\n");
              printf("[7] - Julho\n");
              printf("[8] - Agosto\n");
              printf("[9] - Setembro\n");
              printf("[10] - Outubro\n");
              printf("[11] - Novembro\n");
              printf("[12] - Dezembro\n");    
              printf("\nInsira qualquer outra tecla para voltar\n");
              printf("\n=> ");
              scanf("%d", &escolhaMes);
              getchar();

              if (escolhaMes <= 12 && escolhaMes >= 1) {
                system("clear");           
                int temAniversariante = false; 
                for (int j = 0; j < usuariosQtd; j++) {
                  if (alunos[j].matricula != 0) {
                    int mesAluno;
                    mesAluno = alunos[j].dtNasc / 10000;
                    mesAluno = mesAluno % 100;

                    if (escolhaMes == mesAluno) {
                      temAniversariante = true;
                      printf("- Discente ");
                      puts(alunos[j].nome);
                    }
                  }

                  if (prof[j].matricula != 0) {
                    int mesProf;
                    mesProf = prof[j].dtNasc / 10000;
                    mesProf = mesProf % 100;
                    if (escolhaMes == mesProf) {
                      temAniversariante = true;
                      printf("- Docente ");
                      puts(prof[j].nome);
                    }
                  }
                }

                if (!temAniversariante) {
                  printf("NÃO HÁ ANIVERSARIANTES NESSE MÊS\n(Aperte Enter para continuar)\n\n");
                  getchar();
                  break;
                }

                printf("\n\nAniversariantes listados com sucesso\n(Aperte Enter para continuar)\n\n");
                getchar();
              }
              break;
            }
          } 
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
          int temDisciplina = false;
          system("clear");
          for (int i = disciplinaQtd - 1; i >= 0; i--) {
            if (disciplina[i].codigo == 0)
              continue;

            else {
              temDisciplina = true;
              break;
            }
          }

          if (!temDisciplina) {
            printf("\n\nNÃO HÁ DISCIPLINAS CADASTRADAS\n(Aperte Enter para continuar)\n\n");
            getchar();
          } 
          else {
            int disciplinaCheia = false;
            for (int i = 0; i < disciplinaQtd; i++) {
              int alunos = 0;
              for (int j = 0; j < usuariosQtd; j++) {
                if (disciplina[i].alunos[j] != 0) {
                  alunos++;
                }
              }
              if (alunos > 40) {
                disciplinaCheia = true;
                puts(disciplina[i].nome);
                printf("- Professor: ");
                puts(disciplina[i].professor);
                printf("- Quantidade de Alunos: %d", alunos);
                printf("\n\n");
              }
            }

            if (!disciplinaCheia) {
              printf("NÃO HÁ DISCIPLINAS COM MAIS DE 40 ALUNOS CADASTRADOS\n(Aperte Enter para continuar)\n\n");
              getchar();
              break;
            }

            printf("(Aperte Enter para continuar)\n\n");
            getchar();
          }
        } 
        else
          break;
      }
    } 
    else {
      system("clear");
      printf("FINALIZADO");
      break;
    }
  }
}