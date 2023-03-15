# Importação das bibliotecas necessárias
import os

# Abertura do arquivo
try:
    arquivo = open("Jumpsearch.py\\data\\aluno.txt", "r")
except:
    print("Erro ao abrir arquivo!")
    exit(1)

# Exibição do cabeçalho
print("Bem-vindo ao Programa de Gerenciamento de Alunos!")
print("Este programa gerencia os alunos.")
print("Autores: Jhoan, Abner, Caio, Tomaz\t\tVersao:1.0")

# Loop principal
controle = 0
while controle != 6:
    # Exibição do menu
    print("\n\nMenu:\n1-Buscar aluno\n2-Listar Alunos\n3-Matricular alunos\n4-Lancar notas\n5-Alterar dados de um aluno\n6-Sair\n\nDigite sua opcao: ")
    controle = int(input())
    os.system('cls' if os.name == 'nt' else 'clear')  # Limpa a tela do terminal
    # Tratamento da opção escolhida pelo usuário
    if controle == 1:
        pass  # Implemente o código para buscar aluno
    elif controle == 2:
        pass  # Implemente o código para listar alunos
    elif controle == 3:
        pass  # Implemente o código para matricular alunos
    elif controle == 4:
        pass  # Implemente o código para lançar notas
    elif controle == 5:
        pass  # Implemente o código para alterar dados de um aluno
    elif controle == 6:
        print("Obrigado por usar meu programa!")
    else:
        print("Opção inválida!")
# Fechamento do arquivo
arquivo.close()
