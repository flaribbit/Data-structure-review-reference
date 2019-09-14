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

Bitree *flag=0;
void parent(Bitree *p,char c){
    if(flag){
        return;
    }
    if(p){
        if(p->l&&p->l->e==c||p->r&&p->r->e==c){
            flag=p;
        }
        parent(p->l,c);
        parent(p->r,c);
    }
}

int main(){
    Bitree *tree;
    create(&tree);
    parent(tree,getchar());
    if(flag){
        printf("%c\n",flag->e);
    }else{
        printf("Not found\n");
    }
    return 0;
}
