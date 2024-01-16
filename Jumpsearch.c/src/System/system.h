#ifndef SISTEMA_H
#define SISTEMA_H
// Módulo: funções para tratativas e falhas

#include <stdio.h> //funções basicas da linguagem c
#include <stdlib.h> //para fazer alocação dinamica
#include <string.h> //para usar strings
#include <math.h> //operações algebricas
#include <time.h> //Tempo de execução
#include <ctype.h> //manipulação de caracteres

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

//verifica se o cpf está no formato correto
int validar_cpf(const char *cpf);

// verifica se o rg está no formato correto
int validar_rg(const char *rg);

//le um cpf
void ler_cpf(char cpf[]);

// le um rg
void ler_rg(char rg[]);

//valida nota
int validar_nota(const char *entrada);

// le uma nota
float ler_nota();

#endif // SISTEMA_H