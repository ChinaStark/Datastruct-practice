#include <stdio.h>
#include <stdlib.h>
/*二叉树链接存储的头文件*/
typedef char datatype;         /*结点属性值的类型*/
typedef struct node{           /*二叉树结点的类型*/
  datatype  data;
  struct node  *lchild,*rchild;
}bintnode,*bintree;

bintree stack[100];//建立两个栈
int top = 0;
bintree stack1[100];
int top1 = 0;

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
			 stack1[top1++] = t;
			 preorder(t->lchild);
			 preorder(t->rchild);
             }
     }


void postorder(bintree t)
  { /*后序遍历二叉树的递归算法*/
    if (t) { 
			 postorder(t->lchild);
			 postorder(t->rchild);
			 printf("%c",t->data);
			 stack[top++] = t;
             }
     }


/*我不再给出函数原型，自己在此处完成函数：求前序遍历下的最后一个点。采用递归函数或非递归函数都行*/
void pre(bintree t)
{ /*后序遍历二叉树的递归算法*/
	printf("\npre's last: %c", stack1[top - 1]->data);
}

/*我不再给出函数原型，自己在此处完成函数：求后序遍历下的第一个点。采用递归函数或非递归函数都行*/
void post(bintree t)
{ /*后序遍历二叉树的递归算法*/
	printf("\npost's front: %c", stack[0]->data);
}

void main()
{bintree root;
    
 /*建二叉树*/   
 printf("请输入二叉树的结点值：");  root=createbintree();
 printf("二叉树的前序遍历结果为：");  preorder(root);
 printf("\n二叉树的后序遍历结果为：");  postorder(root);
     
 /*在此处完成对两个函数的调用，并进行测试*/
  pre(root);
  post(root);

}
