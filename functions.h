struct no
{
    int numero;
    struct no *direita;
    struct no *esquerda;
};

struct historico
{
    int numero;
    struct historico *anterior;
};

struct historico *removerLista (struct historico *lista);
struct no *removerArvore (struct no *raiz, int numeroBuscado);
void mostrarHistorico (struct historico *lista);
struct historico *criarBlocoHistorico (int numeroRecebido);
struct historico *adicionarHistorico (struct historico *lista, struct historico *novo);
void mostrar (int vetor[], int tamanho);
struct no *inserir (struct no *arvore, int numeroRecebido);
struct no *criaBloco (int numeroRecebido);
void mostrarArvore (struct no *arvore);
int buscaBinaria (struct no *arvore, int numeroBuscado);
