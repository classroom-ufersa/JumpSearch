#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[100];
    int matricula;
    float notas[3];
    float media;
} Aluno;

FILE* cadastrarAluno(FILE* arquivo) {
   Aluno aluno;
   int i;
   
   // Abrir o arquivo para escrita
   arquivo = fopen("alunos.txt", "a");
   
   // Verificar se o arquivo foi aberto com sucesso
   if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      exit(1);
   }
   
   // Ler os dados do aluno
   printf("Digite o nome do aluno: ");
   scanf(" %[^\n]s", aluno.nome);
   printf("Digite a matricula do aluno: ");
   scanf("%d", &aluno.matricula);
   aluno.media = 0.0;
   for ( i = 0; i < 3; i++) {
        printf("Digite a nota %d do aluno: ", i+1);
        scanf("%f", &aluno.notas[i]);
        aluno.media += aluno.notas[i];
   }
   aluno.media = aluno.media/3;
   
   // Escrever os dados do aluno no arquivo
   fprintf(arquivo, "%s %d %.2f %.2f %.2f %.2f\n", aluno.nome, aluno.matricula, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
   
   // Fechar o arquivo
   fclose(arquivo);
   
   printf("Aluno cadastrado com sucesso.\n");
   return arquivo;
}


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

