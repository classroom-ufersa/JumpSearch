#ifndef ALUNO_H
#define ALUNO_H

#include "../System/system.h"

typedef union documento Documento;

typedef struct aluno Aluno;

// função que adiciona aluno no arquivo
void cadastrar_aluno(const char caminho[], int *mat);

// Função auxiliar para comparar duas matrículas de alunos
int comparar_matriculas(const void *a, const void *b);

// Função que busca um aluno pela matrícula utilizando o algoritmo Jump Search
Aluno *buscar_aluno_pela_matricula(Aluno *alunos, int qnta);

// Função auxiliar para comparar dois nomes de alunos
int comparar_nomes(const void *a, const void *b);

// Função que busca um aluno pelo nome utilizando o algoritmo Jump Search
Aluno *buscar_aluno_pelo_nome(Aluno *alunos, int qnta);

// Função que lê o arquivo e adiciona os alunos numa array do tipo aluno
Aluno *ler_arquivo(Aluno **alunos, const char caminho[], int *qnta, int *mat);

// exibe os alunos armazenados na struct Aluno
void listar_alunos(Aluno *alunos, int qnta);

#endif // ALUNO_H