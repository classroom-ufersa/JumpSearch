import csv

# leitura da lista de strings a partir do arquivo CSV
arquivo = "c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\dataset\\alunos.csv"
with open(arquivo, "r") as file:
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