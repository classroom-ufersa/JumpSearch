# Importação das bibliotecas necessárias
import os
import math

# Abertura do arquivo
try:
    arquivo_alunos = open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\dataset\\alunos.csv', "r")
except:
    print("Erro ao abrir arquivo!")
    exit(1)

def JumpSearch(arquivo_alunos, x):
    n = len(arquivo_alunos)
    # Definir o tamanho do salto
    jump_tamanho = math.sqrt(n)
    # Definir o limite superior e inferior do intervalo de busca
    menor = 0
    superior = jump_tamanho
    # Encontrar o bloco onde a string pode estar presente
    while arquivo_alunos[min(superior, n)-1] < x:
        menor = superior
        superior += jump_tamanho
        if menor >= n:
            return -1
    # Realizar uma pesquisa linear no bloco encontrado
    while arquivo_alunos[menor] < x:
        menor += 1
        if menor == min(superior, n):
            return -1
    # Se a string for encontrada, retornar o índice correspondente
    if arquivo_alunos[menor] == x:
        return menor
    else:
        return -1
    print(arquivo_alunos)
