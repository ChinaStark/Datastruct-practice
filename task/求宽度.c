#include <stdio.h>
#include <stdlib.h>
/*二叉树链接存储的头文件*/
typedef char datatype;         /*结点属性值的类型*/
typedef struct node{           /*二叉树结点的类型*/
  datatype  data;
  struct node  *lchild,*rchild;
}bintnode,*bintree;


bintree createbintree()
{/*按照前序遍历的顺序建立一棵给定的二叉树*/
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
  { /*前序遍历二叉树的递归算法*/
    if (t) { 
			 printf("%c",t->data);
			 preorder(t->lchild);
			 preorder(t->rchild);
             }
     }
/*我不再给出函数原型，自己在此处完成函数：求二叉树的宽度。采用递归函数或非递归函数都行*/

int  count[100];//每一层的节点个数
int MAX = -1;//最大结点个数值
void FindWidth(bintree T, int k)
{
	if (T == NULL)  return;
	count[k]++;
	if (MAX < count[k]) MAX = count[k];
	FindWidth(T->lchild, k + 1);
	FindWidth(T->rchild, k + 1);
}

//MAX即为所求宽度

void main()
{bintree root;
    
 /*建二叉树*/   
 printf("请输入二叉树的结点值：");  root=createbintree();
 printf("二叉树的前序遍历结果为：");  preorder(root);
     
 /*在此处完成对该函数的调用，并进行测试*/
 FindWidth(root,1);
 printf("\n树的宽度%d",MAX);
}
