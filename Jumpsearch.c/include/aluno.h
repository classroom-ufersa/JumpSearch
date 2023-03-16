#include <stdio.h>

typedef struct documento Documento;

typedef struct aluno Aluno;

// Função auxiliar para comparar duas matrículas de alunos
int compararMatriculas(const void* a, const void* b);

// Função que busca um aluno pela matrícula utilizando o algoritmo Jump Search
Aluno* BuscarAlunoPelaMatricula(Aluno* alunos, int qnta);

// Função auxiliar para comparar dois nomes de alunos
int compararNomes(const void* a, const void* b);

// Função que busca um aluno pelo nome utilizando o algoritmo Jump Search
Aluno* BuscarAlunoPeloNome(Aluno* alunos, int qnta);

//função que adiciona aluno no arquivo
FILE* cadastrarAluno(FILE* arquivo, char caminho []);

//Função que lê o arquivo e adiciona os alunos numa array do tipo aluno
Aluno * lerArquivo(Aluno *alunos, char caminho[], int *qnta); 

//exibe os alunos armazenados na struct Aluno
void ListarAlunos(Aluno* alunos, int qnta);
