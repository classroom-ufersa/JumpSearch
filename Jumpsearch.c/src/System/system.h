#ifndef SISTEMA_H
#define SISTEMA_H
// Módulo: funções para tratativas e falhas

#include <stdio.h> //funções basicas da linguagem c
#include <stdlib.h> //para fazer alocação dinamica
#include <string.h> //para usar strings
#include <math.h> //operações algebricas
#include <time.h> //Tempo de execução
#include <ctype.h> //manipulação de caracteres

// Lê e descarta caracteres encontrados na entrada
void limpa_buffer(void);

// Lê e valida a opção digitada pelo usuário
char le_opcao(char menorValor, char maiorValor);

// corrige o nome
void corrige_nome(char nome[]);

// Exibe o menu
void menu(void);

// Imprime em verde
void print_green(char *text);

// Imprime em amarelo
void print_yellow(char *text);

// Imprime em vermelho
void print_red(char *text);

// verificação do numero
int verifica_numero_telefone(const char numero[]);

// verificação do email
int verifica_email(const char email[]);

// formatação do numero
void formata_numero_telefone(char numero[]);

#endif // SISTEMA_H