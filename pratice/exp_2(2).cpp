#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
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
        printf("顺序表是满的!"); exit(1);
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


void ordermerge(sequence_list A, sequence_list B, sequence_list* C)  /*将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    int max, p, k = 1;
    p = max = C->size = (A.size--) + (B.size--); C->size--;
    while (p--) {
        if (A.a[A.size] > B.a[B.size]) {
            C->a[C->size--] = A.a[A.size--];
            if (A.size < 0)
            {
                A.a[0] = B.a[0];
                A.size = 0;
                if (k) {
                    k--;
                    B.size++;
                }
                B.size--;
            }
        }
        else {
            C->a[C->size--] = B.a[B.size--];
            if (B.size < 0)
            {
                B.size = 0;
                B.a[0] = A.a[0];
                if (k) {
                    k--;
                    A.size++;
                }
                A.size--;
            }
        }
    }
    C->size = max;
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

    /*在此处完成对ordermerge函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
    ordermerge(LA, LB, &LC);
    display(LC);
}