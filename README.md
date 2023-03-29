# Grupo 6: Busca De Strings utilizando JumpSearch

Implemente um algoritmo que manipula um tipo estruturado de alunos e possui a funcionalidade de buscar alunos em um arquivo.

Feito em Python e em C.

## Sobre o JumpSearch

O jump search é um algoritmo de busca em um array ordenado que permite encontrar o valor de um elemento específico de forma eficiente. Ele é baseado na ideia de "saltar" para a próxima posição de busca em vez de percorrer todo o array item por item.

O algoritmo começa por definir o tamanho do "salto" que será utilizado para buscar o elemento desejado. Em seguida, ele realiza saltos sequenciais até encontrar uma posição cujo valor seja maior ou igual ao valor desejado.

A partir deste ponto, o algoritmo realiza uma busca linear nos elementos do bloco anterior até encontrar o valor desejado ou determinar que ele não existe no array.

bem mais eficiente do que uma busca linear.

## Análise Big-O

Vamos fazer uma análise mais geral de como o Jump Search funciona. Mais uma vez, consideraremos o pior cenário em que o elemento a ser encontrado está no final da lista.

Para obter uma lista de nelementos e um tamanho de bloco de m, a Pesquisa de salto realizaria n/msaltos de maneira ideal. Considerando o tamanho do bloco √n, o tempo de execução também seria O(√n).

Isso coloca a pesquisa de salto entre a pesquisa linear (pior) com uma complexidade de tempo de execução de O(n)e a pesquisa binária (melhor) com uma complexidade de tempo de execução de O(log n). Portanto, o Jump Search pode ser usado em locais onde a pesquisa binária não é viável e a pesquisa linear é muito cara. 

<div>
  <img src="https://github.com/classroom-ufersa/JumpSearch/blob/develop/Figura.png" width="300" height="300">
</div>