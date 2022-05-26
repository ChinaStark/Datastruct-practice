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
/*  �������ܣ�����һ���յĴ�ͷ���ĵ�����           */
/*  ������������                                     */
/*  ��������ֵ��ָ��node���ͱ�����ָ��             */
/*  �ļ�����hlnklist.c����������init()                    */
/**************************************************** */
 node *init()
 {
   node *head;
   head=(node*)malloc(sizeof(node));
   head->next=NULL;
   return head;
 }


/*****************************************************/
/*  �������ܣ������ͷ���ĵ������и�������ֵ     */
/*  ����������ָ��node���ͱ�����ָ��head            */
/* ��������ֵ����                          */
/*  �ļ�����hlnklist.c����������display()               */
  /*****************************************************/
 void display(node *head)
 {
   node *p;
   p=head->next;/*�ӵ�һ����ʵ�ʣ���㿪ʼ*/
   if(!p) printf("\n��ͷ���ĵ������ǿյ�!");
   else
     {
       printf("\n��ͷ���ĵ������������ֵΪ��\n");
       while(p) { printf("%5d",p->info);p=p->next;}
     }
 }


/*****************************************************/
/*  �������ܣ��ڴ�ͷ���ĵ������в��ҵ�i������ַ */
/*  ����������ָ��node���ͱ�����ָ��head           */
/*             int���ͱ���i                          */
/*  ��������ֵ��ָ��node���ͱ�����ָ��head          */
/*  �ļ���hlnklist.c��������find()                     */
/*****************************************************/
 node *find(node *head,int i)
 {
   int j=0;
   node *p=head;
   if(i<0){printf("\n��ͷ���ĵ������в����ڵ�%d����㣡",i);return NULL;}
   else if(i==0) return p;/*��ʱpָ�����ͷ���*/
   while(p&&i!=j)/*û�в����겢�һ�û���ҵ�*/
   {
     p=p->next;j++;/*��������󣩲��ң���������1*/
   }
   return p;/*���ؽ����i=0ʱ��pָʾ����ͷ���*/
 }


/***********************************************************************/
/*  �������ܣ��ڴ�ͷ���ĵ������е�i���������һ��ֵΪx���½�� */
/*  ����������ָ��node���ͱ�����ָ��head                              */
/*            datatype ���ͱ���x��int�ͱ���i                            */
 /*  ��������ֵ��ָ��node���ͱ�����ָ��head                           */
 /* �ļ�����hlnklist.c����������insert()                     */
 /***********************************************************************/
 node *insert(node *head,datatype x,int i)
 {
   node *p,*q;
   q=find(head,i);/*���Ҵ�ͷ���ĵ������еĵ�i�����*/
                           /*i=0����ʾ�½�������ͷ���֮�󣬴�ʱqָ�����ͷ���*/
   if(!q)/*û���ҵ�*/
   {printf("\n��ͷ���ĵ������в����ڵ�%d����㣡���ܲ���%d��",i,x);return head;}
   p=(node*)malloc(sizeof(node));/*Ϊ׼��������½�����ռ�*/
   p->info=x;/*Ϊ�½������ֵx*/
   p->next=q->next;/*����(1)*/
   q->next=p;/*����(2)����i=0ʱ������qָ�����ͷ��㣬�����ȼ���head>next=p */
   return head;
 }


void splitlist(node *head1,node *head2)  /*������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
{
    int i = 1;
    node* p1,* p2;
    p1 = head1->next;
    p2 = head2;
    while (p1->next)
    {
        p2 ->next= p1->next;
        p2 = p2->next;                
        p1->next = p1->next->next;
        p1 = p1->next;
    }
    p2->next = NULL;


}


void main()
{node *L1,*L2; 
 datatype y;
 int j,n;

 L1=init();  L2=init();

 /*����*/
 printf("�������ͷ��㵥����Ľ�������");  scanf("%d",&n);
 printf("�������ͷ��㵥����Ľ��ֵ��");
 for(j=0;j<n;j++)
   {scanf("%d",&y);  L1=insert(L1,y,j);}

 /*�ڴ˴���ɶ�splitlist�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
 splitlist(L1, L2); display(L1);

 display(L2);
}