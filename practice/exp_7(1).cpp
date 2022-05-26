#include <stdlib.h>
#include <stdio.h>
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node* next;
}linknode, * linklist;


/*尾插法建立带头结点单链表*/
linklist creat()
{
    linklist head, r, s;
    datatype x;
    head = r = (linklist)malloc(sizeof(linknode));
    head->next = NULL;
    printf("请输入一组整型数据，以空格分隔，以0结束输入:\n");  scanf("%d", &x);
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


/*输出带头结点单链表*/
void print(linklist head)
{
    linklist p;
    p = head->next;
    printf("带头结点单链表为：");
    while (p)
    {
        printf("%5d", p->data);
        p = p->next;
    }
}


linklist linkSearch1(linklist head, datatype key)  /*带头结点单链表的非递归检索，将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
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


linklist linkSearch2(linklist head, datatype key)  /*带头结点单链表的递归检索，将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    if (head->next->data == key || head->next == NULL)
        return head->next;
    return linkSearch2(head->next, key);


}


void main()
{
    linklist head, p;
    int key;

    head = creat();   /*尾插法建立带头结点单链表*/
    print(head);    /*输出带头结点单链表*/

    printf("\n请输入要查找的关键字：");  scanf("%d", &key);

    /*在此处完成对linkSearch1函数和linkSearch2函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
    p = linkSearch1(head, key);
    printf("\n非递归的结果为:");
    if (p) printf("找到了   %d",p->data);
    else printf("没找到");
    

    p = linkSearch1(head, key);
    printf("\n\n递归的结果为:");
    if (p) printf("找到了   %d", p->data);
    else printf("没找到");
    
}
