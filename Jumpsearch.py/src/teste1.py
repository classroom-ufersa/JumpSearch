import csv
import math

def jump_search(nome, lista_nomes):
    n = len(lista_nomes)
    jump = int(math.sqrt(n))
    prev = 0
    curr = jump
    while curr < n and lista_nomes[curr] <= nome:
        prev = curr
        curr += jump
    for i in range(prev, min(curr, n)):
        if lista_nomes[i] == nome:
            return i
    return -1

# leitura da lista de strings a partir do arquivo CSV
filename = "alunos1.csv"
with open(filename, "r") as file:
    reader = csv.reader(file)
    lista_nomes = [row[0] for row in reader]

# entrada do usuário da nome a ser buscada
nome = input("Digite a nome a ser buscada: ")

# busca da nome na lista
index = jump_search(nome, lista_nomes)
if index != -1:
    print(f"{nome} encontrada na posição {index} da lista")
else:
    print(f"{nome} não encontrada na lista")