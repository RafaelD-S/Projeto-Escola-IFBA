#include "relatorios.h"

void listarAniversariantes(rgInfoPessoa *alunos, rgInfoPessoa *prof) {

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
      printf("\n\nNÃO HÁ PESSOAS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
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


