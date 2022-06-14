#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
/********************************/
/*˳����ͷ�ļ����ļ���sequlist.h*/
/********************************/
#define MAXSIZE 100
typedef int datatype;
typedef struct {
    datatype a[MAXSIZE];
    int size;
}sequence_list;


/**************************************************/
/*  �������ܣ�˳���ĳ�ʼ��-�ÿձ�            */
/*  ����������ָ��sequence_list�ͱ�����ָ�����slt  */
/*  ��������ֵ����                                */
/*  �ļ�����sequlist.c, ��������init()                  */
/***************************************************/
void init(sequence_list* slt)
{
    slt->size = 0;
}


/***************************************************/
/*  �������ܣ���˳���󲿽��в������             */
/*  ����������ָ��sequence_list�ͱ�����ָ�����slt   */
/*            datatype���͵ı���x                  */
/*  ��������ֵ����                                 */
/*  �ļ�����seqlappe.c, ��������append()               */
/***************************************************/
void append(sequence_list* slt, datatype x)
{
    if (slt->size == MAXSIZE)
    {
        printf("˳���������!"); exit(1);
    }
    slt->a[slt->size] = x;
    slt->size = slt->size + 1;
}


/***************************************************/
/*  �������ܣ���ӡ˳���ĸ����ֵ                 */
/*  ����������sequence_list�ͱ���slt                 */
/*  ��������ֵ����                                 */
/*  �ļ�����sequlist.c,  ��������display()             */
/***************************************************/
void display(sequence_list slt)
{
    int i;
    if (!slt.size) printf("\n˳����ǿյ�!");
    else
        for (i = 0; i < slt.size; i++)  printf("%5d", slt.a[i]);
}


void ordermerge(sequence_list A, sequence_list B, sequence_list* C)  /*������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
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

    /*����*/
    printf("������˳���A�Ľ�������");  scanf("%d", &n);
    printf("������˳���A�Ľ��ֵ��");
    for (j = 1; j <= n; j++)
    {
        scanf("%d", &y);  append(&LA, y);
    }
    display(LA);

    printf("\n������˳���B�Ľ�������");  scanf("%d", &n);
    printf("������˳���B�Ľ��ֵ��");
    for (j = 1; j <= n; j++)
    {
        scanf("%d", &y);  append(&LB, y);
    }

    /*�ڴ˴���ɶ�ordermerge�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
    ordermerge(LA, LB, &LC);
    display(LC);
}