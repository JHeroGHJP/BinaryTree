#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void preencher (int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
    }
}

void mostrar (int vetor[], int tamanho)
{
    printf ("[");
    
    for (int i = 0; i < tamanho; i++)
    {
        printf (" %i ", vetor[i]);
    }
    
    printf ("]\n");
}

void embaralhar (int vetor[], int tamanho)
{
    int vezes = rand()%10000;
    int indice1;
    int indice2;
    int aux;
    
    for (int i = 0; i < vezes; i++)
    {
        indice1 = rand()%tamanho;
        indice2 = rand()%tamanho;
        
        while (indice1 == indice2)
        {
            indice1 = rand()%tamanho;
            indice2 = rand()%tamanho;
        }
        
        aux = vetor[indice1];
        vetor[indice1] = vetor[indice2];
        vetor[indice2] = aux;
    }
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
    struct no *novo = malloc (sizeof (struct no));
    
    novo->numero = numeroRecebido;
    novo->direita = NULL;
    novo->esquerda = NULL;
    
    return (novo);
}

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
}

struct no *preencherArvore (int vetor[], int tamanho, struct no *arvore)
{
    for (int i = 0; i < tamanho; i++)
    {
        arvore = inserir (arvore, vetor[i]);
    }
    
    return (arvore);
}
