#include "validadores.h"

int validarDataDeNascimento(rgInfoPessoa *pessoas, int i) {
  int dia = pessoas[i].dtNasc / 1000000;
  int mes = pessoas[i].dtNasc / 10000 % 100;
  int ano = pessoas[i].dtNasc % 10000;
  
  if (dia > 0 && dia < 32 && mes > 0 && mes < 13 && ano > 1900 && ano < 2024)
    return true;

  printf("\nData de nascimento inválida. Tente novamente.\n\n(Aperte Enter para continuar)");
  getchar();
  return false;
}