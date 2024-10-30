#ifndef RELATORIOS_H
#define RELATORIOS_H
#include "../school.h"

void listarAlunos(rgInfoPessoa *alunos);
void listarAlunosGenero(rgInfoPessoa *alunos);
void listarAlunosNasc(rgInfoPessoa *alunos);
void listarAlunosNome(rgInfoPessoa *alunos);

void listarProf(rgInfoPessoa *prof);
void listarProfGenero(rgInfoPessoa *prof);
void listarProfNasc(rgInfoPessoa *prof);
void listarProfNome(rgInfoPessoa *prof);

void listarAniversariantes(rgInfoPessoa *alunos, rgInfoPessoa *prof);
void pesquisarPessoas(rgInfoPessoa *alunos, rgInfoPessoa *prof);
void listarMenosQueTresDisciplinas(procedimentoMatricula *disciplinas, rgInfoPessoa *alunos);
void listarDisciplinasQuarentaVagas(procedimentoMatricula *disciplinas);

void listarDisciplinas(procedimentoMatricula *disciplinas);
void listarDisciplinaDetalhe(procedimentoMatricula *disciplinas, rgInfoPessoa *alunos);
#endif