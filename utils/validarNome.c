#include "validadores.h"

int validarNome(rgInfoPessoa *pessoas, int i) {

    for (int j = 97; j < 122; j++) {
      if (pessoas[i].nome[0] == j) {
        pessoas[i].nome[0] = pessoas[i].nome[0] - 32;
        break;
      }
    }

    if (strlen(pessoas[i].nome) > 1)
      return true;

    printf("\nNome inválido. Tente novamente.\n\n(Aperte Enter para continuar)");
    getchar();
    return false;
}