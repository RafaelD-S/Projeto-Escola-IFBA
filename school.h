#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ESCOLA_H
#define ESCOLA_H
#define nomeTamanho 35
#define disciplinaQtd 50
#define usuariosQtd 100

typedef struct {
  int matricula;
  char nome[nomeTamanho];
  char sexo;
  int dtNasc;
  long int cpf;
} rgInfoPessoa;

typedef struct {
    char nome[nomeTamanho];
    int codigo = 0;
    int semestre;
    char professor[nomeTamanho];
} procedimentoMatricula

int listaPessoas(rgInfoPessoa* pessoasLista);

#endif