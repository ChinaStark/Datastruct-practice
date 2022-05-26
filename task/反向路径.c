/*设计一个算法，求二叉树中每片叶子到根的反向路径，
反向路径指的是从二叉树的根到某片叶子的路径的逆序。

要求：将以下程序文件补充完整并调试运行，以附件方式上传程序文件和运行结果图片。
文件名格式为：学号+姓名-文件名，例如：20200001张三-反向路径。*/
#include <stdio.h>
#include <stdlib.h>
/*二叉树链接存储的头文件*/
typedef char datatype;         /*结点属性值的类型*/
typedef struct node {           /*二叉树结点的类型*/
	datatype  data;
	struct node* lchild, * rchild;
}bintnode, * bintree;


bintree createbintree()
{/*按照前序遍历的顺序建立一棵给定的二叉树*/
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
{ /*前序遍历二叉树的递归算法*/
	if (t) {
		printf("%c", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
struct snode
{
	bintnode* node;//存放当前节点指针
	int parent;//存放双亲节点在队列中的位置
} Qu[100];//定义非循环队列]
/*我不再给出函数原型，自己在此处完成函数：求二叉树中每片叶子到根的反向路径。采用递归函数或非递归函数都行*/
void revese(bintnode* b)
{
	int front;
	int rear;
	int p;
	//定义队头和队尾指针
	front = rear = -1;//置队列为空队列
	rear++;
	Qu[rear].node = b;//根节点指针进队
	Qu[rear].parent = -1;//根节点没有双亲节点
	while (front < rear)//队列不为空
	{
		front++;//front为当前出队节点的下标
		b = Qu[front].node;//队头出队
		if (b->lchild == NULL && b->rchild == NULL)//*b为叶子节点
		{
			front = 0;
			while (front <= rear)
			{
				printf("\n%c到根节点逆路径：", Qu[front].node->data);
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
		if (b->lchild != NULL)//左孩子进队
		{
			rear++;
			Qu[rear].node = b->lchild;
			Qu[rear].parent = front;
		}
		if (b->rchild != NULL)//右孩子进队
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
	/*建二叉树*/
	printf("请输入二叉树的结点值：");
	root = createbintree();
	printf("二叉树的前序遍历结果为：");
	preorder(root);
	
	printf("二叉树的反向路径为：");revese(root);
	/*在此处完成对该函数的调用，并进行测试*/
}
