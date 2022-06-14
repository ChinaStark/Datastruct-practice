#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#pragma warning(disable : 4996)
typedef int datatype;
typedef struct {
    datatype a[MAXSIZE];
    int size;
}sequence_list;

void init(sequence_list* slt)
{
    slt->size = 0;
}

void append(sequence_list* slt, datatype x)
{
    if (slt->size == MAXSIZE)
    {
        printf("顺序表是满的!"); exit(1);
    }
    slt->a[slt->size] = x;
    slt->size = slt->size + 1;
}

void display(sequence_list slt)
{
    int i;
    if (!slt.size) printf("\n顺序表是空的!");
    else
        for (i = 0; i < slt.size; i++)  printf("%5d", slt.a[i]);
}

void orderinsert(sequence_list* slt, datatype x)  /*将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    if (slt->size == MAXSIZE)
    {
        printf("顺序表是满的!"); exit(1);
    }

    else
    {

        for (int i = 0; i < slt->size; i++)
        {
            if (x >= slt->a[slt->size - 1]) {
                slt->a[slt->size] = x;
                break;
            }
            if (slt->a[i] >= x)
            {
                for (int y = slt->size; y > i; y--)
                {
                    slt->a[y] = slt->a[y - 1];
                }
                slt->a[i] = x;
                break;
            }
            if (slt->size == i)
            {
                slt->a[slt->size] = x;
            }
        }
        slt->size++;
    }

}

void main()
{
    sequence_list L;
    datatype y;
    int j, n, k;

    init(&L);

    /*建表*/
    printf("请输入顺序表的结点个数：");
    scanf_s("%d", &n);
    printf("请输入顺序表的结点值：");
    for (j = 1; j <= n; j++)
    {
        scanf_s("%d", &y);  append(&L, y);
    }/*在此处完成对orderinsert函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
    //display(L);
    printf("请输入你要插入的值：");
    scanf("%d", &k);
    orderinsert(&L, k);
    display(L);
    

}