class Aluno:
    def __init__(self, nome, matricula, notas):
        self.nome = nome
        self.matricula = matricula
        self.notas = notas
        self.media = sum(self.notas) / len(self.notas)
