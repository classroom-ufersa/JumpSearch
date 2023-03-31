from alunos import Aluno
import math

class Aluno1:
    def __init__(self) -> None:
        pass

    def cadastrar_aluno(self,aluno: Aluno):#função pra cadastro
        cadastro = f"{aluno.nome}   {aluno.matricula}   {aluno.documento}\n" #pegando o aluno a ser cadastrado
        arq = open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\src\\alunos.txt','a') #abrindo arquivo 
        arq.write(cadastro) #cadastrando 
        arq.close() #fechando
    
    def listar_aluno(self):
        arq = open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\src\\alunos.txt','r') #abrindo o arquivo pra leitura
        print("Nome   Matricula   Documento")
        for i in arq:
            print(i)

    def ordenar_alunos(self):
        vetor_iniciais = []
        
        arq = open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\src\\alunos.txt','r')
        
        linhas = arq.readlines()

        arq.close()

        for i in linhas:
            vetor_iniciais.append(i[0][0])
        
        #Função para ordenar as vogais
        for i in range(1, len(vetor_iniciais)):
    
            pos = vetor_iniciais[i]
            j = i-1
            while j >= 0 and pos < vetor_iniciais[j] :
                    vetor_iniciais[j + 1] = vetor_iniciais[j]
                    j -= 1
            vetor_iniciais[j + 1] = pos

        #ordenando os nomes com a lista ordenada
        for x in range(0,len(vetor_iniciais)):    
            for y in range(0,len(vetor_iniciais)):
                if vetor_iniciais[x] == linhas[y][0]:
                    aux = linhas[x]
                    linhas[x] = linhas[y]
                    linhas[y] = aux

        result = open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\src\\alunos.txt','w')        
        
        for z in range(0,len(vetor_iniciais)):
            aux2 = linhas[z]
            result.write(aux2)

        result.close

    def jump_search(self, nome, matricula, documento): #função chamada "jump_search" que recebe três parâmetros
        busca = f"{nome} {matricula} {documento}" #cria uma string de busca combinando os parâmetros
        with open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\src\\alunos.txt', 'r') as arquivo: #abre o arquivo no modo leitura
            linhas = arquivo.readlines() #atribui seu conteúdo a uma variável "linhas"
            n = len(linhas) #recebe o número de linhas do arquivo "Aluno.txt"
            jump = int(math.sqrt(n)) #Define o tamanho do salto
            prev = 0 #inicializada com 0 para armazenar a posição anterior em que a busca foi feita
            while jump < n and linhas[jump] <= busca: #Se a linha atual for menor do que "busca", o loop continua com um salto
                prev = jump
                jump += jump
            for i in range(prev, min(jump, n)): #loop por cada linha dentro desse intervalo
                if linhas[i].strip() == busca: #verifica se ela é igual à string de busca "busca"
                    aluno = Aluno(nome, matricula, documento)
                    return f"Nome: {aluno.nome}, Matrícula: {aluno.matricula}, Documento: {aluno.documento}" #cria um objeto aluno e retorna uma string com os detalhes do aluno
        return None #caso a busca não seja bem sucedida
