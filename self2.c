#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bitree{
    char e;
    struct bitree *l,*r;
}Bitree;

void create(Bitree **tree){
    char c=getchar();
    if(c=='.'){
        *tree=0;
    }else{
        *tree=(Bitree*)malloc(sizeof(Bitree));
        (*tree)->e=c;
        create(&((*tree)->l));
        create(&((*tree)->r));
    }
}

void show(Bitree *p){
    if(p){
        printf("%c",p->e);
        show(p->l);
        show(p->r);
    }
}

void swap(Bitree *p){
    Bitree *t;
    if(p){
        swap(p->l);
        swap(p->r);
        t=p->l;//Swap two children
        p->l=p->r;
        p->r=t;
    }
}

int main(){
    Bitree *tree;
    create(&tree);
    show(tree);
    putchar('\n');
    swap(tree);
    show(tree);
    putchar('\n');
    return 0;
}
