#include "school.h"

int main() {
  rgInfoPessoa alunos[usuariosQtd] = {0};
  rgInfoPessoa prof[usuariosQtd] = {0};
  struct procedimentoMatricula disciplina[disciplinaQtd] = {0};

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

        if (escolhaAluno == 1) {
          registrarPessoas(alunos);
        }
          
        else if (escolhaAluno == 2) {
          excluirPessoas(alunos);
        }
        
        else if (escolhaAluno == 3) {
          atualizarPessoas(alunos);
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

        if (escolhaProf == 1) 
          registrarPessoas(prof);

        else if (escolhaProf == 2)
          excluirPessoas(prof);

        else if (escolhaProf == 3)
          atualizarPessoas(prof);
        
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
          if (listarPessoas(alunos)) {
            printf("\n\nAlunos listados com sucesso\n(Aperte Enter para continuar)\n\n");
            getchar();
          } else {
            printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
            getchar();
          }
        }
        // Listar todos os professores
        else if (escolhaRelatorio == 2) {
          if (listarPessoas(prof)) {
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
          if (listarPessoas(alunos)) {
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
          if (listarPessoas(prof)) {
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