#include <stdio.h>


typedef struct aluno
{
    char nome[100];
    int matricula;
    float notas[3];
    float media;
} Aluno;

FILE* cadastrarAluno(FILE* arquivo) {
   Aluno aluno;
   int i;
   
   // Abrir o arquivo para escrita
   arquivo = fopen("alunos.txt", "a");
   
   // Verificar se o arquivo foi aberto com sucesso
   if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      exit(1);
   }
   
   // Ler os dados do aluno
   printf("Digite o nome do aluno: ");
   scanf(" %[^\n]s", aluno.nome);
   printf("Digite a matricula do aluno: ");
   scanf("%d", &aluno.matricula);
   aluno.media = 0.0;
   for ( i = 0; i < 3; i++) {
        printf("Digite a nota %d do aluno: ", i+1);
        scanf("%f", &aluno.notas[i]);
        aluno.media += aluno.notas[i];
   }
   aluno.media = aluno.media/3;
   
   // Escrever os dados do aluno no arquivo
   fprintf(arquivo, "%s %d %.2f %.2f %.2f %.2f\n", aluno.nome, aluno.matricula, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
   
   // Fechar o arquivo
   fclose(arquivo);
   
   printf("Aluno cadastrado com sucesso.\n");
   return arquivo;
}
 int main(void){
    FILE* arquivo = fopen("alunos.txt", "r");
    cadastrarAluno(arquivo);
    return 0;
 }