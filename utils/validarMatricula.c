#include "validadores.h"

int validarMatricula(rgInfoPessoa *pessoas, int i) {

  int jaTemMatricula = false;

  for (int j = usuariosQtd - 1; j >= 0; j--) {
    if (pessoas[j].matricula == pessoas[i].matricula && i != j)
      jaTemMatricula = true;

    else 
      continue;
  }
  
  if (jaTemMatricula && pessoas[i].matricula != 0) {
    printf("\nJá existe alguém com essa matricula. Tente novamente.\n\n(Aperte Enter para continuar)");
    getchar();
    return false;
  }
  
  if (pessoas[i].matricula > 0)
    return true;
    
  else {
    printf("\nMatricula inválida. Tente novamente.\n\n(Aperte Enter para continuar)");
    getchar();
    return false;
  }
}