#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main()
{
    struct no *arvore;
    arvore = NULL;

    struct historico *lista;
    lista = NULL;

    int opcao;

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

    return (0);
}
