#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

typedef struct arvore {
    char city [20];
    int temp;
    struct arvore *left;
    struct arvore *right;
    struct arvore *father;
}NoArvore;
typedef struct Arvore{
    int size;
    NoArvore *root;
}Tree;

void init(Tree **tree) {
    (*tree) = (Tree *) malloc(sizeof(Tree));
    (*tree) -> root = NULL;
    (*tree) -> size = 0;
}
NoArvore *iniciaNo(char *cidade, int val) {
    NoArvore *z;
    z = (NoArvore *) malloc(sizeof(NoArvore));
    strcpy(z->city, cidade);
    z -> temp = val ;
    z -> father = NULL;
    z -> left = NULL;
    z -> right = NULL;
    return z;
}
void preorder(NoArvore *node ){
    if (node != NULL) {
        printf("|Cidade: %s, Temperatura: %d|\n", node->city, node->temp);
        preorder(node -> left);
        preorder(node -> right);
    }
}
void inorder(NoArvore *node ){
    if (node != NULL) {
        inorder(node -> left);
        printf("|Cidade: %s, Temperatura: %d|\n", node->city, node->temp);
        inorder(node -> right);
    }
}
void posorder(NoArvore *node ){
    if (node != NULL) {
        posorder(node -> left);
        posorder(node -> right);
        printf("|Cidade: %s, Temperatura: %d|\n", node->city, node->temp);
    }
}
void tree_insert (Tree **tree, char cidade[], int tempInser) {
    NoArvore *y;
    NoArvore *x;
    NoArvore *z;
    y = NULL;
    x = (*tree) -> root;
    while (x != NULL){
        y = x;
        if (x -> temp > tempInser) x = x->left;
        else x = x -> right;
    }
    z = iniciaNo(cidade, tempInser);
    z -> father = y;
    if (y == NULL){
        (*tree) -> root = z;
    }else {
        if ((z->temp) < (y->temp)) y -> left = z;
        else y -> right = z;
    }
    (*tree)->size ++;

}
void menor(NoArvore *r){
    if (r->left != NULL) menor(r->left);
    if (r->left == NULL ) printf("\n\nCidade mais fria: %s, com a temperatura: %d\n\n", r->city, r->temp);
}

int main (int argc, char **argv) {
    Tree *arvore;
    init(&arvore);

    char cidade [20];
    int temperatura;

    while (scanf("%s %d", cidade, &temperatura) != EOF){
        tree_insert(&arvore, cidade, temperatura);
        if (strcmp(cidade,"Waterloo") == 0) break;
    }
    foreground(YELLOW);
    printf("Em Ordem:\n");
    inorder(arvore->root);

    foreground(BLUE);
    printf("\n\nPre-Ordem:\n\n");
    preorder(arvore->root);

    foreground(GREEN);
    printf("\n\nPos-Ordem:\n");
    posorder(arvore->root);

    style(RESETALL);
    menor(arvore->root);

    fflush(stdout);
}

