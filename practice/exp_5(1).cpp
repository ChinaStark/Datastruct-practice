#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
/*��������ʽ�洢��ͷ�ļ�*/
typedef char datatype;         /*�������ֵ������*/
typedef struct node {           /*��������������*/
    datatype  data;
    struct node* lchild, * rchild;
}bintnode, * bintree;

typedef struct stack         /*ջ�ṹ����*/
{
    bintree data[100];
    int tag[100];          /*Ϊջ��ÿ��Ԫ�����õı�ǣ����ں������*/
    int top;              /*ջ��ָ��*/
} seqstack;

void push(seqstack* s, bintree t)  /*��ջ*/
{
    s->data[s->top] = t; s->top++;
}

bintree pop(seqstack* s)  /*��ջ*/
{
    if (s->top != 0)
    {
        s->top--;  return(s->data[s->top]);
    }
    else
        return NULL;
}


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


void preorder(bintree t)
{ /*ǰ������������ĵݹ��㷨*/
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


int countleaf2(bintree t)   /*�˺���Ϊ�ǵݹ麯����������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
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

    /*��������*/
    printf("������������Ľ��ֵ��");  root = createbintree();
    printf("��������ǰ��������Ϊ��");  preorder(root);

    /*�ڴ˴���ɶ�numofleaf1������numofleaf2�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
    printf("\n�ݹ���ã�%d\n",countleaf(root));
    printf("�ǵݹ���ã�%d\n", countleaf2(root));
}