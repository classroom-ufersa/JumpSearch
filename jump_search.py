import math 

def jump_search(A, item):
    print("Entre")
    n = len(A)
    m = int(math.sqrt(n))
    i = 0

    while i != len(A)-1 and A[i] < item:
        print("Processamento - {}" .format(A[i: i+m]))
        if A[i+m-1] == item:
            return i+m-1
        elif A[i+m-1] > item:
            B = A[i: i+m-1]
            return search_linear(B, item, i)
        i += m

    B = A[i:i+m]
    print('Processamento - {}' .format(B))
    return search_linear(B, item, i)
