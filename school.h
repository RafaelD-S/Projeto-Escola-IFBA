#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./relatorios/relatorios.h"

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
  int codigo;
  int semestre;
  char professor[nomeTamanho];
  int alunos[usuariosQtd];
} procedimentoMatricula;

int listarPessoas(rgInfoPessoa *pessoasLista);
int listarOpcoes(const char **opcao, int opcaoQtd);
void registrarPessoas(rgInfoPessoa *pessoas);
void excluirPessoas(rgInfoPessoa *pessoas);
void atualizarPessoas(rgInfoPessoa *pessoas);
void adicionarDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *prof);
void excluirDisciplina(procedimentoMatricula *disciplina);
void atualizarDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *prof);
void cadastrarAlunoDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *alunos);
void excluirAlunoDisciplina(procedimentoMatricula *disciplina, rgInfoPessoa *alunos);


#endif