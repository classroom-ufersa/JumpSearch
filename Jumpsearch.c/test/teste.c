#include "C:\Users\jhoan\Desktop\VScode\GitHub\JumpSearch\Jumpsearch.c\src\aluno.c"

Aluno *JumpSearch(Aluno *alunos, int qnta)
{
    char nome[100]; //c1, 1 vez
    int salto = sqrt(qnta); //c2, 1 vez
    int i = 0, j = 0; //c3, 1 vez
    while (i < qnta && strcmp(alunos[i].nome, nome) < 0)//c4, √qnta vezes
    {
        i += salto;//c5, √qnta vezes
    }
    if (i >= qnta || strcmp(alunos[i].nome, nome) > 0) //c6, 1 vez
    {
        i -= salto; //c7, 1 vez
        for (j = i; j < i + salto && j < qnta; j++)//c8, √qnta vezes
        {
            if (strcmp(alunos[j].nome, nome) == 0)//c9, √qnta vezes
            {
                return &alunos[j]; //c10, 1 vez
            }
        }
        return NULL;
    }
    else if (strcmp(alunos[i].nome, nome) == 0)//c11, 1 vez
    {
        return &alunos[i];
    }
    return NULL;
}

/*
quantidade de alunos = n

T(n) = (c1 + c2 + c3 + c6 + c7 + c10 + c11) + (c4 + c5 + c8 + c9)√n
a = (c4 + c5 + c8 + c9)        b = (c1 + c2 + c3 + c6 + c7 + c10 + c11)
T(n) = a√n + b

Ou seja 

O(√n)
*/