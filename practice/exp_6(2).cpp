#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#define M 20					/*Ԥ����ͼ����󶥵���*/
typedef char DataType;  /*������Ϣ��������*/
typedef struct node {    /*�߱���*/
    int adjvex;                  /*�ڽӵ�*/
    struct node* next;
}EdgeNode;
typedef struct vnode {   /*ͷ�������*/
    DataType vertex;         /*������Ϣ*/
    EdgeNode* FirstEdge; /*�ڽ�����ͷָ��*/
}VertexNode;
typedef struct {           /*�ڽӱ�����*/
    VertexNode adjlist[M];  /*���ͷ����˳���*/
    int n, e;                 /*ͼ�Ķ����������*/
}LinkedGraph;


/*�������ܣ�����ͼ���ڽӱ�
�����������ڽӱ�ָ�����g�����ͼ��Ϣ���ļ���filename;ͼ�����Ͳ���c��c=0��ʾ��������ͼ�������ʾ��������ͼ
��������ֵ����*/
void creat(LinkedGraph* g, char* filename, int c)
{
    int i, j, k;
    EdgeNode* s;
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp)
    {
        fscanf(fp, "%d%d", &g->n, &g->e);              /*���붥���������*/
        for (i = 0; i < g->n; i++)
        {
            fscanf(fp, "%1s", &g->adjlist[i].vertex);    /*���붥����Ϣ*/
            g->adjlist[i].FirstEdge = NULL;         /*�߱���Ϊ�ձ�*/
        }
        for (k = 0; k < g->e; k++)                     /*ѭ��e�ν����߱�*/
        {
            fscanf(fp, "%d%d", &i, &j);                 /*��������ԣ�i,j��*/
            s = (EdgeNode*)malloc(sizeof(EdgeNode));
            s->adjvex = j;                         /*�ڽӵ����Ϊj*/
            s->next = g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge = s;           /*���½��*s���붥��vi�ı߱�ͷ��*/
            if (c == 0)                             /*����ͼ*/
            {
                s = (EdgeNode*)malloc(sizeof(EdgeNode));
                s->adjvex = i;                         /*�ڽӵ����Ϊi*/
                s->next = g->adjlist[j].FirstEdge;
                g->adjlist[j].FirstEdge = s;           /*���½��*s���붥��vj�ı߱�ͷ��*/
            }
        }
        fclose(fp);
    }
    else
        g->n = 0;
}


/*�������ܣ�����ڽӱ�洢�ṹ*/
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
/*�������ܣ��Ӷ���i��ʼ������ȱ���ͼ����ͨ����
����������ͼ���ڽӱ�g���������i
��������ֵ����*/
void dfs(LinkedGraph g, int i)             /*��dfs������������*/
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
/*�������ܣ�������ȱ���ͼ
����������ͼ���ڽӱ�g
��������ֵ����*/
void DfsTraverse(LinkedGraph g)
{
    int i;
    for (i = 0; i < g.n; i++)
        visited[i] = 0;     /*��ʼ����־����*/
    for (i = 0; i < g.n; i++)
        if (!visited[i])  /*viδ���ʹ�*/
            dfs(g, i);
}


/*�������ܣ��Ӷ���i����������ȱ���ͼg����ͨ����
����������ͼ���ڽӱ�g������ʼ��i
��������ֵ����*/
void bfs(LinkedGraph g, int i)              /*��bfs������������*/
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
/*�������ܣ�������ȱ���ͼg
�����������ڽӱ�g
��������ֵ��������ͨ�����ĸ���*/
int BfsTraverse(LinkedGraph g)
{
    int i, count = 0;
    for (i = 0; i < g.n; i++)
        visited[i] = 0;     /*��ʼ����־����*/
    for (i = 0; i < g.n; i++)
        if (!visited[i])  /*viδ���ʹ�*/
        {
            printf("\n");
            count++;            /*��ͨ����������1*/
            bfs(g, i);
        }
    return count;
}


void main()
{
    LinkedGraph g;
    char filename[20];

    /*��ͼ*/
    printf("������洢��ͼ����ͱߵ���Ϣ���ļ�����");  scanf("%s",filename);
    creat(&g, filename, 0);      /*�˴������Լ���ͼ������ͼ��������ͼ���޸ĵ���������*/
    printf("ͼ���ڽӱ�ṹΪ��\n");  print(g);

    /*�ڴ˴���ɶ�DfsTraverse������BfsTraverse�����ĵ��ã������в���*/
    printf("DFS:");
    DfsTraverse(g);
    BfsTraverse(g);
}
