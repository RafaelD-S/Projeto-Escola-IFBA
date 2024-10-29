#include "relatorios.h"

// Organização feita do mais velho para o mais novo
void listarAlunosNasc(rgInfoPessoa *alunos) {
  system("clear");
  int temAluno = false;
  for (int i = 0; i < usuariosQtd; i++) {
    if (alunos[i].matricula == 0)
      continue;

    else 
      temAluno = true;
  }

  if (!temAluno) {
    printf("\n\nNÃO HÁ ALUNOS DISPONÍVEIS\n(Aperte Enter para continuar)\n\n");
    getchar();
  } 
  else {    
    int alunosNasc[usuariosQtd];

    for (int i = 0; i < usuariosQtd; i++) {
      alunosNasc[i] = i;  
    }

    for (int k = 0; k < usuariosQtd - 1; k++) {
      for (int i = 0; i < usuariosQtd - k - 1; i++) {
        int ano = alunos[alunosNasc[i]].dtNasc % 10000;
        int mes = alunos[alunosNasc[i]].dtNasc / 10000 % 100;
        int dia = alunos[alunosNasc[i]].dtNasc / 1000000;

        int ano1 = alunos[alunosNasc[i + 1]].dtNasc % 10000;
        int mes1 = alunos[alunosNasc[i + 1]].dtNasc / 10000 % 100;
        int dia1 = alunos[alunosNasc[i + 1]].dtNasc / 1000000;

        int aux;        
        if (ano1 < ano || (ano1 == ano && mes1 < mes) || (ano1 == ano && mes1 == mes && dia1 < dia)) {
          aux = alunosNasc[i];
          alunosNasc[i] = alunosNasc[i + 1];
          alunosNasc[i + 1] = aux;
        }
      }
    }

    for (int i = 0; i < usuariosQtd; i++) {
      int index = alunosNasc[i];
      if (alunos[index].matricula != 0) {
        printf("- ");
        puts(alunos[index].nome);
      }
    }
    
    printf("\n\n(Aperte Enter para continuar)");
    getchar();
  }
}