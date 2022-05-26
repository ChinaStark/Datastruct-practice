#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#define maxsize 100
typedef struct {
    char str[maxsize];
    int length;
}seqstring;


void getnext(seqstring p, int next[])
{
    int i, j;
    next[0] = -1;
    i = 0; j = -1;
    while (i < p.length)
    {
        if (j == -1 || p.str[i] == p.str[j])
        {
            ++i; ++j; next[i] = j;
        }
        else
            j = next[j];
    }
    printf("next����ֵΪ��");
    for (i = 0; i < p.length; i++)
        printf("%d  ", next[i]);
}


int kmp(seqstring t, seqstring p, int next[])
{
    int i, j;
    i = 0; j = 0;
    while (i < t.length && j < p.length)
    {
        if (j == -1 || t.str[i] == p.str[j])
        {
            i++; j++;
        }
        else  j = next[j];
    }
    if (j == p.length) return(i - p.length);
    else return(-1);
}


void main()
{
    seqstring t, p;
    int next[50];
    int pos;

    printf("�����������ַ�����");  scanf("%s", t.str);
    t.length = strlen(t.str);
    printf("������ģʽ�ַ�����");  scanf("%s", p.str);
    p.length = strlen(p.str);

    getnext(p, next);
    /*�ڴ˴���ɶ�kmp�����ĵ��ã������в���*/
    int j = kmp(t, p,next);
    if (j) {
        printf("�ҵ����ڵ� %d ��λ��",j);
    }
    else {
        printf("û�ҵ�");
    }
}