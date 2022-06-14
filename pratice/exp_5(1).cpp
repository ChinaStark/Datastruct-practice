#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
/*二叉树链式存储的头文件*/
typedef char datatype;         /*结点属性值的类型*/
typedef struct node {           /*二叉树结点的类型*/
    datatype  data;
    struct node* lchild, * rchild;
}bintnode, * bintree;

typedef struct stack         /*栈结构定义*/
{
    bintree data[100];
    int tag[100];          /*为栈中每个元素设置的标记，用于后序遍历*/
    int top;              /*栈顶指针*/
} seqstack;

void push(seqstack* s, bintree t)  /*进栈*/
{
    s->data[s->top] = t; s->top++;
}

bintree pop(seqstack* s)  /*出栈*/
{
    if (s->top != 0)
    {
        s->top--;  return(s->data[s->top]);
    }
    else
        return NULL;
}


bintree createbintree()
{/*按照前序遍历的顺序建立一棵给定的二叉树*/
    char ch;
    bintree t;
    if ((ch = getchar()) == '#')
        t = NULL;
    else {
        t = (bintnode*)malloc(sizeof(bintnode));
        t->data = ch;
        t->lchild = createbintree();
        t->rchild = createbintree();
    }
    
    return t;
}


void preorder(bintree t)
{ /*前序遍历二叉树的递归算法*/
    if (t) {
        printf("%c", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}


int countleaf(bintree t)
{
    if (t == NULL)
        return 0;
    if (t->lchild == NULL && t->rchild == NULL)
        return 1;
    else
        return countleaf(t->lchild) + countleaf(t->rchild);
}


int countleaf2(bintree t)   /*此函数为非递归函数，将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    int count = 0;
    if (t == NULL) {
        return 0;
    }
    seqstack s1;
    s1.top = 0;
    while ((s1.top!= 0) || (t))
    {
        if (t) {
            if ((t->lchild == NULL) && (t->rchild == NULL)) {
                count++;
            }
            push(&s1, t);
            t = t->lchild;
        }
        else
        {
            
            t = pop(&s1);
            t = t->rchild;
        }
    }
    return count;

}


void main()
{
    bintree root;

    /*建二叉树*/
    printf("请输入二叉树的结点值：");  root = createbintree();
    printf("二叉树的前序遍历结果为：");  preorder(root);

    /*在此处完成对numofleaf1函数和numofleaf2函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
    printf("\n递归调用：%d\n",countleaf(root));
    printf("非递归调用：%d\n", countleaf2(root));
}