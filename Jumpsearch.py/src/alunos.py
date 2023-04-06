class Aluno(): #criando a classe de aluno e encapsulando
    def __init__(self,nome,matricula,documento) -> None:
        self.__nome = nome
        self.__matricula=matricula
        self.__documento=documento
        pass
    
    def getNome(self):
        return self.__nome
   
    def setNome(self,nome):
        self.__nome = nome
    
    def getMatricula(self):
        return self.__matricula
   
    def setMatricula(self,matricula):
        self.__matricula = matricula
    
    def getDocumento(self):
        return self.__documento
   
    def setDocumento(self,documento):
        self.__documento = documento

    
    nome = property(fget=getNome,fset=setNome)
    documento = property(fget=getDocumento, fset=setDocumento)
    matricula = property(fget=getMatricula,fset=setMatricula)