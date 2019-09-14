#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linklist{
    int data;
    struct linklist *next;
}Linklist;

void create(Linklist *head,int *raw,int len){
    int *p;//For scanning raw list
    Linklist *s;//For new node
    for(p=raw;len-(p-raw);p++){
        s=(Linklist*)malloc(sizeof(Linklist));//Create new node
        s->data=*p;//Store data
        s->next=head->next;//Attach whole list to s 
        head->next=s;//Attach s to head
    }
}

void show(Linklist *p){
    printf("[]");//Print a head
    while(p=p->next){//Print every nodes
        printf(" -> %d",p->data);
    }
    putchar('\n');
}

void init(Linklist **head){
    *head=(Linklist*)malloc(sizeof(Linklist));
    (*head)->next=0;
}

void sort(Linklist *head){
    Linklist *min,*p=head;
    int t;
    while(head=head->next){
        p=min=head;
        while(p=p->next){
            if(p->data<min->data){
                min=p;
            }
        }
        t=head->data;
        head->data=min->data;
        min->data=t;
    }
}

int main(){
    int raw[]={8,9,6,2,7,3,4,5};
    Linklist *list;
    init(&list);
    create(list,raw,8);
    show(list);
    sort(list);
    show(list);
    return 0;
}
