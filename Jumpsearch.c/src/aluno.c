#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[100];
    int matricula;
    float notas[3];
    float media;
} Aluno;

void ExibirAluno(int matricula, Aluno **alunos)
{
    printf("\nBuscando aluno...\n");
    // Chama a função jumpsearch para encontrar o aluno com a matrícula fornecida, e armazenar o aluno na variavel temporária
    Aluno *alunoexibido = jumpsearch(matricula, alunos);
    // Se o aluno foi encontrado, exibe suas informações
    if (alunoexibido != NULL)
    {
        printf("Aluno encontrado!\n");
        printf("Nome: %s\n", alunoexibido->nome);
        printf("Matricula: %d\n", alunoexibido->matricula);
        printf("Notas: %.1f %.1f %.1f\n", alunoexibido->notas[0], alunoexibido->notas[1], alunoexibido->notas[2]);
        printf("Media: %.1f\n", alunoexibido->media);
    }
    else
    {
        // Caso contrário, informa que o aluno não foi encontrado
        printf("O aluno nao foi encontrado.\n");
    }
}

void ListarAlunos(Aluno **alunos, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNome:\t%s\n", alunos[i]->nome);
        printf("Matricula:\t%d\n", alunos[i]->matricula);
        printf("Notas:\t%.1f\t%.1f\t%.1f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
        printf("Media:\t%.1f\n", alunos[i]->media);
    }
}

