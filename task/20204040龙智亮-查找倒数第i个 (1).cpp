#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
/************************************/
/* ����ʵ�ֵ�ͷ�ļ����ļ���slnklist.h */
/************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;


/*****************************************************/
/*  �������ܣ�����һ���յĵ�����                     */
/*  ������������                                     */
/*  ��������ֵ��ָ��node���ͱ�����ָ��              */
/*  �ļ�����slnklist.c����������init()                    */
/******************************************************/
 node *init() /*����һ���յĵ�����*/
 {
   return NULL;
 }


/****************************************************/
/*  �������ܣ�����������и�������ֵ              */
/*  ����������ָ��node���ͱ�����ָ��head           */
/*  ��������ֵ����                                  */
/*  �ļ���slnklist.c��������display()                  */
/*****************************************************/
 void display(node *head)
 {
   node *p;
   p=head;
   if(!p) printf("�������ǿյģ�\n");
   else
     {
       printf("�������������ֵΪ��");
       while(p) { printf("%5d",p->info);p=p->next;}
       printf("\n");
     }
 }


/*****************************************************/
/*  �������ܣ��ڵ������в��ҵ�i�����Ĵ�ŵ�ַ     */
/*  ����������ָ��node���ͱ�����ָ��head��int�ͱ���i*/
/*  ��������ֵ��ָ��node���ͱ�����ָ��              */
/*  �ļ�����slnklist.c����������find()                  */
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
/*  �������ܣ��������i���������ֵΪx���½��   */
/*  ����������ָ��node���ͱ�����ָ��head            */
/*            datatype ���ͱ���x��int�ͱ���i          */
/*  ��������ֵ��ָ��node���ͱ�����ָ��              */
/* �ļ�����slnklist.c����������insert()       */
/*****************************************************/
 node *insert(node *head,datatype x,int i)
 {
   node *p,*q;
   q=find(head,i);/*���ҵ�i�����*/
   if(!q&&i!=0)
       printf("\n�Ҳ�����%d����㣬���ܲ���%d��",i,x);
   else{
        p=(node*)malloc(sizeof(node));/*����ռ�*/
        p->info=x;/*�����½��*/
        if(i==0){/* ����Ľ����Ϊ������ĵ�һ�����*/
                  p->next=head;  /*����(1)*/
                  head=p; /*����(2)*/
                }
        else {
              p->next=q->next;/*����(1)*/
              q->next=p;/*����(2)*/
             }
       }
   return head;
 }


node *searchlasti(node *head,int i)  /*������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
{
    int o, j;
    o = j = 1;
    node* p, * q;
    p = q = head;
    while (p)
    {
        if (j - o == i) {
            q = q->next;
            o++;
        }
        p = p->next;
        j++;
    }
    return q;

}


void main()
{node *L; 
 datatype y;
 int j,n;

 L=init();

 /*����*/
 printf("�����뵥����Ľ�������");  scanf("%d",&n);
 printf("�����뵥����Ľ��ֵ��");
 for(j=0;j<n;j++)
   {scanf("%d",&y);  L=insert(L,y,j);}
 display(L);

 /*�ڴ˴���ɶ�searchlasti�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
 int x;
 printf("�����뵹���ڼ����ڵ�:");
 scanf("%d", &x);

 printf("������%d�Ľ��ֵΪ%5d\n",x,searchlasti(L, x)->info);
 display(searchlasti(L, x));
}









