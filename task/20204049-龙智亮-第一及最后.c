#include <stdio.h>
#include <stdlib.h>
/*���������Ӵ洢��ͷ�ļ�*/
typedef char datatype;         /*�������ֵ������*/
typedef struct node{           /*��������������*/
  datatype  data;
  struct node  *lchild,*rchild;
}bintnode,*bintree;

bintree stack[100];//��������ջ
int top = 0;
bintree stack1[100];
int top1 = 0;

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
			 stack1[top1++] = t;
			 preorder(t->lchild);
			 preorder(t->rchild);
             }
     }


void postorder(bintree t)
  { /*��������������ĵݹ��㷨*/
    if (t) { 
			 postorder(t->lchild);
			 postorder(t->rchild);
			 printf("%c",t->data);
			 stack[top++] = t;
             }
     }


/*�Ҳ��ٸ�������ԭ�ͣ��Լ��ڴ˴���ɺ�������ǰ������µ����һ���㡣���õݹ麯����ǵݹ麯������*/
void pre(bintree t)
{ /*��������������ĵݹ��㷨*/
	printf("\npre's last: %c", stack1[top - 1]->data);
}

/*�Ҳ��ٸ�������ԭ�ͣ��Լ��ڴ˴���ɺ��������������µĵ�һ���㡣���õݹ麯����ǵݹ麯������*/
void post(bintree t)
{ /*��������������ĵݹ��㷨*/
	printf("\npost's front: %c", stack[0]->data);
}

void main()
{bintree root;
    
 /*��������*/   
 printf("������������Ľ��ֵ��");  root=createbintree();
 printf("��������ǰ��������Ϊ��");  preorder(root);
 printf("\n�������ĺ���������Ϊ��");  postorder(root);
     
 /*�ڴ˴���ɶ����������ĵ��ã������в���*/
  pre(root);
  post(root);

}
