#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

Aluno* JumpS(FILE* arquivo, int mat) {
    // Obtem o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    // Define o tamanho do bloco
    int tam_bloco = sqrt(tamanho_arquivo / sizeof(Aluno));

    // Define o ponteiro de inicio do bloco
    int inicio_bloco = 0;

    // Define o ponteiro de fim do bloco
    int fim_bloco = tam_bloco;

    // Busca o bloco que contem o aluno procurado
    while (fim_bloco < tamanho_arquivo / sizeof(Aluno) && mat > ((Aluno*)malloc(sizeof(Aluno)))->matricula) {
        inicio_bloco = fim_bloco;
        fim_bloco += tam_bloco;
    }

    // Realiza a busca sequencial no bloco encontrado
    fseek(arquivo, inicio_bloco * sizeof(Aluno), SEEK_SET);
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
    while (ftell(arquivo) < fim_bloco * sizeof(Aluno)) {
        fread(aluno, sizeof(Aluno), 1, arquivo);
        if (aluno->matricula == mat) {
            return aluno;
        }
    }

    // Aluno nao encontrado
    return NULL;
}