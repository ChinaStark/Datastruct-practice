#pragma warning(disable : 4996)
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


/*�Ҳ��ٸ�������ԭ�ͣ��Լ��ڴ˴���ɺ��������k��Ľ����������õݹ麯����ǵݹ麯������*/
int count[100];//�����洢ÿһ��Ľ�����
void Width(bintree T, int k)
{
	if (T == NULL)  return;
	count[k]++;
	Width(T->lchild, k + 1);
	Width(T->rchild, k + 1);
}

void main()
{bintree root;
    
 /*��������*/   
 printf("������������Ľ��ֵ��");  root=createbintree();
 printf("��������ǰ��������Ϊ��");  preorder(root);
     
 /*�ڴ˴���ɶԸú����ĵ��ã������в���*/
 Width(root, 1);
 int k;
 printf("\n�����ҵڼ��㣺");
 scanf("%d", &k);
 printf("��%d����%d���ڵ�",k,count[k]);
}
