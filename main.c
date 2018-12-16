#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>
//#include <time.h>

#include "functions.h"

int main()
{
    //srand (time (NULL));

    struct no *arvore;
    arvore = NULL;

    struct historico *lista;
    lista = NULL;

    int opcao;

    //clock_t inicio, fim;
    //sdouble tempo;

    //int tamanho = 10;

    //int vetor[tamanho];

    //printf ("Quantidade de números que serão inseridos na árvore: %i\n", tamanho);

    //preencher (vetor, tamanho);

    //embaralhar (vetor, tamanho);

    //printf ("Alocando nós...\n");

    //inicio = clock();

    do
    {
        printf ("0 - Sair.\n");
        printf ("1 - Inserir.\n");
        printf ("2 - Mostrar.\n");
        printf ("3 - Buscar.\n");
        printf ("4 - Remover última adição.\n");
        printf ("5 - Mostrar histórico de inserção.\n");

        scanf ("%i", &opcao);

        switch (opcao)
        {
            case 1:
            {
                int num;
                printf ("Insira um número: ");
                scanf ("%i", &num);

                if (arvore != NULL && buscaBinaria(arvore, num) == 1)
                {
                    printf ("Não é possível inserir esse número!\n");
                }
                else
                {
                    arvore = inserir (arvore, num);

                    lista = adicionarHistorico (lista, criarBlocoHistorico(num));
                }

            } break;

            case 2:
            {
                printf ("[");
                mostrarArvore(arvore);
                printf ("]\n");
            } break;

            case 3:
            {
                int ans, num;

                printf ("Insira um número para buscar: ");
                scanf ("%i", &num);

                ans = buscaBinaria (arvore, num);
            } break;

            case 4:
            {
                if (lista != NULL)
                {
                    arvore = removerArvore (arvore, lista -> numero);

                    lista = removerLista (lista);
                }
                else
                {
                    printf ("Não é  possível remover nada!\n");
                }

            } break;

            case 5:
            {
                mostrarHistorico (lista);
            } break;
        }
    } while(opcao != 0);

    //arvore = preencherArvore (vetor, tamanho, arvore);

    //fim = clock();

    //tempo = ((double) (fim - inicio))/CLOCKS_PER_SEC;

    //printf ("[");

    //mostrarArvore (arvore);

    //printf ("]\n");

    //printf ("Todos os nós foram alocados! (%.10lf)\n", tempo);

    /*

    int buscar;

    printf ("Digite um número para buscar:");
    scanf ("%i", &buscar);

    inicio = clock();

    buscar = buscaBinaria (arvore, buscar);

    fim = clock();

    tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;

    if (buscar == 0)
    {
        printf ("Número não encontrado! (%.4lf)\n", tempo);
    }
    else if (buscar == 1)
    {
        printf ("Número encontrado! (%.4lf)\n", tempo);
    }

    */

    //medirBusca (arvore, vetor, tamanho);

    return (0);
}
