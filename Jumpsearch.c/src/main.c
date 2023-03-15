#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

int main(void)
{
    int controle,totaldealunos = 0;
    FILE *arquivo;
    char caminho [] = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\JumpSearch\\Jumpsearch.c\\data\\aluno.txt";
    arquivo = fopen(caminho, "r");
    Aluno* alunos = (Aluno*) malloc(sizeof(Aluno));
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        return 1;

    }
    printf("Bem-vindo ao Programa de Gerenciamento de Alunos!\nEste programa gerencia os alunos.\nAutores: Jhoan,Abner,Caio,Tomaz\t\tVersao:1.0");
    while (controle != 6) // vai repetir ate o usuario digitar 6
    {
        printf("\n\nMenu:\n1-Atualizar sistema\n2-Listar Alunos\n3-Matricular alunos\n4-Lancar notas\n5-Alterar dados de um aluno\n6-Sair\n\nDigite sua opcao: ");
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
            alunos = lerArquivo(alunos, caminho, &totaldealunos);
            printf("Atualizado!");
            break;
        case 2:
            ListarAlunos(alunos,totaldealunos);
            break;
        case 3:
            cadastrarAluno(arquivo,caminho,alunos,&totaldealunos);
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