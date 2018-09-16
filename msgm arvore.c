#include <stdio.h>
#include <stdlib.h>

struct node{
    int valor;
    struct node *esquerda;
    struct node *direita;
};
struct node *inserir(int valor, struct node *arvore){
    if(arvore == NULL){
        struct node *novo = (struct node *)malloc(sizeof(struct node));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arvore = novo;
    }
    else{
        if(valor <= arvore->valor){
            arvore->esquerda =  inserir(valor, arvore->esquerda);
        }
        else{
            arvore-> direita = inserir(valor, arvore->direita);
        }
    }
    return arvore;
}
void PreOrder(struct node *raiz){
    if(raiz != NULL){
        printf(" %d", raiz->valor);
        PreOrder(raiz->esquerda);
        PreOrder(raiz->direita);
    }
}
void InOrder(struct node *raiz){
    if(raiz != NULL){
        InOrder(raiz->esquerda);
        printf(" %d", raiz->valor);
        InOrder(raiz->direita);
    }
}
void PosOrder(struct node *raiz){
    if(raiz != NULL){
        PosOrder(raiz->esquerda);
        PosOrder(raiz->direita);
        printf(" %d", raiz->valor);
    }
}
int main(void)
{
    int testes, i, valorAtual, elementos, valor;
    scanf("%d", &testes);
    for(i=1; i <= testes; i++){
        scanf("%d", &elementos);
        struct node *raiz = (struct node *)malloc(sizeof(struct node));
        raiz = NULL;

        for(valorAtual = 0; valorAtual < elementos; valorAtual++){
            scanf("%d", &valor);
            if(valorAtual == 0){
                raiz = inserir(valor, raiz);
            }
            else
                inserir(valor, raiz);
        }
        printf("Case %d:\n", i);

        printf("Pre.:");
        PreOrder(raiz);
        printf("\n");

        printf("In..:");
        InOrder(raiz);
        printf("\n");

        printf("Post:");
        PosOrder(raiz);
        printf("\n\n");

    }
    return 0;
}
