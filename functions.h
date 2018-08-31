struct no
{
    int numero;
    struct no *direita;
    struct no *esquerda;
};

void preencher (int vetor[], int tamanho);
void mostrar (int vetor[], int tamanho);
void embaralhar (int vetor[], int tamanho);
struct no *preencherArvore (int vetor[], int tamanho, struct no *arvore);
struct no *inserir (struct no *arvore, int numeroRecebido);
struct no *criaBloco (int numeroRecebido);
void mostrarArvore (struct no *arvore);
