#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "functions.h"

int main()
{
    srand (time (NULL));
    
    struct no *arvore;
    arvore = NULL;
    
    clock_t inicio, fim;
    double tempo;
    
    int tamanho = /*rand()%1000000*/1000000;
    
    int vetor[tamanho];
    
    printf ("Quantidade de números que serão inseridos na árvore: %i\n", tamanho);
    
    preencher (vetor, tamanho);
    
    embaralhar (vetor, tamanho);
    
    printf ("Alocando nós...\n");
    
    inicio = clock();
    
    arvore = preencherArvore (vetor, tamanho, arvore);
    
    fim = clock();
    
    tempo = ((double) (fim - inicio))/CLOCKS_PER_SEC;
    
    //printf ("[");
    
    //mostrarArvore (arvore);
    
    //printf ("]\n");
    
    printf ("Todos os nós foram alocados! (%.4lf)\n", tempo);
    
    return (0);
}
