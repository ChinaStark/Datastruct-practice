#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#define M 20					/*Ԥ����ͼ����󶥵���*/
typedef char DataType;  /*������Ϣ��������*/
typedef struct node{    /*�߱���*/
   int adjvex,weight;                  /*�ڽӵ�*/
   struct node *next;
}EdgeNode;
typedef struct vnode{   /*ͷ�������*/
   DataType vertex;         /*������Ϣ*/
   EdgeNode *FirstEdge; /*�ڽ�����ͷָ��*/
}VertexNode;
typedef struct{           /*�ڽӱ�����*/
 VertexNode adjlist[M];  /*���ͷ����˳���*/
 int n,e;                 /*ͼ�Ķ����������*/
}LinkedGraph;


/*�������ܣ�����ͼ���ڽӱ�
�����������ڽӱ�ָ�����g�����ͼ��Ϣ���ļ���filename;ͼ�����Ͳ���c��c=0��ʾ��������ͼ�������ʾ��������ͼ 
��������ֵ����*/ 
void creat(LinkedGraph *g,char *filename,int c)
    { int i,j,k;
      EdgeNode *s;
      FILE *fp;
      fp=fopen(filename,"r");
      if (fp)
      {fscanf(fp,"%d%d",&g->n,&g->e);              /*���붥���������*/
       for(i=0;i<g->n;i++)
       {fscanf(fp,"%1s",&g->adjlist[i].vertex);    /*���붥����Ϣ*/
        g->adjlist[i].FirstEdge=NULL;         /*�߱���Ϊ�ձ�*/
       }
      for(k=0;k<g->e;k++)                     /*ѭ��e�ν����߱�*/
        {   fscanf(fp,"%d%d",&i,&j);                 /*��������ԣ�i,j��*/
            s=(EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex=j;                         /*�ڽӵ����Ϊj*/
            s->next=g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge=s;           /*���½��*s���붥��vi�ı߱�ͷ��*/
            if(c==0)                             /*����ͼ*/ 
            {s=(EdgeNode *)malloc(sizeof(EdgeNode));
             s->adjvex=i;                         /*�ڽӵ����Ϊi*/
             s->next=g->adjlist[j].FirstEdge;
             g->adjlist[j].FirstEdge=s;           /*���½��*s���붥��vj�ı߱�ͷ��*/
			}
        }
    fclose(fp);
    }
    else
    g->n=0;
   }


/*�������ܣ�����ڽӱ�洢�ṹ*/
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


int countdegree(LinkedGraph g,int i)   /*��������������������ͼ��ĳ������Ķȣ�������������������Ҳ���Բ����Ҹ��ĺ���ԭ�ͣ��Լ�дһ������*/
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
 
 /*��ͼ*/
 printf("������洢��ͼ����ͱߵ���Ϣ���ļ�����"); scanf("%s", filename);
 creat(&g,filename,0);
 printf("ͼ���ڽӱ�ṹΪ��\n");  print(g);

 /*�ڴ˴���ɶ�countdegree�����ĵ��ã������в��ԡ�������Լ�д�ĺ�����ͬ����ɺ����ĵ��úͲ���*/
 for (int i = 0; i < g.e; i++) {
     printf("��%d�����Ķ�Ϊ:%d\n",i, countdegree(g, i));
 }
 
}
