#include "Aluno/aluno.c"
#include "System/system.c"

int main(void)
{
    clock_t inicio;
    double tempo;
    int controle, totaldealunos = 0, j;
    Aluno *alunotemporario;
    FILE *arquivo;
    const char caminho[] = "../data/aluno.txt";
    Aluno *alunos = (Aluno *)malloc(sizeof(Aluno)); // alocando dinamicamente
    if (alunos == NULL)
    {
        printf("[ERRO]");
        exit(1);
    }
    alunos = ler_arquivo(alunos, caminho, &totaldealunos); 
    printf("+----------------------------------------------------------------+\n"
           "|        Bem-vindo ao Programa de Gerenciamento de Alunos        |\n"
           "|                                                                |\n"
           "|             Autores: Jhoan   Abner   Caio    Tomaz             |\n"
           "|                                                                |\n"
           "|                          Versao: 2.0                           |\n"
           "+----------------------------------------------------------------+\n\n");
    while (controle != 6) 
    {
        menu();
        scanf("%d", &controle);
        switch (controle)
        {
        case 1:
            alunos = ler_arquivo(alunos, caminho, &totaldealunos);
            printf("Atualizado!\n\n");
            break;
        case 2:
            listar_alunos(alunos, totaldealunos);
            break;
        case 3:
            cadastrar_aluno(arquivo, caminho);
            break;
        case 4:
            inicio = clock();
            alunotemporario = buscar_aluno_pela_matricula(alunos, totaldealunos);
            tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // Milisegundos
            printf("Tempo de execucao: %.1f Milisegundos\n", tempo);
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
            inicio = clock();
            alunotemporario = buscar_aluno_pelo_nome(alunos, totaldealunos);
            tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // Milisegundos
            printf("Tempo de execucao: %.1f Milisegundos\n", tempo);
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