#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

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

Aluno *BuscarAlunoPelaMatricula(Aluno *alunos, int qnta)
{
    int matricula;
    int salto = sqrt(qnta); // Calcula o tamanho do salto para o algoritmo Jump Search
    int i = 0, j = 0;

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
    qsort(alunos, qnta, sizeof(Aluno), compararMatriculas); // Ordena o array de alunos

    // Aplicar o algoritmo Jump Search para encontrar o índice do aluno no array
    while (i < qnta && alunos[i].matricula < matricula) // Executa um loop enquanto a matrícula do aluno atual for menor do que a matrícula procurada
    {
        i += salto; // Incrementa o índice do aluno com base no tamanho do salto
    }
    if (i >= qnta || alunos[i].matricula > matricula) // Se o índice do aluno atual for maior ou igual ao tamanho do array de alunos ou a matrícula do aluno atual for maior do que a matrícula procurada
    {
        i -= salto;                                 // Decrementa o índice do aluno com base no tamanho do salto
        for (j = i; j < i + salto && j < qnta; j++) // Executa um loop para percorrer os alunos próximos ao índice do aluno atual, no intervalo [i, i+salto)
        {
            if (alunos[j].matricula == matricula) // Se a matrícula do aluno atual for igual à matrícula procurada
            {
                return &alunos[j]; // Retorna o ponteiro para o aluno encontrado
            }
        }
        return NULL; // Retorna NULL para indicar que não foi encontrado nenhum aluno
    }
    else if (alunos[i].matricula == matricula) // Se a matrícula do aluno atual for igual à matrícula procurada
    {
        return &alunos[i]; // Retorna o ponteiro para o aluno encontrado
    }

    return NULL; // Retorna NULL para indicar que não foi encontrado nenhum aluno
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
    int i = 0, j = 0;

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
    // Formatando nome
    int tamanhodonome = strlen(aluno.nome);
    aluno.nome[0] = toupper(aluno.nome[0]); // convertendo o primeiro caractere para maiusculo
    // Percorra os caracteres restantes e convertendo para minúscula
    for (i = 1; i < tamanhodonome; i++)
    {
        aluno.nome[i] = tolower(aluno.nome[i]);
        // Verificando se o caractere anterior é um espaço em branco Se sim, converte o caractere atual para maiúscula
        if (aluno.nome[i - 1] == ' ')
        {
            aluno.nome[i] = toupper(aluno.nome[i]);
        }
    }
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
