#ifndef RELATORIOS_H
#define RELATORIOS_H
#include "../school.h"

void listarAlunos(rgInfoPessoa *alunos);
void listarAlunosGenero(rgInfoPessoa *alunos);
void listarAlunosNasc();
void listarAlunosNome();

void listarProf(rgInfoPessoa *prof);
void listarProfGenero(rgInfoPessoa *prof);
void listarProfNasc();
void listarProfNome();

void listarAniversariantes(rgInfoPessoa *alunos, rgInfoPessoa *prof);
void pesquisarPessoas();
void listarMenosQueTresDisciplinas();
void listarDisciplinasQuarentaVagas(procedimentoMatricula *disciplina);

void listarDisciplinas(procedimentoMatricula *disciplinas);
void listarDisciplinaDetalhe(procedimentoMatricula *disciplinas, rgInfoPessoa *alunos);
#endif