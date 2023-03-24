import math
import csv
import Alunos

def cadastrar_aluno_csv(aluno):
    header = ["Nome", "Idade", "Endereco"]
    file_exists = os.path.isfile("alunos.csv")

    with open("alunos.csv", "a", newline="") as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=header)

        if not file_exists:
            writer.writeheader()

        writer.writerow({"Nome": aluno.get_nome(), "Idade": aluno.get_idade(), "Endereco": aluno.get_endereco()})

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