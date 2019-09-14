#include <stdio.h>
#include <stdlib.h>
#define newline putchar('\n')

typedef int datatype;

typedef struct node{
    datatype data;
    struct node *next;
}lklist;

void create(lklist *head,datatype *data,int len){
    lklist *p,*tail;
    int i;
    for(i=0,tail=head;i<len;i++){
        p=(lklist*)malloc(sizeof(lklist));
        p->data=*(data+i);
        p->next=tail->next;
        tail->next=p;
        tail=p;
    }
}

void show(lklist *head){
    lklist *p=head;
    printf("[]");
    while(p=p->next){
        printf(" -> %d",p->data);
    }
    newline;
}

void init(lklist **head){
    *head=(lklist*)malloc(sizeof(lklist));
    (*head)->next=0;
}

void mergelklist(lklist *ha,lklist *hb,lklist **hc)
{
    lklist *head=*hc,*s=*hc=0;//Deal with head node
    ha=ha->next;//
    hb=hb->next;//
    while(ha!=0 && hb!=0)
        if(ha->data<hb->data){if(s==0) *hc=s=ha; else {s->next=ha; s=ha;};ha=ha->next;}
        else {if(s==0) *hc=s=hb; else {s->next=hb; s=hb;};hb=hb->next;}
    if(ha==0) s->next=hb; else s->next=ha;
    head->next=*hc;//Deal with head node
    *hc=head;
}

int main(){
    int raw1[]={1,3,5},raw2[]={2,4,6,7},i;
    lklist *list[3];
    for(i=0;i<3;i++){
        init(list+i);//
    }
    create(*(list+1),raw1,3);
    create(*(list+2),raw2,4);
    show(*(list+1));
    show(*(list+2));
    mergelklist(*(list+1),*(list+2),list);
    show(*list);
}
