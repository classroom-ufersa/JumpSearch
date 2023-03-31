from typing import List
import os
from typing import IO

class Documento:
    def __init__(self, cpf: str = "", rg: str = ""):
        self.cpf = cpf
        self.rg = rg

class Aluno:
    def __init__(self, nome: str = "", matricula: int = 0, cpf: str = "", rg: str = "", notas: List[float] = []):
        self.nome = nome
        self.matricula = matricula
        self.documento = Documento(cpf, rg)
        self.notas = notas
        self.media = sum(notas)/len(notas) if len(notas) > 0 else 0

def ler_arquivo(caminho: str) -> List[Aluno]:
    alunos = []
    with open(caminho, "r") as arquivo:
        for linha in arquivo:
            campos = linha.strip().split("\t")
            nome = campos[0]
            matricula = int(campos[1])
            cpf = campos[2]
            notas = [float(nota) for nota in campos[3:]]
            aluno = Aluno(nome, matricula, cpf, notas=notas)
            alunos.append(aluno)
    return alunos

def ListarAlunos(alunos):
    # Verificar se a lista de alunos está vazia
    if not alunos:
        print("Nenhum aluno cadastrado.")
        return
    
    # Imprimir os dados de cada aluno
    for i, aluno in enumerate(alunos):
        print(f"Aluno {i + 1}")
        print(f"Nome: {aluno.nome}")
        print(f"Matricula: {aluno.matricula}")
        if len(aluno.documento.cpf) == 14:
            print(f"CPF: {aluno.documento.cpf}")
        elif len(aluno.documento.rg) == 11:
            print(f"RG: {aluno.documento.rg}")
        print(f"Notas: {', '.join(str(nota) for nota in aluno.notas)}")
        print(f"Media: {aluno.media:.1f}\n")

def BuscarAlunoPeloNome(alunos: List[Aluno]) -> Aluno:
    qnta = len(alunos)
    nome = input("Digite o nome do aluno que deseja buscar: ")
    salto = int(qnta**0.5)

    # Verificar se o array de alunos está vazio
    if qnta == 0:
        print("Nenhum aluno cadastrado.")
        return None

    # Ordenar o array de alunos em ordem crescente pelo nome
    alunos.sort(key=lambda a: a.nome)

    # Aplicar o algoritmo Jump Search para encontrar o índice do aluno no array
    i = 0
    while i < qnta and alunos[i].nome < nome:
        i += salto

    if i >= qnta or alunos[i].nome > nome:
        i -= salto
        for j in range(i, min(i+salto, qnta)):
            if alunos[j].nome == nome:
                return alunos[j]
        return None

    elif alunos[i].nome == nome:
        return alunos[i]

    return None

def BuscarAlunoPelaMatricula(alunos: List[Aluno]) -> Aluno:
    qnta = len(alunos)
    matricula = int(input("Digite a matricula do aluno que deseja buscar: "))
    salto = int(qnta**0.5)

    # Verificar se o array de alunos está vazio
    if qnta == 0:
        print("Nenhum aluno cadastrado.")
        return None

    # Ordenar o array de alunos em ordem crescente pela matrícula
    alunos.sort(key=lambda a: a.matricula)

    # Aplicar o algoritmo Jump Search para encontrar o índice do aluno no array
    i = 0
    while i < qnta and alunos[i].matricula < matricula:
        i += salto

    if i >= qnta or alunos[i].matricula > matricula:
        i -= salto
        for j in range(i, min(i+salto, qnta)):
            if alunos[j].matricula == matricula:
                return alunos[j]
        return None

    elif alunos[i].matricula == matricula:
        return alunos[i]

    return None

def BuscarAlunoPeloNome(alunos: List[Aluno]) -> Aluno:
    nome = input("Digite o nome do aluno que deseja buscar: ")
    qnta = len(alunos)

    # Verificar se o array de alunos está vazio
    if qnta == 0:
        print("Nenhum aluno cadastrado.")
        return None

    # Aplicar o algoritmo Jump Search para encontrar o índice do aluno no array
    salto = int(qnta ** 0.5)
    i = 0
    while i < qnta and alunos[i].nome < nome:
        i += salto

    if i >= qnta or alunos[i].nome > nome:
        i -= salto
        for j in range(i, min(i + salto, qnta)):
            if alunos[j].nome == nome:
                return alunos[j]
        return None

    elif alunos[i].nome == nome:
        return alunos[i]

    return None


def cadastrarAluno(arquivo: IO, caminho: str) -> IO:
    aluno = Aluno()
    i = 0

    # Abrir o arquivo para escrita
    arquivo = open(caminho, "a")

    # Verificar se o arquivo foi aberto com sucesso
    if not arquivo:
        print("Erro ao abrir o arquivo.")
        exit(1)

    # Ler os dados do aluno
    aluno.nome = input("Digite o nome do aluno: ")
    # Formatando nome
    aluno.nome = aluno.nome.title()
    aluno.matricula = int(input("Digite a matricula do aluno: "))
    aluno.media = 0.0

    # Pedir para o usuário escolher qual documento cadastrar
    opcao_documento = input(
        "Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG: ")

    # Ler o documento escolhido pelo usuário
    if opcao_documento == '1':
        cpf = input("Digite o CPF do aluno (XXX.YYY.ZZZ-SS): ")
        rg = ""
        aluno.documento = Documento(cpf, rg)
    elif opcao_documento == '2':
        rg = input("Digite o RG do aluno (XXX.YYY.ZZZ): ")
        cpf = ""
        aluno.documento = Documento(cpf, rg)
    else:
        print("Opcao invalida.")
        exit(1)

    # Ler as notas do aluno
    aluno.notas = []
    for i in range(3):
        nota = float(input(f"Digite a nota {i+1} do aluno: "))
        aluno.notas.append(nota)
        aluno.media += nota
    aluno.media = aluno.media / 3

    # Escrever os dados do aluno no arquivo
    if opcao_documento == '1':
        arquivo.write(f"{aluno.nome}\t{aluno.matricula}\t{aluno.documento.cpf}\t{aluno.notas[0]:.1f}\t{aluno.notas[1]:.1f}\t{aluno.notas[2]:.1f}\t{aluno.media:.1f}\n")
    else:
        arquivo.write(f"{aluno.nome}\t{aluno.matricula}\t{aluno.documento.rg}\t{aluno.notas[0]:.1f}\t{aluno.notas[1]:.1f}\t{aluno.notas[2]:.1f}\t{aluno.media:.1f}\n")
    return arquivo