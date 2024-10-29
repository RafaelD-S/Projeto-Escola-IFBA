#include "school.h"

int main() {
  rgInfoPessoa alunos[usuariosQtd] = {0};
  rgInfoPessoa prof[usuariosQtd] = {0};
  procedimentoMatricula disciplina[disciplinaQtd] = {0};

  while (true) {
    system("clear");
    printf("Bem vindo ao Projeto Escola. Digite uma das seguintes opções:");
    const char *opcoes[] = {
        "Cadastro de Alunos",
        "Cadastro de Professores",
        "Cadastro de Disciplinas",
        "Relatório"
    };
    int escolha = listarOpcoes(opcoes, 4);

    // Cadastro de Alunos
    if (escolha == 1) {
      while (true) {
        system("clear");
        printf("\nCADASTRO DE ALUNO");
        const char *opcoes[] = {
            "Incluir um novo aluno",
            "Excluir um aluno",
            "Atualizar algum aluno"
        };
        int escolhaAluno = listarOpcoes(opcoes, 3);

        if (escolhaAluno == 1) 
          registrarPessoas(alunos);
          
        else if (escolhaAluno == 2) 
          excluirPessoas(alunos);
        
        else if (escolhaAluno == 3) 
          atualizarPessoas(alunos);

        else if (escolhaAluno == 0)
          break;
      }
    }
      
    // Cadastro de professor
    else if (escolha == 2) {
      while (true) {

        system("clear");
        printf("CADASTRO DE PROFESSOR\n");
        
        const char *opcoes[] = {
          "Incluir um novo professor",
          "Excluir um professor",
          "Atualizar algum professor"
        };
        
        int escolhaProf = listarOpcoes(opcoes, 3);

        if (escolhaProf == 1) 
          registrarPessoas(prof);

        else if (escolhaProf == 2)
          excluirPessoas(prof);

        else if (escolhaProf == 3)
          atualizarPessoas(prof);
        
        else if (escolhaProf == 0)
          break;
      }
    }

    // Cadastro de disciplina
    else if (escolha == 3) {
      while (true) {
        
        system("clear");
        printf("CADASTRO DE DISCIPLINA\n");
        const char *opcoes[] = {
          "Incluir uma nova disciplina",
          "Excluir uma disciplina",
          "Atualizar alguma disciplina",
          "Cadastrar um aluno na disciplina",
          "Excluir o cadastro de um aluno na disciplina"
        };
        int escolhaDisciplina = listarOpcoes(opcoes, 5);
        
        if (escolhaDisciplina == 1) 
          adcionarDisciplina(disciplina, prof);

        else if (escolhaDisciplina == 2) 
          excluirDisciplina(disciplina);   

        else if (escolhaDisciplina == 3) 
          atualizarDisciplina(disciplina, prof);

        else if (escolhaDisciplina == 4) 
          cadastrarAlunoDisciplina(disciplina, alunos);

        else if (escolhaDisciplina == 5) 
          excluirAlunoDisciplina(disciplina, alunos);

        else if (escolhaDisciplina == 0)
          break;
      }
    }

    // Relatórios
    else if (escolha == 4) {
      while (true) {
        system("clear");
        printf("\nRELATÓRIOS");
        const char *opcoesRelatorio[] = {
            "Listar todos os alunos",                          // Rafael X
            "Listar todos os professores",                     // Rafael X
            "Listar todas as disciplinas",                     // Luana X
            "Listar uma disciplina com detalhes",              // Luana X
            "Listar alunos por gênero",                        // Rafael X
            "Listar alunos ordenados por nome",                // Rafael
            "Listar alunos ordenados por data de nascimento",  // Rafael
            "Listar professores por gênero",                   // Rafael X
            "Listar professores ordenados por nome",           // Rafael
            "Listar professores ordenados por data de nascimento", // Rafael
            "Listar aniversariantes do mês",                   // Luana
            "Pesquisar pessoas",                               // Rafael
            "Listar alunos matriculados em menos de 3 disciplinas", // Luana
            "Listar disciplinas que extrapolam 40 vagas"       // Luana
        };
        int escolhaRelatorio = listarOpcoes(opcoesRelatorio, 14);


        if (escolhaRelatorio == 1) 
          listarAlunos(alunos);

        else if (escolhaRelatorio == 2) 
          listarProf(prof);

        else if (escolhaRelatorio == 3) 
          listarDisciplinas(disciplina);

        else if (escolhaRelatorio == 4) 
          listarDisciplinaDetalhe(disciplina, alunos);

        else if (escolhaRelatorio == 5) 
          listarAlunosGenero(alunos);

        else if (escolhaRelatorio == 6) 
          listarAlunosNome(alunos);

        else if (escolhaRelatorio == 7) 
          listarAlunosNasc(alunos);

        else if (escolhaRelatorio == 8) 
          listarProfGenero(prof);

        else if (escolhaRelatorio == 9) 
          listarProfNome(prof);

        else if (escolhaRelatorio == 10) 
          listarProfNasc();

        else if (escolhaRelatorio == 11) 
          listarAniversariantes(alunos, prof);

        else if (escolhaRelatorio == 12) 
          pesquisarPessoas();

        else if (escolhaRelatorio == 13) 
          listarMenosQueTresDisciplinas();

        else if (escolhaRelatorio == 14) 
          listarDisciplinasQuarentaVagas(disciplina);
    
        else if (escolhaRelatorio == 0)
          break;
        
      }
    } 

    // Finalizar
    else if (escolha == 0) {
      system("clear");
      printf("FINALIZADO");
      break;
    }
  }
}