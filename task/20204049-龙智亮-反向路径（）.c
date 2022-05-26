#include <stdio.h>
#include <stdlib.h>
/*���������Ӵ洢��ͷ�ļ�*/
typedef char datatype;         /*�������ֵ������*/
typedef struct node{           /*��������������*/
  datatype  data;
  struct node  *lchild,*rchild;
}bintnode,*bintree;


typedef struct node1 {
    datatype  data;
    struct node* next;
}nodelink;

nodelink* head;

//ABD##E##CF###
bintree createbintree()       
{/*����ǰ�������˳����һ�ø����Ķ�����*/ 
 char ch;  bintree t;
 if ((ch=getchar())=='#')
      t=NULL;
else {
	t=(bintnode *)malloc(sizeof(bintnode));
	t->data=ch;
	t->lchild=createbintree();
	t->rchild=createbintree();
    }
 return t;
 }

void reverse(nodelink * head,datatype data)
{
    nodelink* p = (nodelink*)malloc(sizeof(nodelink));
    p = head->next;
    printf("\n�ڵ�%c�ķ���·��Ϊ��", data);
    while (p)//�ҵ��ýڵ�
    {if (p->data == data)
        break;  
        p = p->next;
    }
    while (p)//�������иýڵ������ݽ������
    {
        printf("%c", p->data);
        p = p->next;
    }
}

void preorder(bintree t)
{ /*ǰ������������ĵݹ��㷨*/
    if (t) 
	{ 
        printf("%c",t->data);
        nodelink* p = (nodelink*)malloc(sizeof(nodelink));
        p->data = t->data;
        p->next = head->next;//ͷ�巨����ǰ���������������ģ�
        head->next = p;
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void fun(bintree t)
{ /*ǰ������������ĵݹ��㷨*/
    if (t)
    {
        reverse(head, t->data);
        fun(t->lchild);
        fun(t->rchild);
    }
}


/*�Ҳ��ٸ�������ԭ�ͣ��Լ��ڴ˴���ɺ��������������ÿƬҶ�ӵ����ķ���·�������õݹ麯����ǵݹ麯������*/


void main()
{bintree root;
head = (nodelink*)malloc(sizeof(nodelink));
head->next = NULL;
 /*��������*/   
 printf("������������Ľ��ֵ��");  root=createbintree();
 printf("��������ǰ��������Ϊ��");  preorder(root);

 /*�ڴ˴���ɶԸú����ĵ��ã������в���*/
 fun(root);
}