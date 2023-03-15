#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[100];
    int matricula;
    float notas[3];
    float media;
} Aluno;

Aluno* BuscarAlunoPeloNome (Aluno * aluno, int qnta);

//função que adiciona aluno no arquivo
FILE *cadastrarAluno(FILE *arquivo, char caminho[])
{
    Aluno aluno;
    int i;

    // Abrir o arquivo para escrita
    arquivo = fopen(caminho, "a");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Ler os dados do aluno
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", aluno.nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno.matricula);
    aluno.media = 0.0;
    for (i = 0; i < 3; i++)
    {
        printf("Digite a nota %d do aluno: ", i + 1);
        scanf("%f", &aluno.notas[i]);
        aluno.media += aluno.notas[i];
    }
    aluno.media = aluno.media / 3;

    // Escrever os dados do aluno no arquivo
    fprintf(arquivo, "%s %d %.2f %.2f %.2f %.2f\n", aluno.nome, aluno.matricula, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);

    // Fechar o arquivo
    fclose(arquivo);
    printf("Aluno cadastrado com sucesso.\n");
    return arquivo;
}

//Função que lê o arquivo e adiciona os alunos numa array do tipo aluno
Aluno * lerArquivo(Aluno *alunos, char caminho[], int *qnta)
{
    FILE *arquivo;
    int i = 0;
    char linha[200];
    char *token;

    // Abrir o arquivo para leitura
    arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Ler cada linha do arquivo e armazenar em um elemento do array
    while (fgets(linha, 200, arquivo) != NULL)
    {
        // Redimensiona o array de alunos dinamicamente, se necessário
        if (i >= *qnta)
        {
            alunos = (Aluno *)realloc(alunos, (*qnta + 1) * sizeof(Aluno));
            if (alunos == NULL)
            {
                printf("Erro ao alocar memória para o array de alunos.\n");
                exit(1);
            }
            (*qnta)++;
        }

        // Extrai os dados de um aluno a partir de uma linha do arquivo
        token = strtok(linha, " "); // extrai o nome do aluno
        strcpy((alunos)[i].nome, token);
        token = strtok(NULL, " "); // extrai a matrícula
        (alunos)[i].matricula = atoi(token);
        token = strtok(NULL, " "); // extrai a primeira nota
        (alunos)[i].notas[0] = atof(token);
        token = strtok(NULL, " "); // extrai a segunda nota
        (alunos)[i].notas[1] = atof(token);
        token = strtok(NULL, " "); // extrai a terceira nota
        (alunos)[i].notas[2] = atof(token);
        token = strtok(NULL, " "); // extrai a média
        (alunos)[i].media = atof(token);
        i++; // incrementa o índice do array
    }
    // Fechar o arquivo
    fclose(arquivo);
    return alunos;
}

//exibe os alunos armazenados na struct Aluno
void ListarAlunos(Aluno *alunos, int qnta)
{
    int i, j;
    // Verificar se o array de alunos está vazio
    if (alunos == NULL)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    // Imprimir os dados de cada aluno
    for (i = 0; i < qnta; i++)
    {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Notas: ");
        for (j = 0; j < 3; j++)
        {
            printf("%.1f ", alunos[i].notas[j]);
        }
        printf("\nMedia: %.1f\n\n", alunos[i].media);
    }
}
