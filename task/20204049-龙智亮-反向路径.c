/*���һ���㷨�����������ÿƬҶ�ӵ����ķ���·����
����·��ָ���ǴӶ������ĸ���ĳƬҶ�ӵ�·��������

Ҫ�󣺽����³����ļ������������������У��Ը�����ʽ�ϴ������ļ������н��ͼƬ��
�ļ�����ʽΪ��ѧ��+����-�ļ��������磺20200001����-����·����*/
#include <stdio.h>
#include <stdlib.h>
/*���������Ӵ洢��ͷ�ļ�*/
typedef char datatype;         /*�������ֵ������*/
typedef struct node {           /*��������������*/
	datatype  data;
	struct node* lchild, * rchild;
}bintnode, * bintree;


bintree createbintree()
{/*����ǰ�������˳����һ�ø����Ķ�����*/
	char ch;  bintree t;
	if ((ch = getchar()) == '#')
		t = NULL;
	else {
		t = (bintnode*)malloc(sizeof(bintnode));
		t->data = ch;
		t->lchild = createbintree();
		t->rchild = createbintree();
	}
	return t;
}


void preorder(bintree t)
{ /*ǰ������������ĵݹ��㷨*/
	if (t) {
		printf("%c", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
struct snode
{
	bintnode* node;//��ŵ�ǰ�ڵ�ָ��
	int parent;//���˫�׽ڵ��ڶ����е�λ��
} Qu[100];//�����ѭ������]
/*�Ҳ��ٸ�������ԭ�ͣ��Լ��ڴ˴���ɺ��������������ÿƬҶ�ӵ����ķ���·�������õݹ麯����ǵݹ麯������*/
void revese(bintnode* b)
{
	int front;
	int rear;
	int p;
	//�����ͷ�Ͷ�βָ��
	front = rear = -1;//�ö���Ϊ�ն���
	rear++;
	Qu[rear].node = b;//���ڵ�ָ�����
	Qu[rear].parent = -1;//���ڵ�û��˫�׽ڵ�
	while (front < rear)//���в�Ϊ��
	{
		front++;//frontΪ��ǰ���ӽڵ���±�
		b = Qu[front].node;//��ͷ����
		if (b->lchild == NULL && b->rchild == NULL)//*bΪҶ�ӽڵ�
		{
			front = 0;
			while (front <= rear)
			{
				printf("\n%c�����ڵ���·����", Qu[front].node->data);
				p = front;
				while (Qu[p].parent != -1)
				{
					printf("%c", Qu[p].node->data);
					p = Qu[p].parent;
				}
				printf("%c", Qu[p].node->data);
				front++;
			}
			
		}
		if (b->lchild != NULL)//���ӽ���
		{
			rear++;
			Qu[rear].node = b->lchild;
			Qu[rear].parent = front;
		}
		if (b->rchild != NULL)//�Һ��ӽ���
		{
			rear++;
			Qu[rear].node = b->rchild;
			Qu[rear].parent = front;
		}
	}
}

void main()
{
	bintree root;
	int n;
	/*��������*/
	printf("������������Ľ��ֵ��");
	root = createbintree();
	printf("��������ǰ��������Ϊ��");
	preorder(root);
	
	printf("�������ķ���·��Ϊ��");revese(root);
	/*�ڴ˴���ɶԸú����ĵ��ã������в���*/
}