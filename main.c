#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void main()
{
    struct no *arvore;
    arvore = NULL;
    
    int numbers = rand()%INT_MAX;
    
    printf ("Quantidade de números: %i\n", numbers);
}
