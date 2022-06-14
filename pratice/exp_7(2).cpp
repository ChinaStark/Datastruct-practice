#pragma warning(disable : 4996)
#include <stdio.h>
#define maxsize 100     /*预定义最大的数据域空间*/
typedef  int datatype;  /*假设数据类型为整型*/
typedef struct {
    datatype data[maxsize];   /*此处假设数据元素只包含一个整型的关键字域*/
    int len;   /*线性表长度*/
}seqlist;    /*预定义的顺序表类型*/


/*函数功能：二分查找的非递归实现算法
函数参数：顺序表l；待查找关键字key
函数返回值：查找成功则返回所在位置，否则返回-1*/
int binsearch1(seqlist l, datatype key)            /*将本函数补充完整*/
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


/*函数功能：二分查找的递归实现算法
函数参数：顺序表l；待查找关键字key；顺序表起点low；顺序表终点high
函数返回值：查找成功则返回所在位置，否则返回-1*/
int binsearch2(seqlist l, datatype key, int low, int high)            /*将本函数补充完整*/
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

    /*建顺序表*/
    printf("请输入线性表的长度：");  scanf("%d", &l.len);
    printf("在输入节点值:");
    for (i = 0; i < l.len; i++)
        scanf("%d", &l.data[i]);

    printf("\n请输入要查找的关键字:");  scanf("%d", &key);

    /*在此处完成对binsearch1函数和binsearch2函数的调用，并进行测试*/

    k = binsearch1(l, key);
    printf("\n非递归的结果为:");
    if (k != -1) printf("找到了 在第%d个\n",k);
    else printf("没找到\n");
    

    k = binsearch2(l, key,0,l.len - 1);
    printf("\n递归的结果为:");
    if (k != -1) printf("找到了 在第%d个\n", k);
    else printf("没找到\n");
}
