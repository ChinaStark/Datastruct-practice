#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
/********************************/
/*顺序表的头文件，文件名sequlist.h*/
/********************************/
#define MAXSIZE 100
typedef int datatype;
typedef struct {
    datatype a[MAXSIZE];
    int size;
}sequence_list;


/**************************************************/
/*  函数功能：顺序表的初始化-置空表            */
/*  函数参数：指向sequence_list型变量的指针变量slt  */
/*  函数返回值：空                                */
/*  文件名：sequlist.c, 函数名：init()                  */
/***************************************************/
void init(sequence_list* slt)
{
    slt->size = 0;
}


/***************************************************/
/*  函数功能：在顺序表后部进行插入操作             */
/*  函数参数：指向sequence_list型变量的指针变量slt   */
/*            datatype类型的变量x                  */
/*  函数返回值：空                                 */
/*  文件名：seqlappe.c, 函数名：append()               */
/***************************************************/
void append(sequence_list* slt, datatype x)
{
    if (slt->size == MAXSIZE)
    {
        printf("NULL"); exit(1);
    }
    slt->a[slt->size] = x;
    slt->size = slt->size + 1;
}


/***************************************************/
/*  函数功能：打印顺序表的各结点值                 */
/*  函数参数：sequence_list型变量slt                 */
/*  函数返回值：空                                 */
/*  文件名：sequlist.c,  函数名：display()             */
/***************************************************/
void display(sequence_list slt)
{
    int i;
    if (!slt.size) printf("\n顺序表是空的!");
    else
        for (i = 0; i < slt.size; i++)  printf("%5d", slt.a[i]);
}
/*
 函数名：Has
 功能:判断p中有没有x这个值如果有的话就返回false否则返回true
 */
bool Has(sequence_list* p, int x) {
    int i = 0;
    while (p->size != i) {
        if (p->a[i] == x) {
            return true;
        }
        i++;
    }return false;
}
sequence_list intersection(sequence_list A, sequence_list B, sequence_list C)  /*将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    sequence_list h;
    if (A.size < B.size)//把长的放在A中
    {
        h = A;
        A = B;
        B = h;
    }
    for (int i = 0; i < B.size; i++) {
        if (Has(&A, B.a[i])) {//将B中的数据依次和A比较如果一样就加在A的尾部
            C.a[C.size++] = B.a[i];
        }
    }
    return C;


}


void main()
{
    sequence_list LA, LB, LC;
    datatype y;
    int j, n;

    init(&LA);  init(&LB);  init(&LC);

    /*建表*/
    printf("请输入顺序表A的结点个数：");  scanf("%d", &n);
    printf("请输入顺序表A的结点值：");
    for (j = 1; j <= n; j++)
    {
        scanf("%d", &y);  append(&LA, y);
    }
    display(LA);

    printf("\n请输入顺序表B的结点个数：");  scanf("%d", &n);
    printf("请输入顺序表B的结点值：");
    for (j = 1; j <= n; j++)
    {
        scanf("%d", &y);  append(&LB, y);
    }
    display(LB);

    /*在此处完成对unionset函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
    LC = intersection(LA, LB,LC);
    printf("\nA∩B = ");
    display(LC);
}
