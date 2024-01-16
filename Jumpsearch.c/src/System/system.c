#include "system.h"

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define WHITE "\x1B[0m"

#define N_OPCOES 8

#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'

void limpa_buffer(void)
{
    int valorLido;
    do
    {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

char le_opcao(char menorValor, char maiorValor)
{
    char op;
    char entrada[100];
    char text[50];
    while (1)
    {
        printf("Digite sua opcao: ");
        scanf(" %[^\n]", entrada);
        op = entrada[0];
        if (op >= menorValor && op <= maiorValor && strlen(entrada) == 1)
        {
            limpa_buffer();
            break;
        }
        else
        {
            sprintf(text, "Opcao invalida. A opcao deve estar entre %c e %c.\n", menorValor, maiorValor);
            print_red(text);
            limpa_buffer();
        }
    }
    return op;
}

void corrige_nome(char nome[])
{
    int tamanho_do_nome = strlen(nome);
    int i, j;
    char ultimo_caractere = ' ';

    for (i = 0, j = 0; i < tamanho_do_nome; i++)
    {
        if (isalpha(nome[i]) || nome[i] == ' ')
        {
            if (nome[i] == ' ' && ultimo_caractere == ' ')
            {
                continue;
            }
            nome[j] = nome[i];
            j++;
            ultimo_caractere = nome[i];
        }
    }
    nome[j] = '\0';
    nome[0] = toupper(nome[0]);
    for (i = 1; i < j; i++)
    {
        nome[i] = tolower(nome[i]);
        if (nome[i - 1] == ' ')
        {
            nome[i] = toupper(nome[i]);
        }
    }
    tamanho_do_nome = strlen(nome);
    if (j == 1 && nome[tamanho_do_nome] == ' ')
    {
        nome[tamanho_do_nome] = '\0';
    }
}

void menu(void)
{
    printf("Menu:\n");
    printf("========================================\n");
    printf("[1] Atualizar sistema\n");
    printf("[2] Listar Alunos\n");
    printf("[3] Matricular alunos\n");
    printf("[4] Buscar aluno por matricula\n");
    printf("[5] Buscar aluno pelo nome\n");
    printf("[6] Sair\n");
    printf("========================================\n");
    printf("Digite o numero da opcao desejada: ");
}

void print_green(char *text)
{
    printf("%s%s%s", GREEN, text, WHITE);
}

void print_yellow(char *text)
{
    printf("%s%s%s", YELLOW, text, WHITE);
}

void print_red(char *text)
{
    printf("%s%s%s", RED, text, WHITE);
}