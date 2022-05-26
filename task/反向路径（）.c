#include <stdio.h>
#include <stdlib.h>
/*二叉树链接存储的头文件*/
typedef char datatype;         /*结点属性值的类型*/
typedef struct node{           /*二叉树结点的类型*/
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
{/*按照前序遍历的顺序建立一棵给定的二叉树*/ 
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
    printf("\n节点%c的反向路径为：", data);
    while (p)//找到该节点
    {if (p->data == data)
        break;  
        p = p->next;
    }
    while (p)//对链表中该节点后的数据进行输出
    {
        printf("%c", p->data);
        p = p->next;
    }
}

void preorder(bintree t)
{ /*前序遍历二叉树的递归算法*/
    if (t) 
	{ 
        printf("%c",t->data);
        nodelink* p = (nodelink*)malloc(sizeof(nodelink));
        p->data = t->data;
        p->next = head->next;//头插法建立前序遍历的链表（逆序的）
        head->next = p;
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void fun(bintree t)
{ /*前序遍历二叉树的递归算法*/
    if (t)
    {
        reverse(head, t->data);
        fun(t->lchild);
        fun(t->rchild);
    }
}


/*我不再给出函数原型，自己在此处完成函数：求二叉树中每片叶子到根的反向路径。采用递归函数或非递归函数都行*/


void main()
{bintree root;
head = (nodelink*)malloc(sizeof(nodelink));
head->next = NULL;
 /*建二叉树*/   
 printf("请输入二叉树的结点值：");  root=createbintree();
 printf("二叉树的前序遍历结果为：");  preorder(root);

 /*在此处完成对该函数的调用，并进行测试*/
 fun(root);
}
