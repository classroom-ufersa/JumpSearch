class Alunos():
    def __init__(self, nome, idade, matricula) ->None:
        self.__nome = nome
        self.__idade = idade
        self.__matricula = matricula

    def get_nome(self):
        return self.__nome

    def get_idade(self):
        return self.__idade

    def get_matricula(self):
        return self.__matricula

    def set_nome(self, nome):
        self.__nome = nome

    def set_idade(self, idade):
        self.__idade = idade

    def set_matricula(self, matricula):
        self.__matricula = matricula

    nome = property(fget=getNome,fset=setNome)
    documento = property(fget=getDocumento, fset=setDocumento)
    matricula = property(fget=getMatricula,fset=setMatricula)