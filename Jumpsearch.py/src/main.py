from alunos import Aluno
from jump import Aluno1

op = 0 

print("+----------------------------------------------------------------+\n"
           "|        Bem-vindo ao Programa de Gerenciamento de Alunos        |\n"
           "|                                                                |\n"
           "|             Autores: Jhoan   Abner   Caio    Tomaz             |\n"
           "|                                                                |\n"
           "|                          Versao: 2.0                           |\n"
           "+----------------------------------------------------------------+");
while op != 4:
    
    op = int(input('\nMenu\n1 - Matricular alunos\n2 - Listar alunos matriculados\n3 - Buscar aluno\n4 - Fechar programa\nDigite sua opção: '))

    if op == 1:
        nome = input('Digite o nome do aluno: ')
        matricula = int(input('Digite a matricula do aluno: '))
        documento = int(input('Digite o documento do aluno: '))
        aluno = Aluno(nome,matricula,documento)
        Aluno1 = Aluno1()
        Aluno1.cadastrar_aluno(aluno)
        Aluno1.ordenar_alunos()
        
    elif op == 2:
        print('\n')
        Aluno1 = Aluno1()
        Aluno1.listar_aluno()
    
    elif op == 3:
        nome = input('Digite o nome do aluno que deseja ver os dados: ')
        matricula = int(input('Digite a matricula: '))
        documento = int(input('Digite seu documento: '))
        Alunoz = Aluno1()
        busca_aluno = Alunoz.jump_search(nome, matricula, documento)
        print(busca_aluno)
    
    elif op == 4:
        print('Obrigado por usar esse programa!')