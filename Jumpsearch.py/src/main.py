import os
from aluno import *
import time
import os
import time

# declarando variaveis
inicio = 0
tempo = 0
controle = 0
totaldealunos = 0
j = 0
alunos = []
caminho = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\JumpSearch\\JumpSearch07.py\\data\\aluno.txt"
# Verificar se o arquivo de alunos já existe
if os.path.isfile(caminho):
    # Ler os alunos do arquivo
    arquivo = open(caminho, "r")
    for linha in arquivo:
        campos = linha.strip().split("\t")
        nome = campos[0]
        matricula = int(campos[1])
        cpf = campos[2]
        rg = campos[3]
        notas = [float(campos[4]), float(campos[5]), float(campos[6])]
        aluno = Aluno(nome, matricula, cpf, rg, notas)
        alunos.append(aluno)
    arquivo.close()
alunotemporario = None

# inicialização inicial do vetor alunos com dados do arquivo

print("+----------------------------------------------------------------+")
print("|        Bem-vindo ao Programa de Gerenciamento de Alunos        |")
print("|                                                                |")
print("|             Autores: Jhoan   Abner   Caio    Tomaz             |")
print("|                                                                |")
print("|                          Versao: 2.0                           |")
print("+----------------------------------------------------------------+\n")

while controle != 6:
    print("Menu:")
    print("========================================")
    print("[1] Atualizar sistema")
    print("[2] Listar Alunos")
    print("[3] Matricular alunos")
    print("[4] Buscar aluno por matricula")
    print("[5] Buscar aluno pelo nome")
    print("[6] Sair")
    print("========================================")

    controle = int(input("Digite o numero da opcao desejada: "))
    os.system("cls" if os.name == "nt" else "clear")

    if controle == 1:
        alunos = ler_arquivo(caminho)
        print("Atualizado!\n\n")

    elif controle == 2:
        ListarAlunos(alunos)

    elif controle == 3:
        cadastrarAluno(arquivo, caminho)

    elif controle == 4:
        inicio = time.time()
        alunotemporario = BuscarAlunoPelaMatricula(alunos)
        tempo = (time.time() - inicio) * 1000  # Milisegundos
        print(f"Tempo de execucao: {tempo:.1f} Milisegundos\n")

        if alunotemporario:
            print("\nAluno Encontrado!\n")
            print(f"Nome: {alunotemporario.nome}")
            print(f"Matricula: {alunotemporario.matricula}")
            
            if len(alunotemporario.documento.cpf) == 14:
                print(f"CPF: {alunotemporario.documento.cpf}")
                
            elif len(alunotemporario.documento.rg) == 11:
                print(f"RG: {alunotemporario.documento.rg}")
            print("Notas: ", end="")
            
            for j in range(3):
                print(f"{alunotemporario.notas[j]:.1f} ", end="")
            print(f"\nMedia: {alunotemporario.media:.1f}\n")

        else:
            print("Aluno Nao foi encontrado!\n")

    elif controle == 5:
        inicio = time.time()
        alunotemporario = BuscarAlunoPeloNome(alunos)
        tempo = (time.time() - inicio) * 1000  # Milisegundos
        print(f"Tempo de execucao: {tempo:.1f} Milisegundos")
        if alunotemporario:
            print("\nAluno Encontrado!\n")
            print(f"Nome: {alunotemporario.nome}")
            print(f"Matricula: {alunotemporario.matricula}")
            
            if len(alunotemporario.documento.cpf) == 14:
                print(f"CPF: {alunotemporario.documento.cpf}")
                
            elif len(alunotemporario.documento.rg) == 11:
                print(f"RG: {alunotemporario.documento.rg}")
            print("Notas: ", end="")
            
            for j in range(3):
                print(f"{alunotemporario.notas[j]:.1f} ", end="")
            print(f"\nMedia: {alunotemporario.media:.1f}\n")

        else:
            print("Aluno Nao foi encontrado!\n")
    elif controle == 6:
        print("Obrigado por usar meu programa!")
    else:
        print("Opcao invalida!")