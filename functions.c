#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

struct historico *removerLista (struct historico *lista)
{
    struct historico *auxiliar;

    auxiliar = lista -> anterior;

    free (lista);

    return (auxiliar);
}

struct no *removerArvore (struct no *raiz, int numeroBuscado)
{
    if (raiz -> numero == numeroBuscado && raiz -> direita == NULL && raiz -> esquerda == NULL)
    {
        free (raiz);
        raiz = NULL;
    }
    else if (raiz -> numero != numeroBuscado)
    {
        if (numeroBuscado > raiz -> numero)
        {
            raiz -> direita = removerArvore (raiz -> direita, numeroBuscado);
        }
        else if (numeroBuscado < raiz -> numero)
        {
            raiz -> esquerda = removerArvore (raiz -> esquerda, numeroBuscado);
        }
    }

    return (raiz);
};

void mostrarHistorico (struct historico *lista)
{
    struct historico *auxiliar;
    auxiliar = lista;

    printf ("[");

    while (auxiliar != NULL)
    {
        printf (" %i ", auxiliar -> numero);

        auxiliar = auxiliar -> anterior;
    }

    printf ("]\n");
}

struct historico *criarBlocoHistorico (int numeroRecebido)
{
    struct historico *novo;
    novo = (struct historico *) malloc (sizeof(struct historico));

    novo -> numero = numeroRecebido;
    novo -> anterior = NULL;

    return (novo);
};

struct historico *adicionarHistorico (struct historico *lista, struct historico *novo)
{
    novo -> anterior = lista;
    return (novo);
};

void mostrar (int vetor[], int tamanho)
{
    printf ("[");

    for (int i = 0; i < tamanho; i++)
    {
        printf (" %i ", vetor[i]);
    }

    printf ("]\n");
}

void mostrarArvore (struct no *arvore)
{
    if (arvore != NULL)
    {
        mostrarArvore (arvore->esquerda);
        printf (" %i ", arvore->numero);
        mostrarArvore (arvore->direita);
    }
}

struct no *criaBloco (int numeroRecebido)
{
    struct no *novo = (struct no*) malloc (sizeof (struct no));

    novo->numero = numeroRecebido;
    novo->direita = NULL;
    novo->esquerda = NULL;

    return (novo);
};

struct no *inserir (struct no *arvore, int numeroRecebido)
{
    if (arvore == NULL)
    {
        return (criaBloco (numeroRecebido));
    }
    else if (numeroRecebido < arvore->numero)
    {
        arvore->esquerda = inserir (arvore->esquerda, numeroRecebido);
    }
    else if (numeroRecebido > arvore->numero)
    {
        arvore->direita = inserir (arvore->direita, numeroRecebido);
    }

    return (arvore);
};

int buscaBinaria (struct no *arvore, int numeroBuscado)
{
    if (numeroBuscado == arvore->numero)
    {
        printf ("Achei %i!\n", numeroBuscado);
        return (1);
    }
    else if (numeroBuscado > arvore->numero && arvore->direita != NULL)
    {
        buscaBinaria (arvore->direita, numeroBuscado);
    }
    else if (numeroBuscado < arvore->numero && arvore->esquerda != NULL)
    {
        buscaBinaria (arvore->esquerda, numeroBuscado);
    }
    else if (numeroBuscado != arvore->numero)
    {
        printf ("Não achei %i!\n", numeroBuscado);
        return (0);
    }
}
