#include <stdio.h>
#include <stdlib.h>
#define newline putchar('\n')

typedef struct node{
    int data;
    struct node *lchild, *rchild;
} bitree;

void swapbitree(bitree *bt){
    bitree *p;
    if (bt == 0) return;
    swapbitree(bt->lchild);
    swapbitree(bt->rchild);
    p = bt->lchild;
    bt->lchild = bt->rchild;
    bt->rchild = p;
}

void create(bitree **bt){
    char name=getchar();
    if(name=='.')*bt=NULL;
    else{
        *bt=(bitree*)malloc(sizeof(bitree));
        (*bt)->data=name;
        create(&((*bt)->lchild));
        create(&((*bt)->rchild));
    }
}

void preorder(bitree *root){
    if(root){
        printf("%c",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int main(){
    bitree *tree;
    create(&tree);
    preorder(tree);
    newline;
    swapbitree(tree);
    preorder(tree);
    newline;
    return 0;
}
