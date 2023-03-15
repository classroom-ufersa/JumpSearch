#include <stdio.h>

typedef struct aluno Aluno;

//função que adiciona aluno no arquivo
FILE* cadastrarAluno(FILE* arquivo, char caminho [],Aluno* alunos,int* qnta);

//Função que lê o arquivo e adiciona os alunos numa array do tipo aluno
Aluno * lerArquivo(Aluno *alunos, char caminho[], int *qnta); 

//exibe os alunos armazenados
void ListarAlunos(Aluno* alunos, int qnta);
