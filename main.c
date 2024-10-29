#include "school.h"

int main() {
  rgInfoPessoa alunos[usuariosQtd] = {0};
  rgInfoPessoa prof[usuariosQtd] = {0};
  procedimentoMatricula disciplina[disciplinaQtd] = {0};

  // Exemplos de uso para não ter que gerar um novo todo teste
  char nome1[nomeTamanho] = "Rafael";  
  alunos[0].matricula = 123;
  alunos[0].sexo = 'F';
  strcpy(alunos[0].nome, nome1);
  alunos[0].dtNasc = 28032006;
  alunos[0].cpf = 12345678912;

  char nome5[nomeTamanho] = "Luana";   
  alunos[1].matricula = 321;
  alunos[1].sexo = 'M';
  strcpy(alunos[1].nome, nome5);
  alunos[1].dtNasc = 18012006;
  alunos[1].cpf = 12345678912;

  char nome2[nomeTamanho] = "Romilson";  
  prof[0].matricula = 123;
  prof[0].sexo = 'F';
  strcpy(prof[0].nome, nome2);
  prof[0].dtNasc = 18012006;
  prof[0].cpf = 12345678912;

  char nome3[nomeTamanho] = "Magno";      
  prof[1].matricula = 321;
  prof[1].sexo = 'M';
  strcpy(prof[1].nome, nome3); 
  prof[1].dtNasc = 18122006;
  prof[1].cpf = 12345678912;

  char nome4[nomeTamanho] = "Matemática"; 
  strcpy(disciplina[0].nome, nome4);
  disciplina[0].codigo = 2;
  disciplina[0].semestre = 1;
  strcpy(disciplina[0].professor, nome3); 

  char nome6[nomeTamanho] = "Lógica de Programação"; 
  strcpy(disciplina[1].nome, nome6);
  disciplina[1].codigo = 1;
  disciplina[1].semestre = 1;
  strcpy(disciplina[1].professor, nome2);

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

    // Cadastro de Alunos
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

        if (escolhaAluno == 1) 
          registrarPessoas(alunos);
          
        else if (escolhaAluno == 2) 
          excluirPessoas(alunos);
        
        else if (escolhaAluno == 3) 
          atualizarPessoas(alunos);

        else if (escolhaAluno == 0)
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
        
        else if (escolhaProf == 0)
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
        
        if (escolhaDisciplina == 1) 
          adcionarDisciplina(disciplina, prof);

        else if (escolhaDisciplina == 2) 
          excluirDisciplina(disciplina);   

        else if (escolhaDisciplina == 3) 
          atualizarDisciplina(disciplina, prof);

        else if (escolhaDisciplina == 4) 
          cadastrarAlunoDisciplina(disciplina, alunos);

        else if (escolhaDisciplina == 5) 
          excluirAlunoDisciplina(disciplina, alunos);

        else if (escolhaDisciplina == 0)
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