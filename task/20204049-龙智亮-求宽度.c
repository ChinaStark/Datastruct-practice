#include <stdio.h>
#include <stdlib.h>
/*���������Ӵ洢��ͷ�ļ�*/
typedef char datatype;         /*�������ֵ������*/
typedef struct node{           /*��������������*/
  datatype  data;
  struct node  *lchild,*rchild;
}bintnode,*bintree;


bintree createbintree()
{/*����ǰ�������˳����һ�ø����Ķ�����*/
 char ch;
 bintree t;
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


void preorder(bintree t)
  { /*ǰ������������ĵݹ��㷨*/
    if (t) { 
			 printf("%c",t->data);
			 preorder(t->lchild);
			 preorder(t->rchild);
             }
     }
/*�Ҳ��ٸ�������ԭ�ͣ��Լ��ڴ˴���ɺ�������������Ŀ�ȡ����õݹ麯����ǵݹ麯������*/

int  count[100];//ÿһ��Ľڵ����
int MAX = -1;//��������ֵ
void FindWidth(bintree T, int k)
{
	if (T == NULL)  return;
	count[k]++;
	if (MAX < count[k]) MAX = count[k];
	FindWidth(T->lchild, k + 1);
	FindWidth(T->rchild, k + 1);
}

//MAX��Ϊ������

void main()
{bintree root;
    
 /*��������*/   
 printf("������������Ľ��ֵ��");  root=createbintree();
 printf("��������ǰ��������Ϊ��");  preorder(root);
     
 /*�ڴ˴���ɶԸú����ĵ��ã������в���*/
 FindWidth(root,1);
 printf("\n���Ŀ��%d",MAX);
}