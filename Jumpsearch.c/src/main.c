#include "Aluno/aluno.c"
#include "System/system.c"

int main(void)
{
    clock_t inicio;
    double tempo;
    int controle, totaldealunos = 0, j;
    int mat = 0;
    Aluno *alunotemporario;
    const char caminho[] = "../data/aluno.txt";
    Aluno *alunos = (Aluno *)malloc(sizeof(Aluno)); // alocando dinamicamente
    if (alunos == NULL)
    {
        print_red("[ERRO]");
        exit(1);
    }
    alunos = ler_arquivo(&alunos, caminho, &totaldealunos, &mat);
    print_green("+----------------------------------------------------------------+\n"
                "|        Bem-vindo ao Programa de Gerenciamento de Alunos        |\n"
                "|                                                                |\n"
                "|             Autores: Jhoan   Abner   Caio    Tomaz             |\n"
                "|                                                                |\n"
                "|                          Versao: 2.0                           |\n"
                "+----------------------------------------------------------------+\n\n");
    while (controle != OPCAO5)
    {
        menu();
        controle = le_opcao(OPCAO1, OPCAO5);
        switch (controle)
        {
        case OPCAO1:
            listar_alunos(alunos, totaldealunos);
            break;
        case OPCAO2:
            cadastrar_aluno(caminho, &mat);
            alunos = ler_arquivo(&alunos, caminho, &totaldealunos, &mat);
            break;
        case OPCAO3:
            inicio = clock();
            alunotemporario = buscar_aluno_pela_matricula(alunos, totaldealunos);
            tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // Milisegundos
            printf("Tempo de execucao: %.1f Milisegundos\n", tempo);
            if (alunotemporario != NULL)
            {
                print_green("\nAluno Encontrado!\n\n");
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
                print_red("Aluno Nao foi encontrado!\n\n");
            }
            break;
        case OPCAO4:
            inicio = clock();
            alunotemporario = buscar_aluno_pelo_nome(alunos, totaldealunos);
            tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // Milisegundos
            printf("Tempo de execucao: %.1f Milisegundos\n", tempo);
            if (alunotemporario != NULL)
            {
                print_green("\nAluno Encontrado!\n\n");
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
                print_red("Aluno Nao foi encontrado!\n\n");
            }
            break;
        case OPCAO5:
            print_yellow("Obrigado por usar meu programa!\n");
            break;
        default:
            print_red("opcao invalida!\n");
            break;
        }
    }
    free(alunos);
    return 0;
}