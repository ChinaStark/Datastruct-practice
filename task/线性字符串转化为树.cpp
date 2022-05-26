#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
typedef struct node {
	char data;
	int child[3];
}treenode;
treenode tree[20];
int root;
int length = 0;
char p[50];
void backtotree(char p[],treenode tree[])
{
	int stack[50];
	int top = 0;
	int i = 0;
	tree[length].data = p[i++];
	for (int i = 0; i < 3; i++) {
		tree[length].child[i] = -1;
	}
	length++;
	while (p[i] != '#') {
		if (p[i] == '(') {
			stack[top++] = length-1;
			i++;
		}
		else if(p[i] == ')') {
			top--;
			i++;
			if (stack[top] == NULL) {
				break;
			}
		}
		else {
			tree[length].data = p[i++];
			for (int h = 0; h < 3; h++) {
				tree[length].child[h] = -1;
			}
			for (int k = 0; k < 3; k++) {
				if (tree[stack[top - 1]].child[k] == -1) {
					tree[stack[top - 1]].child[k] = length;
					break;
				}
			}
			
			length++;
		}
	}
}
int numleaf(treenode tree[],int p)//复杂方法
{
	int x, y, z;
	if (tree[p].child[0] == -1)
		return 1;
	else
	{
		x = numleaf(tree, tree[p].child[0]);
	} 
	if (tree[p].child[1] == -1)
		return x;
	else
	{
		y = numleaf(tree, tree[p].child[1]);
	}
	if (tree[p].child[2] == -1)
		return x+y;
	else
	{
		z = numleaf(tree, tree[p].child[2]);
	}
}
void print(treenode tree[],int i )
{
	int y = 0;
	int k = 0;
	printf("%c", tree[i].data);
	for(int j = 0; j < 3; j++){ if (tree[i].child[j] != -1)k = 1;}
	if (k == 1) {
		printf("(");
	}
	for (int j = 0; j < 3; j++) {
		if (tree[i].child[j] != -1) {
			
			print(tree, tree[i].child[j]);
			y = 1;
		}
	}
	if (y == 1) {
		printf(")");
	}
	
}
void input(char p[]) {
	printf("请输入(并且以‘#’结束)：");
	
	scanf("%s", p);
	
	/*int i = 0;
	char s;
	while ((s = getchar())!= '#')
	{
		strcpy(p[i++], s);
	}*/
}
void main()
{
	char p[20];
	treenode tree[20];
	p[0] = '0';
	input(p);
	if (p[0] == 0) {
		printf("NULL");
		exit(0);
	}
	else {
		backtotree(p, tree);
	}
	print(tree, 0);
	int t = (int)numleaf(tree, 0);
	printf("%d",t);
}