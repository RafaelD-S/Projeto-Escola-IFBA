#include "relatorios.h"

void listarProfNasc(rgInfoPessoa *prof) {
  system("clear");
  int temProf = false;
  for (int i = 0; i < usuariosQtd; i++) {
    if (prof[i].matricula == 0)
      continue;

    else 
      temProf = true;
  }

  if (!temProf) {
    printf("\n\nNÃO HÁ PROFESSORES DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {    
    int profNasc[usuariosQtd];

    for (int i = 0; i < usuariosQtd; i++) {
      profNasc[i] = i;  
    }

    for (int k = 0; k < usuariosQtd - 1; k++) {
      for (int i = 0; i < usuariosQtd - k - 1; i++) {
        int ano = prof[profNasc[i]].dtNasc % 10000;
        int mes = prof[profNasc[i]].dtNasc / 10000 % 100;
        int dia = prof[profNasc[i]].dtNasc / 1000000;

        int ano1 = prof[profNasc[i + 1]].dtNasc % 10000;
        int mes1 = prof[profNasc[i + 1]].dtNasc / 10000 % 100;
        int dia1 = prof[profNasc[i + 1]].dtNasc / 1000000;

        int aux;        
        if (ano1 < ano || (ano1 == ano && mes1 < mes) || (ano1 == ano && mes1 == mes && dia1 < dia)) {
          aux = profNasc[i];
          profNasc[i] = profNasc[i + 1];
          profNasc[i + 1] = aux;
        }
      }
    }

    for (int i = 0; i < usuariosQtd; i++) {
      int index = profNasc[i];
      if (prof[index].matricula != 0) {
        printf("- ");
        puts(prof[index].nome);
      }
    }
    
    printf("\n\nOrdenados do mais velho para o mais novo\n(Aperte Enter para continuar)");
    getchar();
  }
}