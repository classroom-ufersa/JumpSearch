#include <stdio.h>

typedef struct aluno Aluno;

Aluno* BuscarAlunoPeloNome (Aluno * aluno, int qnta);

//função que adiciona aluno no arquivo
FILE* cadastrarAluno(FILE* arquivo, char caminho []);

//Função que lê o arquivo e adiciona os alunos numa array do tipo aluno
Aluno * lerArquivo(Aluno *alunos, char caminho[], int *qnta); 

//exibe os alunos armazenados na struct Aluno
void ListarAlunos(Aluno* alunos, int qnta);
