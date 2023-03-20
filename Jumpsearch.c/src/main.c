#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

int main(void)
{
    int controle, totaldealunos = 0, j;
    Aluno *alunotemporario;
    FILE *arquivo;
    char caminho[] = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\JumpSearch\\Jumpsearch.c\\data\\aluno.txt"; // caminho do arquivo txt(Varia de pc para pc)
    arquivo = fopen(caminho, "r");
    Aluno *alunos = (Aluno *)malloc(sizeof(Aluno)); // alocando dinamicamente
    alunos = NULL;                                  // inicializnando o "vetor aluno"
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        return 1;
    }
    printf("+----------------------------------------------------------------+\n"
           "|        Bem-vindo ao Programa de Gerenciamento de Alunos        |\n"
           "|                                                                |\n"
           "|             Autores: Jhoan   Abner   Caio    Tomaz             |\n"
           "|                                                                |\n"
           "|                          Versao: 2.0                           |\n"
           "+----------------------------------------------------------------+\n\n");
    while (controle != 6) // vai repetir ate o usuario digitar 6
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
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
            alunos = lerArquivo(alunos, caminho, &totaldealunos);
            printf("Atualizado!\n\n");
            break;
        case 2:
            ListarAlunos(alunos, totaldealunos);
            break;
        case 3:
            cadastrarAluno(arquivo, caminho);
            break;
        case 4:
            alunotemporario = BuscarAlunoPelaMatricula(alunos, totaldealunos);
            if (alunotemporario != NULL)
            {
                printf("\nAluno Encontrado!\n\n");
                printf("Nome: %s\n", alunotemporario->nome);
                printf("Matricula: %d\n", alunotemporario->matricula);
                if (strlen(alunotemporario->documento.cpf) == 14)
                {
                    printf("CPF: %s\n", alunotemporario->documento.cpf);
                }
                else if (strlen(alunotemporario->documento.rg) == 11)
                {
                    printf("RG: %s\n", alunotemporario->documento.rg);
                }
                printf("Notas: ");
                for (j = 0; j < 3; j++)
                {
                    printf("%.1f ", alunotemporario->notas[j]);
                }
                printf("\nMedia: %.1f\n\n", alunotemporario->media);
            }
            else
            {
                printf("Aluno Nao foi encontrado!\n\n");
            }
            break;
        case 5:
            alunotemporario = BuscarAlunoPeloNome(alunos, totaldealunos);
            if (alunotemporario != NULL)
            {
                printf("\nAluno Encontrado!\n\n");
                printf("Nome: %s\n", alunotemporario->nome);
                printf("Matricula: %d\n", alunotemporario->matricula);
                if (strlen(alunotemporario->documento.cpf) == 14)
                {
                    printf("CPF: %s\n", alunotemporario->documento.cpf);
                }
                else if (strlen(alunotemporario->documento.rg) == 11)
                {
                    printf("RG: %s\n", alunotemporario->documento.rg);
                }
                printf("Notas: ");
                for (j = 0; j < 3; j++)
                {
                    printf("%.1f ", alunotemporario->notas[j]);
                }
                printf("\nMedia: %.1f\n\n", alunotemporario->media);
            }
            else
            {
                printf("Aluno Nao foi encontrado!\n\n");
            }
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
    free(alunos);
    return 0;
}