#include "validadores.h"

int validarGenero(rgInfoPessoa *pessoas, int i) {
  if (pessoas[i].sexo == 'm' || pessoas[i].sexo == 'f' || pessoas[i].sexo == 'n') 
    pessoas[i].sexo -= 32;

  if (pessoas[i].sexo == 'M' || pessoas[i].sexo == 'F' || pessoas[i].sexo == 'N')
    return true;

  getchar();
  printf("\nGênero inválido. Tente novamente.\n\n(Aperte Enter para continuar)");
  getchar();
  return false;
}
