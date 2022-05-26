#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
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
        printf("NULL"); exit(1);
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
/*
 ��������Has
 ����:�ж�p����û��x���ֵ����еĻ��ͷ���false���򷵻�true
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
sequence_list intersection(sequence_list A, sequence_list B, sequence_list C)  /*������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
{
    sequence_list h;
    if (A.size < B.size)//�ѳ��ķ���A��
    {
        h = A;
        A = B;
        B = h;
    }
    for (int i = 0; i < B.size; i++) {
        if (Has(&A, B.a[i])) {//��B�е��������κ�A�Ƚ����һ���ͼ���A��β��
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
    display(LB);

    /*�ڴ˴���ɶ�unionset�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
    LC = intersection(LA, LB,LC);
    printf("\nA��B = ");
    display(LC);
}
