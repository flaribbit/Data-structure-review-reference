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

void merge(Linklist *head,Linklist *ha,Linklist *hb){
    Linklist *p=head,*pa=ha->next,*pb=hb->next;
    while(pa&&pb){
        if(pa->data>pb->data){
            p->next=pa;//Attach pa node to main list
            pa=pa->next;
        }else{
            p->next=pb;//Attach pb node to main list
            pb=pb->next;
        }
        p=p->next;
    }
    p->next=pa?pa:pb;
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

int main(){
    int raw1[]={1,3,5,7},raw2[]={2,4},i;
    Linklist *list[3];
    for(i=0;i<3;i++){
        init(list+i);
    }
    create(list[1],raw1,4);
    create(list[2],raw2,2);
    show(list[1]);
    show(list[2]);
    merge(list[0],list[1],list[2]);
    show(*list);
    return 0;
}
