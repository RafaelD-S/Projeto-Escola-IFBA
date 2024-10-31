#include "validadores.h"

int validarCpf(rgInfoPessoa *pessoas, int i) {
  char numeroStr[12];
  snprintf(numeroStr, sizeof(numeroStr), "%.0ld", pessoas[i].cpf);

  if (strlen(numeroStr) == 11)
    return true;

  printf("\nCPF inválido. Tente novamente.\n\n(Aperte Enter para continuar)");
  getchar();
  return false;
}