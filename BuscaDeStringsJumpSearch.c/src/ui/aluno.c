#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

//implementando a struct aluno
struct aluno
{
    char nome[81];
    int matricula;
    float notas[4];
    float media;
};

Aluno* buscar_aluno(FILE* arquivo, int mat){
    Aluno* aluno = jumpS(arquivo,mat);
    printf("%d", aluno->matricula);
}
