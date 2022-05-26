#include <stdlib.h>
#include <stdio.h>
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node* next;
}linknode, * linklist;


/*β�巨������ͷ��㵥����*/
linklist creat()
{
    linklist head, r, s;
    datatype x;
    head = r = (linklist)malloc(sizeof(linknode));
    head->next = NULL;
    printf("������һ���������ݣ��Կո�ָ�����0��������:\n");  scanf("%d", &x);
    while (x != 0)
    {
        s = (linklist)malloc(sizeof(linknode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return head;
}


/*�����ͷ��㵥����*/
void print(linklist head)
{
    linklist p;
    p = head->next;
    printf("��ͷ��㵥����Ϊ��");
    while (p)
    {
        printf("%5d", p->data);
        p = p->next;
    }
}


linklist linkSearch1(linklist head, datatype key)  /*��ͷ��㵥����ķǵݹ������������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
{
    linklist l = head->next;
    while (l)
    {
        if (l->data == key)
            return l;
        l = l->next;
    }
    return NULL;

}


linklist linkSearch2(linklist head, datatype key)  /*��ͷ��㵥����ĵݹ������������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
{
    if (head->next->data == key || head->next == NULL)
        return head->next;
    return linkSearch2(head->next, key);


}


void main()
{
    linklist head, p;
    int key;

    head = creat();   /*β�巨������ͷ��㵥����*/
    print(head);    /*�����ͷ��㵥����*/

    printf("\n������Ҫ���ҵĹؼ��֣�");  scanf("%d", &key);

    /*�ڴ˴���ɶ�linkSearch1������linkSearch2�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
    p = linkSearch1(head, key);
    printf("\n�ǵݹ�Ľ��Ϊ:");
    if (p) printf("�ҵ���   %d",p->data);
    else printf("û�ҵ�");
    

    p = linkSearch1(head, key);
    printf("\n\n�ݹ�Ľ��Ϊ:");
    if (p) printf("�ҵ���   %d", p->data);
    else printf("û�ҵ�");
    
}
