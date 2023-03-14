#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int controle;
    FILE *arquivo = fopen("Alunos.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    printf("Bem-vindo ao Programa de Gerenciamento de Alunos!\nEste programa gerencia os alunos.\nAutores: Jhoan,Abner,Caio,Tomaz\t\tVersao:1.0");
    while (controle != 6) // vai repetir ate o usuario digitar 6
    {
        printf("\n\nMenu:\n1-Buscar aluno\n2-Listar Alunos\n3-Matricular alunos\n4-Lancar notas\n5-Alterar dados de um aluno\n6-Sair\n\nDigite sua opcao: ");
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
        
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            printf("Obrigado por usar meu programa!");
            break;
        default:
            printf("opcao invalida!");
            break;
        }
    }
    fclose(arquivo);
    return 0;
}