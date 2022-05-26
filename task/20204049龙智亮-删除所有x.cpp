#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
/************************************/
/* 链表实现的头文件，文件名slnklist.h */
/************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;


/*****************************************************/
/*  函数功能：建立一个空的单链表                     */
/*  函数参数：无                                     */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：slnklist.c，函数名：init()                    */
/******************************************************/
 node *init() /*建立一个空的单链表*/
 {
   return NULL;
 }


/****************************************************/
/*  函数功能：输出单链表中各个结点的值              */
/*  函数参数：指向node类型变量的指针head           */
/*  函数返回值：空                                  */
/*  文件名slnklist.c，函数名display()                  */
/*****************************************************/
 void display(node *head)
 {
   node *p;
   p=head;
   if(!p) printf("单链表是空的！\n");
   else
     {
       printf("单链表各个结点的值为：");
       while(p) { printf("%5d",p->info);p=p->next;}
       printf("\n");
     }
 }


/*****************************************************/
/*  函数功能：在单链表中查找第i个结点的存放地址     */
/*  函数参数：指向node类型变量的指针head，int型变量i*/
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：slnklist.c，函数名：find()                  */
/*****************************************************/
 node *find(node *head,int i)
 {
   int j=1;
   node *p=head;
   if(i<1) return NULL;
   while(p&&i!=j)
   {
     p=p->next;j++;
   }
   return p;
 }


/*****************************************************/
/*  函数功能：单链表第i个结点后插入值为x的新结点   */
/*  函数参数：指向node类型变量的指针head            */
/*            datatype 类型变量x，int型变量i          */
/*  函数返回值：指向node类型变量的指针              */
/* 文件名：slnklist.c，函数名：insert()       */
/*****************************************************/
 node *insert(node *head,datatype x,int i)
 {
   node *p,*q;
   q=find(head,i);/*查找第i个结点*/
   if(!q&&i!=0)
       printf("\n找不到第%d个结点，不能插入%d！",i,x);
   else{
        p=(node*)malloc(sizeof(node));/*分配空间*/
        p->info=x;/*设置新结点*/
        if(i==0){/* 插入的结点作为单链表的第一个结点*/
                  p->next=head;  /*插入(1)*/
                  head=p; /*插入(2)*/
                }
        else {
              p->next=q->next;/*插入(1)*/
              q->next=p;/*插入(2)*/
             }
       }
   return head;
 }


node *deleallx(node *head,datatype x)  /*将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    node* p1 = head;
    node* p = head->next;
    while (p)
    {
        if (head->info == x) {
            head = head->next;
        }
        if (p->info == x) {
         
            
            p = p->next;
            p1->next = p;
     
            
        }
        else {
            p1 = p1->next;
            p = p->next;
        }
    }
    return head;

}


void main()
{node *L; 
 datatype y;
 int j,n;

 L=init();

 /*建表*/
 printf("请输入单链表的结点个数：");  scanf("%d",&n);
 printf("请输入单链表的结点值：");
 for(j=0;j<n;j++)
   {scanf("%d",&y);  L=insert(L,y,j);}
 display(L);
 int x;
 printf("请输入你要删除的值:");
 scanf("%d", &x);
 /*在此处完成对deleallx函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
 display(deleallx(L, x));
}


