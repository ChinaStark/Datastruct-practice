#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#define maxsize 100
typedef struct {
    char str[maxsize];
    int length;
}seqstring;
int normal(seqstring t, seqstring p)
{
    int i, j;
    i = 0; j = 0;
    for (i; i < t.length; i++) {
        if (p.str[0] == t.str[i]) {
            int y = i, x = 0;
            while (y < t.length && x < p.length)
            {
                if (p.str[x] != t.str[y])
                    break;
                x++; y++;
            }
            if (x == p.length)
                return i - j + 1;
        }  
    }
    return 0;
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
    /*�ڴ˴���ɶ�kmp�����ĵ��ã������в���*/
    int j = normal(t, p);
    if (j) {
        printf("�ҵ����ڵ� %d ��λ��", j);
    }
    else {
        printf("û�ҵ�");
    }
}