#include "aluno.h"

union documento
{
    char cpf[15];
    char rg[12];
};

struct aluno
{
    char nome[100];
    int matricula;
    Documento documento;
    float notas[3];
    float media;
};

void cadastrar_aluno(const char caminho[], int *mat)
{
    Aluno aluno;
    int i;
    char opcao_documento;

    FILE *arquivo = fopen(caminho, "a");

    if (arquivo == NULL)
    {
        print_red("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    print_yellow("Digite o nome do aluno: ");
    scanf(" %[^\n]s", aluno.nome);

    corrige_nome(aluno.nome);
    aluno.matricula = (*mat)++ + 100;
    aluno.media = 0.0;

    printf("Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG\n");
    opcao_documento = le_opcao(OPCAO1, OPCAO2);
    if (opcao_documento == OPCAO1)
        ler_cpf(aluno.documento.cpf);
    else
        ler_rg(aluno.documento.rg);
    printf("\n");
    for (i = 0; i < 3; i++)
    {
        printf("Nota %d\n", i + 1);
        aluno.notas[i] = ler_nota();
        aluno.media += aluno.notas[i];
    }
    aluno.media = aluno.media / 3;

    if (opcao_documento == '1')
    {
        fprintf(arquivo, "%s\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n", aluno.nome, aluno.matricula, aluno.documento.cpf, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
    }
    else
    {
        fprintf(arquivo, "%s\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n", aluno.nome, aluno.matricula, aluno.documento.rg, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
    }

    fclose(arquivo);
    print_green("Aluno cadastrado com sucesso.\n\n");
}

int comparar_matriculas(const void *a, const void *b)
{
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return alunoA->matricula - alunoB->matricula;
}

Aluno *buscar_aluno_pela_matricula(Aluno *alunos, int qnta)
{
    int matricula;
    int salto = sqrt(qnta);
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
    qsort(alunos, qnta, sizeof(Aluno), comparar_matriculas); // Ordena o array de alunos

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

int comparar_nomes(const void *a, const void *b)
{
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return strcmp(alunoA->nome, alunoB->nome);
}

// Função que busca um aluno pelo nome utilizando o algoritmo Jump Search
Aluno *buscar_aluno_pelo_nome(Aluno *alunos, int qnta)
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
    corrige_nome(nome);
    // Ordenar o array de alunos em ordem alfabética pelo nome
    qsort(alunos, qnta, sizeof(Aluno), comparar_nomes);

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

Aluno *ler_arquivo(Aluno **alunos, const char caminho[], int *qnta, int *mat)
{
    FILE *arquivo;
    int i = 0;
    char linha[200];
    char *token;

    arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fgets(linha, 200, arquivo) != NULL)
    {
        if (i >= *qnta)
        {
            (*alunos) = (Aluno *)realloc(*alunos, (*qnta + 1) * sizeof(Aluno));
            if ((*alunos) == NULL)
            {
                printf("Erro ao alocar memória para o array de alunos.\n");
                exit(1);
            }
            (*qnta)++;
        }

        token = strtok(linha, "\t"); 
        strcpy((*alunos)[i].nome, token);
        token = strtok(NULL, "\t"); 
        (*alunos)[i].matricula = atoi(token);
        token = strtok(NULL, "\t"); 
        if (strlen(token) == 14)
        {
            strcpy((*alunos)[i].documento.cpf, token);
        }
        else if (strlen(token) == 11)
        {
            strcpy((*alunos)[i].documento.rg, token);
        }
        token = strtok(NULL, "\t"); 
        (*alunos)[i].notas[0] = atof(token);
        token = strtok(NULL, "\t"); 
        (*alunos)[i].notas[1] = atof(token);
        token = strtok(NULL, "\t"); 
        (*alunos)[i].notas[2] = atof(token);
        token = strtok(NULL, "\t"); 
        (*alunos)[i].media = atof(token);
        (*mat) = (*alunos)[i].matricula - 100 + 1;
        i++; 
    }

    fclose(arquivo);
    return (*alunos);
}

void listar_alunos(Aluno *alunos, int qnta)
{
    int i, j;
    
    if (alunos == NULL)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    
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