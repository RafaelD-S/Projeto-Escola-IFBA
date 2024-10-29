#include "../school.h"

int listarOpcoes(const char **opcao, int opcaoQtd) {
  int escolha = 0;
  printf("\n\n[0] - Retroceder\n");
  for (int i = 0; i < opcaoQtd; i++) {
    printf("[%d] - ", i + 1);
    puts(opcao[i]);
  }
  printf("\n=> ");
  scanf("%d", &escolha);
  getchar();

  return escolha;
}