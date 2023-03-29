<h1 align="center"> Grupo 6: Busca De Strings utilizando JumpSearch 
</h1>

## Problemática:

    Implemente um algoritmo que manipula um tipo estruturado de alunos e possui a funcionalidade de buscar alunos em um arquivo.

- problemática resolvida utilizando as linguagens `Python` e `C`.

## Tópicos

- [Sobre o JumpSearch](#Sobre-o-JumpSearch)
- [Etapas de pesquisa de salto](#etapas-de-pesquisa-de-salto)
    - [Entradas](#entradas)
    - [Saída](#saída)
- [Passos](#passos)
- [Implementação](#implementação)
    - [Em C](#em-c)
    - [Em Python](#em-python)
- [Análise Big-O](#análise-big-o)

## Etapas de pesquisa de salto

### Entradas:

- Array/lista `A` de tamanho `n`
- Chave de pesquisa `item`

### Saída:

- Índice da chave de pesquisa correspondente ou `-1` se `item` não for encontrado

## Passos

- Passo 1: Encontre o comprimento da lista de fontes classificadas `-n = len(A)`
- Passo 2: Determine o Tamanho de Bloco adequado `-m = √n`
- Passo 3: A iteração começa no índice de `i = 0` ate `item` com uma etapa de me continua até que a janela chegue ao final da lista.
- Passo 4: Compare `A[i+m]` ( `i+m` é o último índice de um bloco) e o `item`

    - a) Se `A[i+m] == item`, retorno `i+m`;

    - b) Se `A[i+m] > item`, proceda à busca linear dentro do bloco conhecido como lista derivada `B = A[i: i+m]`
        - Itere e compare cada elemento da lista com a chave de pesquisa e retorne a correspondência, ise encontrada; Saídas de código

    - c) Se `A[i+m] < item`, Prossiga com a próxima iteração para a Etapa 4

- Etapa 5: itere os elementos da lista que não cabem no bloco e retorne o índice correspondente `i`. Se nenhuma correspondência for encontrada, retorne `-1`;

## Implementação

### Em C: 

```c
// Aplicar o algoritmo Jump Search para encontrar o índice do aluno no array
    while (i < qnta && alunos[i].matricula < matricula) // Executa um loop enquanto a matrícula do aluno atual for menor do que a matrícula procurada
    {
        i += salto; // Incrementa o índice do aluno com base no tamanho do salto
    }
    if (i >= qnta || alunos[i].matricula > matricula) // Se o índice do aluno atual for maior ou igual ao tamanho do array de alunos ou a matrícula do aluno atual for maior do que a matrícula procurada
    {
        i -= salto;                                 // Decrementa o índice do aluno com base no tamanho do salto
        for (j = i; j < i + salto && j < qnta; j++) // Executa um loop para percorrer os alunos próximos ao índice do aluno atual, no intervalo [i, i+salto)
        {
            if (alunos[j].matricula == matricula) // Se a matrícula do aluno atual for igual à matrícula procurada
            {
                return &alunos[j]; // Retorna o ponteiro para o aluno encontrado
            }
        }
        return NULL; // Retorna NULL para indicar que não foi encontrado nenhum aluno
    }
    else if (alunos[i].matricula == matricula) // Se a matrícula do aluno atual for igual à matrícula procurada
    {
        return &alunos[i]; // Retorna o ponteiro para o aluno encontrado
    }

    return NULL; // Retorna NULL para indicar que não foi encontrado nenhum aluno
}
```
### Em Python:

```py
def jump_search(self, nome, documento, matricula):
        busca = f"{nome}   {matricula}   {documento}"
        with open('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\src\\alunos.txt', 'r') as arquivo:
            linhas = arquivo.readlines()
            n = len(linhas)
            jump = int(math.sqrt(n))
            prev = 0
            while jump < n and linhas[jump] <= busca:
                prev = jump
                jump += jump
            for i in range(prev, min(jump, n)):
                if linhas[i].strip() == busca:
                    aluno = Aluno(nome, matricula, documento)
                    return f"Nome: {aluno.nome}, Documento: {aluno.documento}, Matrícula: {aluno.matricula}"
        return None
```


## Análise Big-O

Vamos fazer uma análise mais geral de como o Jump Search funciona. Mais uma vez, consideraremos o pior cenário em que o elemento a ser encontrado está no final da lista.

Para obter uma lista de `n` elementos e um tamanho de bloco de `m`, a Pesquisa de salto realizaria `n/m` saltos de maneira ideal. Considerando o tamanho do bloco √n, o tempo de execução também seria `O(√n)`.

Isso coloca a pesquisa de salto entre a pesquisa linear (pior) com uma complexidade de tempo de execução de O(n)e a pesquisa binária (melhor) com uma complexidade de tempo de execução de O(log n). Portanto, o Jump Search pode ser usado em locais onde a pesquisa binária não é viável e a pesquisa linear é muito cara. 

![Complexidade](https://github.com/classroom-ufersa/JumpSearch/blob/develop/Figura.png)

