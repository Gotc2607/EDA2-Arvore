#include <stdio.h>
#include <stdlib.h>

// Estrutura da Árvore Binária de Busca
typedef struct ABB
{
    int valor;
    struct ABB *esq , *dir;
} ABB;

// Função para criar um novo nó
ABB* criar_ABB(int valor){
    ABB* novo_no = (ABB*)malloc(sizeof(ABB));
    if (novo_no != NULL)
    {
        novo_no->valor = valor;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
    }
    return novo_no; 
}

// Função para inserir um valor na Árvore Binária de Busca
ABB* inserir_ABB(ABB* raiz, int valor){
    // Se a raiz for NULL, cria um novo nó com o valor
    if (raiz == NULL)
    {
        return criar_ABB(valor);
    }

    // Se o valor for menor que o valor da raiz, insere na subárvore esquerda
    if (valor < raiz->valor)
    {
        raiz->esq = inserir_ABB(raiz->esq, valor);
    }
    // Se o valor for maior que o valor da raiz, insere na subárvore direita
    else if (valor > raiz->valor)
    {
        raiz->dir = inserir_ABB(raiz->dir, valor);
    }

    // Retorna a raiz da árvore após a inserção
    return raiz;
}

// Função para buscar um valor na Árvore Binária de Busca
ABB* buscar_ABB(ABB* raiz, int valor){
    // Se a raiz for NULL ou o valor for encontrado, retorna a raiz
    if (raiz == NULL || raiz->valor == valor)
    {
        return raiz;
    }

    // Se o valor for menor que o valor da raiz, busca na subárvore esquerda
    if (valor < raiz->valor)
    {
        return buscar_ABB(raiz->esq, valor);
    }
    // Se o valor for maior que o valor da raiz, busca na subárvore direita
    else
    {
        return buscar_ABB(raiz->dir, valor);
    }
}

// Função para encontrar o nó com o valor mínimo na Árvore Binária de Busca
ABB* encontrar_minimo(ABB* raiz){
    ABB* atual = raiz;

    // Percorre a subárvore esquerda até encontrar o nó mais à esquerda
    while (atual != NULL && atual->esq != NULL)
    {
        atual = atual->esq;
    }

    return atual;
}

// Função para remover um valor da Árvore Binária de Busca
ABB* remover_ABB(ABB* raiz, int valor){
    // Se a raiz for NULL, retorna NULL
    if (raiz == NULL)
    {
        return NULL;
    }

    // Se o valor for menor que o valor da raiz, remove da subárvore esquerda
    if (valor < raiz->valor)
    {
        raiz->esq = remover_ABB(raiz->esq, valor);
    }
    // Se o valor for maior que o valor da raiz, remove da subárvore direita
    else if (valor > raiz->valor)
    {
        raiz->dir = remover_ABB(raiz->dir, valor);
    }
    // Se o valor for igual ao valor da raiz, remove a raiz
    else
    {
        // Caso 1: Nó com apenas um filho ou nenhum filho
        if (raiz->esq == NULL)
        {
            ABB* temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL)
        {
            ABB* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 2: Nó com dois filhos
        ABB* temp = encontrar_minimo(raiz->dir);
        raiz->valor = temp->valor;
        raiz->dir = remover_ABB(raiz->dir, temp->valor);
    }

    return raiz;
}