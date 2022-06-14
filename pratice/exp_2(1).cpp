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
        printf("˳���������!"); exit(1);
    }
    slt->a[slt->size] = x;
    slt->size = slt->size + 1;
}

void display(sequence_list slt)
{
    int i;
    if (!slt.size) printf("\n˳����ǿյ�!");
    else
        for (i = 0; i < slt.size; i++)  printf("%5d", slt.a[i]);
}

void orderinsert(sequence_list* slt, datatype x)  /*������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
{
    if (slt->size == MAXSIZE)
    {
        printf("˳���������!"); exit(1);
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

    /*����*/
    printf("������˳���Ľ�������");
    scanf_s("%d", &n);
    printf("������˳���Ľ��ֵ��");
    for (j = 1; j <= n; j++)
    {
        scanf_s("%d", &y);  append(&L, y);
    }/*�ڴ˴���ɶ�orderinsert�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
    //display(L);
    printf("��������Ҫ�����ֵ��");
    scanf("%d", &k);
    orderinsert(&L, k);
    display(L);
    

}