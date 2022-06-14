#pragma warning(disable : 4996)
#include <stdio.h>
#define maxsize 100     /*Ԥ��������������ռ�*/
typedef  int datatype;  /*������������Ϊ����*/
typedef struct {
    datatype data[maxsize];   /*�˴���������Ԫ��ֻ����һ�����͵Ĺؼ�����*/
    int len;   /*���Ա���*/
}seqlist;    /*Ԥ�����˳�������*/


/*�������ܣ����ֲ��ҵķǵݹ�ʵ���㷨
����������˳���l�������ҹؼ���key
��������ֵ�����ҳɹ��򷵻�����λ�ã����򷵻�-1*/
int binsearch1(seqlist l, datatype key)            /*����������������*/
{
    int low = 0, high = l.len - 1,mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (l.data[mid] == key) return mid;
        if (l.data[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}


/*�������ܣ����ֲ��ҵĵݹ�ʵ���㷨
����������˳���l�������ҹؼ���key��˳������low��˳����յ�high
��������ֵ�����ҳɹ��򷵻�����λ�ã����򷵻�-1*/
int binsearch2(seqlist l, datatype key, int low, int high)            /*����������������*/
{
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (l.data[mid] == key) return mid;
    if (l.data[mid] > key) return binsearch2(l, key, low, mid - 1);
    else return binsearch2(l, key,mid + 1,high);
}


void main()
{
    int i, k;
    datatype key;
    seqlist l;

    /*��˳���*/
    printf("���������Ա�ĳ��ȣ�");  scanf("%d", &l.len);
    printf("������ڵ�ֵ:");
    for (i = 0; i < l.len; i++)
        scanf("%d", &l.data[i]);

    printf("\n������Ҫ���ҵĹؼ���:");  scanf("%d", &key);

    /*�ڴ˴���ɶ�binsearch1������binsearch2�����ĵ��ã������в���*/

    k = binsearch1(l, key);
    printf("\n�ǵݹ�Ľ��Ϊ:");
    if (k != -1) printf("�ҵ��� �ڵ�%d��\n",k);
    else printf("û�ҵ�\n");
    

    k = binsearch2(l, key,0,l.len - 1);
    printf("\n�ݹ�Ľ��Ϊ:");
    if (k != -1) printf("�ҵ��� �ڵ�%d��\n", k);
    else printf("û�ҵ�\n");
}
