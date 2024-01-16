#include "system.h"

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

int validar_cpf(const char *cpf)
{
    if (strlen(cpf) != 14)
    {
        return 1;
    }

    for (int i = 0; i < 14; i++)
    {
        if (i != 3 && i != 7 && i != 11)
        {
            if (!isdigit(cpf[i]))
            {
                return 1;
            }
        }
    }

    if (cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-')
    {
        return 1;
    }

    return 0;
}

int validar_rg(const char *rg)
{
    if (strlen(rg) != 11)
    {
        return 1;
    }

    for (int i = 0; i < 11; i++)
    {
        if (i != 3 && i != 7)
        {
            if (!isdigit(rg[i]))
            {
                return 1;
            }
        }
    }

    if (rg[3] != '.' || rg[7] != '.')
    {
        return 1;
    }
    return 0;
}

void ler_cpf(char cpf[])
{
    do
    {
        printf("Digite o CPF do aluno (XXX.YYY.ZZZ-SS): ");
        scanf(" %[^\n]", cpf);
        limpa_buffer();
        if (validar_cpf(cpf))
        {
            print_red("Erro: digite um CPF valido.\n");
        }
    } while (validar_cpf(cpf));
}

void ler_rg(char rg[])
{
    do
    {
        printf("Digite o RG do aluno (XXX.YYY.ZZZ): ");
        scanf(" %[^\n]", rg);
        limpa_buffer();
        if (validar_rg(rg))
        {
            print_red("Erro: digite um RG valido.\n");
        }
    } while (validar_rg(rg));
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

int validar_nota(const char *entrada)
{
    int tamanho = strlen(entrada);
    int i, boleano = 1;
    for (i = 0; i < tamanho; i++)
    {
        if (!isdigit(entrada[i]) && entrada[i] != '.')
        {
            boleano = 0;
            break;
        }
    }
    return boleano;
}

float ler_nota()
{
    float nota;
    char entrada[100];
    while (1)
    {
        printf("Digite a nota: ");
        scanf(" %[^\n]", entrada);

        if (validar_nota(entrada))
        {
            if (sscanf(entrada, "%f", &nota))
            {
                if (nota >= 0 && nota <= 10)
                {
                    limpa_buffer();
                    return nota;
                }
            }
        }
        print_red("Nota invalida. A nota deve estar entre 0 e 10.\n\n");
        limpa_buffer();
    }
}

void menu(void)
{
    printf("Menu:\n");
    printf("========================================\n");
    printf("[1] Listar Alunos\n");
    printf("[2] Matricular alunos\n");
    printf("[3] Buscar aluno por matricula\n");
    printf("[4] Buscar aluno pelo nome\n");
    printf("[5] Sair\n");
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