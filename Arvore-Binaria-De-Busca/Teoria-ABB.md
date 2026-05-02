# Teoria - Arvore Binaria de Busca (ABB)

## 1. O que e uma ABB
Uma Arvore Binaria de Busca (ABB) e uma estrutura de dados hierarquica formada por nos.
Cada no armazena um valor e possui no maximo dois filhos:
- filho da esquerda
- filho da direita

A regra principal da ABB e:
- todo valor na subarvore esquerda e menor que o valor do no atual
- todo valor na subarvore direita e maior que o valor do no atual

Essa propriedade permite buscar valores de forma eficiente, descartando metade das possibilidades a cada decisao (esquerda ou direita).

## 2. Conceitos fundamentais
- Raiz: primeiro no da arvore.
- Folha: no sem filhos.
- Subarvore: qualquer no com seus descendentes.
- Altura: maior numero de arestas da raiz ate uma folha.
- Nivel/profundidade: distancia da raiz ate um no.

A altura influencia diretamente o desempenho das operacoes.

## 3. Propriedade de ordenacao
A ABB mantem os dados implicitamente ordenados.
Se fizermos o percurso em-ordem (esquerda -> raiz -> direita), os valores saem em ordem crescente.

Isso e uma vantagem importante em relacao a estruturas nao ordenadas.

## 4. Operacoes teoricas principais

### 4.1 Insercao
A insercao comeca na raiz:
- se o valor for menor, caminha para a esquerda
- se for maior, caminha para a direita
- repete ate encontrar uma posicao vazia (NULL)

No seu codigo, valores iguais nao sao inseridos (evita duplicatas), pois so existem os casos < e >.

### 4.2 Busca
A busca segue a mesma logica da insercao:
- compara com o no atual
- vai para esquerda (menor) ou direita (maior)
- para quando encontra o valor ou chega em NULL

### 4.3 Encontrar minimo
Em uma ABB, o menor valor sempre esta no no mais a esquerda.
Basta seguir ponteiros para esquerda ate nao existir mais filho esquerdo.

### 4.4 Remocao
A remocao e a operacao mais importante teoricamente, porque possui 3 casos:

1. No folha (sem filhos):
- remove diretamente.

2. No com um filho:
- o pai do no removido passa a apontar para o filho existente.

3. No com dois filhos:
- substitui o valor do no removido pelo sucessor em-ordem
- sucessor em-ordem = menor valor da subarvore direita
- depois remove o no que forneceu esse valor (agora em caso mais simples)

Essa estrategia preserva a propriedade de busca da ABB.

## 5. Complexidade de tempo
Considere h = altura da arvore.

- Busca: O(h)
- Insercao: O(h)
- Remocao: O(h)
- Minimo: O(h)

### Melhores e piores cenarios
- Caso medio (arvore relativamente balanceada): h ~ log2(n) -> O(log n)
- Pior caso (arvore degenerada, parecida com lista): h ~ n -> O(n)

Logo, a performance depende de quao balanceada a arvore fica apos as insercoes.

## 6. Complexidade de espaco
- Cada no armazena: valor + 2 ponteiros.
- Espaco total: O(n), onde n e o numero de nos.
- Como o codigo usa recursao, ha custo adicional da pilha de chamadas: O(h).

## 7. Relacao com o seu arquivo ABB.c
Seu arquivo implementa corretamente os blocos teoricos centrais da ABB:

- criar_ABB: cria no e inicializa filhos com NULL.
- inserir_ABB: aplica regra de ordenacao da ABB na insercao.
- buscar_ABB: usa comparacao para eliminar metade das opcoes por nivel.
- encontrar_minimo: percorre o caminho mais a esquerda.
- remover_ABB: trata os tres casos classicos de remocao.

Do ponto de vista teorico, a implementacao esta consistente com a definicao formal de ABB.

## 8. Pontos teoricos importantes para evolucao

### 8.1 Balanceamento
A ABB simples nao garante balanceamento automatico.
Se os dados entrarem ordenados, a arvore pode degradar para O(n).

Para garantir O(log n) de forma consistente, usam-se arvores balanceadas, como:
- AVL
- Rubro-Negra

### 8.2 Percursos classicos
Para estudo completo, normalmente incluem-se:
- pre-ordem (raiz -> esquerda -> direita)
- em-ordem (esquerda -> raiz -> direita)
- pos-ordem (esquerda -> direita -> raiz)

### 8.3 Liberacao completa de memoria
Em C, e recomendavel implementar uma funcao para desalocar todos os nos (pos-ordem), evitando vazamento de memoria ao final do programa.

## 9. Resumo teorico
A ABB e uma estrutura eficiente para manter dados dinamicos ordenados.
Sua forca esta na regra:
- menores a esquerda
- maiores a direita

Com isso, busca/insercao/remocao podem ser muito eficientes quando a altura e pequena.
O desempenho real depende do formato da arvore, por isso o balanceamento e o proximo passo natural em estudos avancados.
