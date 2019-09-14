#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define newline putchar('\n')

typedef char datatype;

typedef struct node{
    datatype data;
    struct node *next;
}lklist;

void split(lklist *head,lklist **ha,lklist **hb,lklist **hc)
{
    lklist *p=head;
    //*ha=0,*hb=0,*hc=0;
    for(p=head;p!=0;p=head){
        head=p->next;
        p->next=0;
        if(p->data>='A' && p->data<='Z'){
            p->next=(*ha)->next;
            (*ha)->next=p;
        }
        else if(p->data>='0' && p->data<='9'){
            p->next=(*hb)->next;
            (*hb)->next=p;
        }
        else{
            p->next=(*hc)->next;
            (*hc)->next=p;
        }
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
        printf(" -> %c",p->data);
    }
    newline;
}

int main(){
    char *raw="WF2ANK46W+*12G#$FD56",i;
    lklist *list[4];
    for(i=0;i<4;i++){
        init(list+i);
    }
    create(*list,raw,strlen(raw));
    show(*list);
    split(*list,list+1,list+2,list+3);
    for(i=1;i<4;i++){
        show(list[i]);
    }
}
