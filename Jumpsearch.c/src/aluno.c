#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef union documento
{
    char cpf[15];
    char rg[12];
} Documento;

typedef struct aluno
{
    char nome[100];
    int matricula;
    Documento documento;
    float notas[3];
    float media;
} Aluno;

// Função auxiliar para comparar duas matrículas de alunos
int compararMatriculas(const void *a, const void *b)
{
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return alunoA->matricula - alunoB->matricula;
}

// Função que busca um aluno pela matrícula utilizando o algoritmo Jump Search
Aluno *BuscarAlunoPelaMatricula(Aluno *alunos, int qnta)
{
    int matricula;
    int salto = sqrt(qnta);
    int i, j;

    // Verificar se o array de alunos está vazio
    if (alunos == NULL)
    {
        printf("Nenhum aluno cadastrado.\n");
        return NULL;
    }

    // Pedir ao usuário a matrícula do aluno que deseja buscar
    printf("Digite a matricula do aluno que deseja buscar: ");
    scanf("%d", &matricula);

    // Ordenar o array de alunos em ordem crescente pela matrícula
    qsort(alunos, qnta, sizeof(Aluno), compararMatriculas);

    // Aplicar o algoritmo Jump Search para encontrar o índice do aluno no array
    i = 0;
    while (i < qnta && alunos[i].matricula < matricula)
    {
        i += salto;
    }
    if (i >= qnta || alunos[i].matricula > matricula)
    {
        i -= salto;
        for (j = i; j < i + salto && j < qnta; j++)
        {
            if (alunos[j].matricula == matricula)
            {
                return &alunos[j];
            }
        }
        return NULL;
    }
    else if (alunos[i].matricula == matricula)
    {
        return &alunos[i];
    }

    return NULL;
}

// Função auxiliar para comparar dois nomes de alunos
int compararNomes(const void *a, const void *b)
{
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return strcmp(alunoA->nome, alunoB->nome);
}

// Função que busca um aluno pelo nome utilizando o algoritmo Jump Search
Aluno *BuscarAlunoPeloNome(Aluno *alunos, int qnta)
{
    char nome[100];
    int salto = sqrt(qnta);
    int i, j;

    // Verificar se o array de alunos está vazio
    if (alunos == NULL)
    {
        printf("Nenhum aluno cadastrado.\n");
        return NULL;
    }

    // Pedir ao usuário o nome do aluno que deseja buscar
    printf("Digite o nome do aluno que deseja buscar: ");
    scanf(" %[^\n]s", nome);

    // Ordenar o array de alunos em ordem alfabética pelo nome
    qsort(alunos, qnta, sizeof(Aluno), compararNomes);

    // Aplicar o algoritmo Jump Search para encontrar o índice do aluno no array
    i = 0;
    while (i < qnta && strcmp(alunos[i].nome, nome) < 0)
    {
        i += salto;
    }
    if (i >= qnta || strcmp(alunos[i].nome, nome) > 0)
    {
        i -= salto;
        for (j = i; j < i + salto && j < qnta; j++)
        {
            if (strcmp(alunos[j].nome, nome) == 0)
            {
                return &alunos[j];
            }
        }
        return NULL;
    }
    else if (strcmp(alunos[i].nome, nome) == 0)
    {
        return &alunos[i];
    }

    return NULL;
}

FILE *cadastrarAluno(FILE *arquivo, char caminho[])
{
    Aluno aluno;
    int i;
    char opcao_documento;

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

    // Pedir para o usuário escolher qual documento cadastrar
    printf("Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG: ");
    scanf(" %c", &opcao_documento);

    // Ler o documento escolhido pelo usuário
    if (opcao_documento == '1')
    {
        printf("Digite o CPF do aluno (XXX.YYY.ZZZ-SS): ");
        scanf(" %s", aluno.documento.cpf);
    }
    else if (opcao_documento == '2')
    {
        printf("Digite o RG do aluno (XXX.YYY.ZZZ): ");
        scanf(" %s", aluno.documento.rg);
    }
    else
    {
        printf("Opcao invalida.\n");
        exit(1);
    }

    for (i = 0; i < 3; i++)
    {
        printf("Digite a nota %d do aluno: ", i + 1);
        scanf("%f", &aluno.notas[i]);
        aluno.media += aluno.notas[i];
    }
    aluno.media = aluno.media / 3;

    // Escrever os dados do aluno no arquivo
    if (opcao_documento == '1')
    {
        fprintf(arquivo, "%s\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n", aluno.nome, aluno.matricula, aluno.documento.cpf, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
    }
    else
    {
        fprintf(arquivo, "%s\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n", aluno.nome, aluno.matricula, aluno.documento.rg, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
    }

    // Fechar o arquivo
    fclose(arquivo);
    printf("Aluno cadastrado com sucesso.\n\n");
    return arquivo;
}

Aluno *lerArquivo(Aluno *alunos, char caminho[], int *qnta)
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
        token = strtok(linha, "\t"); // extrai o nome do aluno
        strcpy((alunos)[i].nome, token);
        token = strtok(NULL, "\t"); // extrai a matrícula
        (alunos)[i].matricula = atoi(token);
        token = strtok(NULL, "\t"); // extrai o documento
        if (strlen(token) == 14)
        {
            strcpy((alunos)[i].documento.cpf, token);
        }
        else if (strlen(token) == 11)
        {
            strcpy((alunos)[i].documento.rg, token);
        }
        token = strtok(NULL, "\t"); // extrai a primeira nota
        (alunos)[i].notas[0] = atof(token);
        token = strtok(NULL, "\t"); // extrai a segunda nota
        (alunos)[i].notas[1] = atof(token);
        token = strtok(NULL, "\t"); // extrai a terceira nota
        (alunos)[i].notas[2] = atof(token);
        token = strtok(NULL, "\t"); // extrai a média
        (alunos)[i].media = atof(token);
        i++; // incrementa o índice do array
    }
    // Fechar o arquivo
    fclose(arquivo);
    return alunos;
}

// exibe os alunos armazenados na struct Aluno
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
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        if (strlen(alunos[i].documento.cpf) == 14)
        {
            printf("CPF: %s\n", alunos[i].documento.cpf);
        }
        else if (strlen(alunos[i].documento.rg) == 11)
        {
            printf("RG: %s\n", alunos[i].documento.rg);
        }
        printf("Notas: ");
        for (j = 0; j < 3; j++)
        {
            printf("%.1f ", alunos[i].notas[j]);
        }
        printf("\nMedia: %.1f\n\n", alunos[i].media);
    }
}
