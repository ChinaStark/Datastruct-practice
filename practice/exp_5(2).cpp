#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
/*���������Ӵ洢��ͷ�ļ�*/
typedef char datatype;         /*�������ֵ������*/
typedef struct node {           /*��������������*/
    datatype  data;
    struct node* lchild, * rchild;
}bintnode, * bintree;


bintree createbintree()
{/*����ǰ�������˳����һ�ø����Ķ�����*/
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
{ /*��������������ĵݹ��㷨*/
    if (t) {
        inorder(t->lchild);
        printf("%c", t->data);
        inorder(t->rchild);
    }
}


bintree firstofin(bintree t)   /*�˺�������������µĵ�һ���㣬������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
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


bintree lastofin(bintree t)   /*�˺�������������µ����һ���㣬������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
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

    /*��������*/
    printf("������������Ľ��ֵ��");  root = createbintree();
    printf("������������������Ϊ��");  inorder(root);

    /*�ڴ˴���ɶ�firstofin������lastofin�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
    printf("\nfirstofin��ֵΪ%c\n", firstofin(root)->data);
    printf("lastofin��ֵΪ%c", lastofin(root)->data);
}
        