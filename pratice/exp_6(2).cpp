#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#define M 20					/*预定义图的最大顶点数*/
typedef char DataType;  /*顶点信息数据类型*/
typedef struct node {    /*边表结点*/
    int adjvex;                  /*邻接点*/
    struct node* next;
}EdgeNode;
typedef struct vnode {   /*头结点类型*/
    DataType vertex;         /*顶点信息*/
    EdgeNode* FirstEdge; /*邻接链表头指针*/
}VertexNode;
typedef struct {           /*邻接表类型*/
    VertexNode adjlist[M];  /*存放头结点的顺序表*/
    int n, e;                 /*图的顶点数与边数*/
}LinkedGraph;


/*函数功能：建立图的邻接表
函数参数：邻接表指针变量g；存放图信息的文件名filename;图的类型参数c，c=0表示建立无向图，否则表示建立有向图
函数返回值：无*/
void creat(LinkedGraph* g, char* filename, int c)
{
    int i, j, k;
    EdgeNode* s;
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp)
    {
        fscanf(fp, "%d%d", &g->n, &g->e);              /*读入顶点数与边数*/
        for (i = 0; i < g->n; i++)
        {
            fscanf(fp, "%1s", &g->adjlist[i].vertex);    /*读入顶点信息*/
            g->adjlist[i].FirstEdge = NULL;         /*边表置为空表*/
        }
        for (k = 0; k < g->e; k++)                     /*循环e次建立边表*/
        {
            fscanf(fp, "%d%d", &i, &j);                 /*输入无序对（i,j）*/
            s = (EdgeNode*)malloc(sizeof(EdgeNode));
            s->adjvex = j;                         /*邻接点序号为j*/
            s->next = g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge = s;           /*将新结点*s插入顶点vi的边表头部*/
            if (c == 0)                             /*无向图*/
            {
                s = (EdgeNode*)malloc(sizeof(EdgeNode));
                s->adjvex = i;                         /*邻接点序号为i*/
                s->next = g->adjlist[j].FirstEdge;
                g->adjlist[j].FirstEdge = s;           /*将新结点*s插入顶点vj的边表头部*/
            }
        }
        fclose(fp);
    }
    else
        g->n = 0;
}


/*函数功能：输出邻接表存储结构*/
void print(LinkedGraph  g)
{
    EdgeNode* p;
    int i;
    for (i = 0; i < g.n; i++)
    {
        printf("%c", g.adjlist[i].vertex);
        p = g.adjlist[i].FirstEdge;
        while (p)
        {
            printf("-->%d", p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
}


int visited[M];
/*函数功能：从顶点i开始深度优先遍历图的连通分量
函数参数：图的邻接表g，遍历起点i
函数返回值：无*/
void dfs(LinkedGraph g, int i)             /*将dfs函数补充完整*/
{
    EdgeNode* p;
    if (i == 0)
    {
        printf("%c", g.adjlist[i].vertex);
    }
    else
    {
        printf("-->%c", g.adjlist[i].vertex);
    }
    p = g.adjlist[i].FirstEdge;
    visited[i] = 1;
    while (p)
    {
        if (!visited[p->adjvex]) {
            dfs(g, p->adjvex);
        }
       p = p->next;
       
    }
}
/*函数功能：深度优先遍历图
函数参数：图的邻接表g
函数返回值：无*/
void DfsTraverse(LinkedGraph g)
{
    int i;
    for (i = 0; i < g.n; i++)
        visited[i] = 0;     /*初始化标志数组*/
    for (i = 0; i < g.n; i++)
        if (!visited[i])  /*vi未访问过*/
            dfs(g, i);
}


/*函数功能：从顶点i出发广度优先变量图g的连通分量
函数参数：图的邻接表g，遍历始点i
函数返回值：无*/
void bfs(LinkedGraph g, int i)              /*将bfs函数补充完整*/
{
    EdgeNode* p;
    int queue[M], front = 0, rear = 0;
    int j = 0;
    printf("BFS:%c", g.adjlist[i].vertex);
    visited[i] = 1;
    queue[rear++] = i;
    while (rear> front)
    {
        j = queue[front++];
        p = g.adjlist[j].FirstEdge;
        while (p)
        {
            if (!visited[p->adjvex]) {
                printf("-->%c", g.adjlist[p->adjvex].vertex);
                visited[p->adjvex] = 1;
                queue[rear++] = p->adjvex;
            }
            p = p->next;
        }
        
    }
}
/*函数功能：广度优先遍历图g
函数参数：邻接表g
函数返回值：返回连通分量的个数*/
int BfsTraverse(LinkedGraph g)
{
    int i, count = 0;
    for (i = 0; i < g.n; i++)
        visited[i] = 0;     /*初始化标志数组*/
    for (i = 0; i < g.n; i++)
        if (!visited[i])  /*vi未访问过*/
        {
            printf("\n");
            count++;            /*连通分量个数加1*/
            bfs(g, i);
        }
    return count;
}


void main()
{
    LinkedGraph g;
    char filename[20];

    /*建图*/
    printf("请输入存储了图顶点和边的信息的文件名：");  scanf("%s",filename);
    creat(&g, filename, 0);      /*此处根据自己的图是无向图还是有向图，修改第三个参数*/
    printf("图的邻接表结构为：\n");  print(g);

    /*在此处完成对DfsTraverse函数和BfsTraverse函数的调用，并进行测试*/
    printf("DFS:");
    DfsTraverse(g);
    BfsTraverse(g);
}
