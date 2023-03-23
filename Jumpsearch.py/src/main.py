# Importação das bibliotecas necessárias
import csv
import os
import math
import pandas as pd

# Abertura do arquivo
#try:
 #   lista_alunos = open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\dataset\\alunos.csv', "r")
#except:
 #   print("Erro ao abrir lista!")
  #  exit(1)

#lista_alunos = lista_alunos.read()

def jump_search(nome, lista_alunos):
    tamanho = len(lista_alunos)
    jump = int(math.sqrt(tamanho))
    prev = 0
    curr = jump
    while curr < tamanho and lista_alunos[curr] <= nome:
        prev = curr
        curr += jump
    for i in range(prev, min(curr, tamanho)):
        if lista_alunos[i] == nome:
            return i
    return -1

lista_alunos = open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\dataset\\alunos.csv', "r")
lista_alunos = lista_alunos.read()
nome = 'Bruno'
index = jump_search(nome, lista_alunos)
if index != -1:
    print(f"{nome} encontrado na posição {index}")
else:
    print(f"{nome} nao foi encontrado")
