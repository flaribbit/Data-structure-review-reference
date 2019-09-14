#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linklist{
    char data;
    struct linklist *next;
}Linklist;

void split(Linklist *head,Linklist *ha,Linklist *hb,Linklist *hc){
    Linklist *s,*p=head->next;//For scanning linklist
    while(s=p){//s points to the current node
        p=s->next;//p points to the next node
        if(s->data>='A'&&s->data<='Z'){
            s->next=ha->next;//Attach whole list to s
            ha->next=s;//Attach s to ha
        }else if(s->data>='0'&&s->data<='9'){
            s->next=hb->next;//Attach whole list to s
            hb->next=s;//Attach s to hb
        }else{
            s->next=hc->next;//Attach whole list to s
            hc->next=s;//Attach s to hc
        }
    }
}

void create(Linklist *head,char *raw,int len){
    char *p;//For scanning raw string
    Linklist *s;//For new node
    for(p=raw;*p;p++){
        s=(Linklist*)malloc(sizeof(Linklist));//Create new node
        s->data=*p;//Store data
        s->next=head->next;//Attach whole list to s 
        head->next=s;//Attach s to head
    }
}

void show(Linklist *p){
    printf("[]");//Print a head
    while(p=p->next){//Print every nodes
        printf(" -> %c",p->data);
    }
    putchar('\n');
}

void init(Linklist **head){
    *head=(Linklist*)malloc(sizeof(Linklist));
    (*head)->next=0;
}

int main(){
    char *raw="D4J^I2O$W8&SH4$OI(3=DW",i;
    Linklist *list[4];
    for(i=0;i<4;i++){
        init(list+i);
    }
    create(*list,raw,strlen(raw));
    show(list[0]);
    split(list[0],list[1],list[2],list[3]);
    show(list[1]);
    show(list[2]);
    show(list[3]);
    return 0;
}
