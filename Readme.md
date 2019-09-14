## 实验复习(本周五前，1班上传1，2，3题完整答案；2班上传4，5，6完整答案。具体任务由班长安排)

执行 `make all && rev1 && rev2 && rev3` 编译所有程序并运行

对于程序2，测试的输入数据为 `ab..cd...` ，其他程序自带了测试数据

### 1.  设单链表中有仅三类字符的数据元素(大写字母、数字和其它字符)，要求利用原单链表中结点空间设计出三个单链表的算法，使每个单链表只包含同类字符。
```C
typedef char datatype;
typedef struct node {datatype data; struct node *next;}lklist;
void split(lklist *head,lklist *&ha,lklist *&hb,lklist *&hc)
{
   lklist *p; ha=0,hb=0,hc=0;
   for(p=head;p!=0;p=head)
   {
    head=p->next; p->next=0;
    if (p->data>='A' && p->data<='Z') {p->next=ha; ha=p;}
    else if (p->data>='0' && p->data<='9') {p->next=hb; hb=p;} else {p->next=hc; hc=p;}
   }
}
```

### 2. 设计在链式存储结构上交换二叉树中所有结点左右子树的算法。
```C
typedef struct node {int data; struct node *lchild,*rchild;} bitree;
void swapbitree(bitree *bt)
{
   bitree *p;
   if(bt==0) return;
swapbitree(bt->lchild); swapbitree(bt->rchild);
p=bt->lchild; bt->lchild=bt->rchild; bt->rchild=p;
}
```

### 3. 设计两个有序单链表的合并排序算法。
```C
void mergelklist(lklist *ha,lklist *hb,lklist *&hc)
{
   lklist *s=hc=0;
   while(ha!=0 && hb!=0)
     if(ha->data<hb->data){if(s==0) hc=s=ha; else {s->next=ha; s=ha;};ha=ha->next;}
     else {if(s==0) hc=s=hb; else {s->next=hb; s=hb;};hb=hb->next;}
   if(ha==0) s->next=hb; else s->next=ha;
}
```

### 4. 设计一个求结点x在二叉树中的双亲结点算法。
```C
typedef struct node {datatype data; struct node *lchild,*rchild;} bitree;
bitree *q[20]; int r=0,f=0,flag=0;
void preorder(bitree *bt, char x)
{
  if (bt!=0 && flag==0)
if (bt->data==x) { flag=1; return;}
else {r=(r+1)% 20; q[r]=bt; preorder(bt->lchild,x); preorder(bt->rchild,x); }
}
void parent(bitree *bt,char x)
{
   int i;
   preorder(bt,x);
   for(i=f+1; i<=r; i++) if (q[i]->lchild->data==x || q[i]->rchild->data) break;
   if (flag==0) printf("not found x\n");
   else if (i<=r) printf("%c",bt->data); else printf("not parent");
}
```

### 5. 设计在顺序有序表中实现二分查找的算法。
```C
struct record {int key; int others;};
int bisearch(struct record r[ ], int k)
{
  int low=0,mid,high=n-1;
  while(low<=high)
{
    mid=(low+high)/2;
    if(r[mid].key==k) return(mid+1); else if(r[mid].key>k) high=mid-1; else low=mid+1;
  }
  return(0);
}
```

### 6. 设计在链式结构上实现简单选择排序算法。
```C
void simpleselectsorlklist(lklist *&head)
{
  lklist *p,*q,*s;  int min,t;
  if(head==0 ||head->next==0) return;
  for(q=head; q!=0;q=q->next)
  {
    min=q->data; s=q;
    for(p=q->next; p!=0;p=p->next) if(min>p->data){min=p->data; s=p;}
    if(s!=q){t=s->data; s->data=q->data; q->data=t;}
  }
}
```
