import math

def jump_search(string, string_list):
    n = len(string_list)
    jump = int(math.sqrt(n))
    prev = 0
    curr = jump
    while curr < n and string_list[curr] <= string:
        prev = curr
        curr += jump
    for i in range(prev, min(curr, n)):
        if string_list[i] == string:
            return i
    return -1

# entrada do usuário da lista de strings
string_list = input("Digite a lista de strings separadas por vírgula: ").split(",")
string_list = [s.strip() for s in string_list]

# entrada do usuário da string a ser buscada
string = input("Digite a string a ser buscada: ")

# busca da string na lista
pos = jump_search(string, string_list)
if pos != -1:
    print(f"{string} encontrada na posição {pos} da lista")
else:
    print(f"{string} não encontrada na lista")