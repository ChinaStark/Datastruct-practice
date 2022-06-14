#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#define M 20					/*预定义图的最大顶点数*/
typedef char DataType;  /*顶点信息数据类型*/
typedef struct node{    /*边表结点*/
   int adjvex,weight;                  /*邻接点*/
   struct node *next;
}EdgeNode;
typedef struct vnode{   /*头结点类型*/
   DataType vertex;         /*顶点信息*/
   EdgeNode *FirstEdge; /*邻接链表头指针*/
}VertexNode;
typedef struct{           /*邻接表类型*/
 VertexNode adjlist[M];  /*存放头结点的顺序表*/
 int n,e;                 /*图的顶点数与边数*/
}LinkedGraph;


/*函数功能：建立图的邻接表
函数参数：邻接表指针变量g；存放图信息的文件名filename;图的类型参数c，c=0表示建立无向图，否则表示建立有向图 
函数返回值：无*/ 
void creat(LinkedGraph *g,char *filename,int c)
    { int i,j,k;
      EdgeNode *s;
      FILE *fp;
      fp=fopen(filename,"r");
      if (fp)
      {fscanf(fp,"%d%d",&g->n,&g->e);              /*读入顶点数与边数*/
       for(i=0;i<g->n;i++)
       {fscanf(fp,"%1s",&g->adjlist[i].vertex);    /*读入顶点信息*/
        g->adjlist[i].FirstEdge=NULL;         /*边表置为空表*/
       }
      for(k=0;k<g->e;k++)                     /*循环e次建立边表*/
        {   fscanf(fp,"%d%d",&i,&j);                 /*输入无序对（i,j）*/
            s=(EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex=j;                         /*邻接点序号为j*/
            s->next=g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge=s;           /*将新结点*s插入顶点vi的边表头部*/
            if(c==0)                             /*无向图*/ 
            {s=(EdgeNode *)malloc(sizeof(EdgeNode));
             s->adjvex=i;                         /*邻接点序号为i*/
             s->next=g->adjlist[j].FirstEdge;
             g->adjlist[j].FirstEdge=s;           /*将新结点*s插入顶点vj的边表头部*/
			}
        }
    fclose(fp);
    }
    else
    g->n=0;
   }


/*函数功能：输出邻接表存储结构*/
void print(LinkedGraph  g)
{  EdgeNode *p;
   int i;
   for(i=0;i<g.n;i++)
    {   printf("%c",g.adjlist[i].vertex);
        p=g.adjlist[i].FirstEdge;
        while(p)
        {   printf("-->%d",p->adjvex);
            p=p->next;
        }
     printf("\n");
   }
}


int countdegree(LinkedGraph g,int i)   /*本函数的作用是求无向图的某个顶点的度，将本函数补充完整。也可以不用我给的函数原型，自己写一个函数*/
{
    int count = 0;
    
    EdgeNode* p;
    p = g.adjlist[i].FirstEdge;
    while (p)
    {
        count++;
        p = p->next;
    }

    return count;



}


void main()
{LinkedGraph g;
 char filename[20];
 
 /*建图*/
 printf("请输入存储了图顶点和边的信息的文件名："); scanf("%s", filename);
 creat(&g,filename,0);
 printf("图的邻接表结构为：\n");  print(g);

 /*在此处完成对countdegree函数的调用，并进行测试。如果是自己写的函数，同样完成函数的调用和测试*/
 for (int i = 0; i < g.e; i++) {
     printf("第%d个结点的度为:%d\n",i, countdegree(g, i));
 }
 
}
