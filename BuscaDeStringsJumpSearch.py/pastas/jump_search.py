import math 

def jump_search(A, item):
    print("Entre")
    n = len(A)
    m = int(math.sqrt(n))
    i = 0

    while i != len(A)-1 and A[i] < item:
        print("Processamento - {}".format(A[i: i+m]))
        if A[i+m-1] == item:
            return i+m-1
        elif A[i+m-1] > item:
            B = A[i: i+m-1]
            return search_linear(B, item, i)
        i += m

    B = A[i:i+m]
    print('Processamento - {}'.format(B))
    return search_linear(B, item, i)

def search_linera(B, item, loc):
    print('\t Pesquisa linear, entrada.')
    i = 0

    while i != len(B):
        if B[i] == item:
            return loc + i
        i += 1
    return -1

if __name__ == "__main__":
    A = [1, 2, 3, 5, 9, 22, 35, 70, 120, 123, 1346, 1345, 1345]
    print(jump_search(A, 1345))