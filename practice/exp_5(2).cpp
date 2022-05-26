#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
/*二叉树链接存储的头文件*/
typedef char datatype;         /*结点属性值的类型*/
typedef struct node {           /*二叉树结点的类型*/
    datatype  data;
    struct node* lchild, * rchild;
}bintnode, * bintree;


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


void inorder(bintree t)
{ /*中序遍历二叉树的递归算法*/
    if (t) {
        inorder(t->lchild);
        printf("%c", t->data);
        inorder(t->rchild);
    }
}


bintree firstofin(bintree t)   /*此函数求中序遍历下的第一个点，将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    if (t == NULL) {
        return NULL;
    }
    while (t->lchild != NULL)
    {
        t = t->lchild;
    }
    return t;


}


bintree lastofin(bintree t)   /*此函数求中序遍历下的最后一个点，将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    if (t == NULL) {
        return NULL;
    }
    while (t->rchild != NULL)
    {
        t = t->rchild;
    }
    return t;

}


void main()
{
    bintree root;

    /*建二叉树*/
    printf("请输入二叉树的结点值：");  root = createbintree();
    printf("二叉树的中序遍历结果为：");  inorder(root);

    /*在此处完成对firstofin函数和lastofin函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
    printf("\nfirstofin的值为%c\n", firstofin(root)->data);
    printf("lastofin的值为%c", lastofin(root)->data);
}
        