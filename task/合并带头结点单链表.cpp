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
/*  函数功能：建立一个空的带头结点的单链表           */
/*  函数参数：空                                     */
/*  函数返回值：指向node类型变量的指针             */
/*  文件名：hlnklist.c，函数名：init()                    */
/**************************************************** */
 node *init()
 {
   node *head;
   head=(node*)malloc(sizeof(node));
   head->next=NULL;
   return head;
 }


/*****************************************************/
/*  函数功能：输出带头结点的单链表中各个结点的值     */
/*  函数参数：指向node类型变量的指针head            */
/* 函数返回值：无                          */
/*  文件名：hlnklist.c，函数名：display()               */
  /*****************************************************/
 void display(node *head)
 {
   node *p;
   p=head->next;/*从第一个（实际）结点开始*/
   if(!p) printf("\n带头结点的单链表是空的!");
   else
     {
       printf("\n带头结点的单链表各个结点的值为：\n");
       while(p) { printf("%5d",p->info);p=p->next;}
       printf("\n");
     }
 }


/*****************************************************/
/*  函数功能：在带头结点的单链表中查找第i个结点地址 */
/*  函数参数：指向node类型变量的指针head           */
/*             int类型变量i                          */
/*  函数返回值：指向node类型变量的指针head          */
/*  文件名hlnklist.c，函数名find()                     */
/*****************************************************/
 node *find(node *head,int i)
 {
   int j=0;
   node *p=head;
   if(i<0){printf("\n带头结点的单链表中不存在第%d个结点！",i);return NULL;}
   else if(i==0) return p;/*此时p指向的是头结点*/
   while(p&&i!=j)/*没有查找完并且还没有找到*/
   {
     p=p->next;j++;/*继续向后（左）查找，计数器加1*/
   }
   return p;/*返回结果，i=0时，p指示的是头结点*/
 }


/***********************************************************************/
/*  函数功能：在带头结点的单链表中第i个结点后插入一个值为x的新结点 */
/*  函数参数：指向node类型变量的指针head                              */
/*            datatype 类型变量x，int型变量i                            */
 /*  函数返回值：指向node类型变量的指针head                           */
 /* 文件名：hlnklist.c，函数名：insert()                     */
 /***********************************************************************/
 node *insert(node *head,datatype x,int i)
 {
   node *p,*q;
   q=find(head,i);/*查找带头结点的单链表中的第i个结点*/
                           /*i=0，表示新结点插入在头结点之后，此时q指向的是头结点*/
   if(!q)/*没有找到*/
   {printf("\n带头结点的单链表中不存在第%d个结点！不能插入%d！",i,x);return head;}
   p=(node*)malloc(sizeof(node));/*为准备插入的新结点分配空间*/
   p->info=x;/*为新结点设置值x*/
   p->next=q->next;/*插入(1)*/
   q->next=p;/*插入(2)，当i=0时，由于q指向的是头结点，本语句等价于head>next=p */
   return head;
 }


node *mergelist(node *head1,node *head2)  /*将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    node* p = head1->next;
    node* p2;
    head2 = head2->next;
    while (head2)
    {
        p2 = head2;
        if (head2->info > p->info) {
            if (p->next)
            {
                if (head2->info > p->next->info) {
                    p = p->next;
                }
                else {
                    head2 = head2->next;
                    p2->next = p->next;
                    p->next = p2;
                    p = p->next;
                    
                }
            }
            else {
                p->next = p2;
                break;
            }
        }
        else {
            head2 = head2->next;
            p2->next = head1->next;
            head1->next = p2;
        }
    }
    return head1;

}


void main()
{node *L1,*L2; 
 datatype y;
 int j,n;

 L1=init();  L2=init();

 /*建表*/
 printf("请输入带头结点单链表A的结点个数：");  scanf("%d",&n);
 printf("请输入带头结点单链表A的结点值：");
 for(j=0;j<n;j++)
   {scanf("%d",&y);  L1=insert(L1,y,j);}
 display(L1);

 printf("请输入带头结点单链表B的结点个数：");  scanf("%d",&n);
 printf("请输入带头结点单链表B的结点值：");
 for(j=0;j<n;j++)
   {scanf("%d",&y);  L2=insert(L2,y,j);}
 display(L2);
 

 display(mergelist(L1, L2));
 /*在此处完成对mergelist函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/

}
