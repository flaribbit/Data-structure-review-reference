#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define newline putchar('\n')

typedef int datatype;

typedef struct node{
    datatype data;
    struct node *next;
}lklist;

void simpleselectsorlklist(lklist **head)
{
    lklist *p,*q,*s,*ha=*head;
    int min,t;
    if(*head==0 ||(*head)->next==0) return;
    //for(q=*head; q!=0;q=q->next)
    for(q=(*head)->next; q!=0;q=q->next)
    {
        min=q->data; s=q;
        for(p=q->next; p!=0;p=p->next) if(min>p->data){min=p->data; s=p;}
        if(s!=q){t=s->data; s->data=q->data; q->data=t;}
    }
}

void create(lklist *head,datatype *data,int len){
    lklist *p;
    int i;
    for(i=0;i<len;i++){
        p=(lklist*)malloc(sizeof(lklist));
        p->data=*(data+i);
        p->next=head->next;
        head->next=p;
    }
}

void init(lklist **head){
    *head=(lklist*)malloc(sizeof(lklist));
    (*head)->next=0;
}

void show(lklist *head){
    lklist *p=head;
    printf("[]");
    while(p=p->next){
        printf(" -> %d",p->data);
    }
    newline;
}

int main(){
    int raw[5]={8,2,6,3,7};
    lklist *list;
    init(&list);
    create(list,raw,5);
    show(list);
    simpleselectsorlklist(&list);
    show(list);
    return 0;
}
