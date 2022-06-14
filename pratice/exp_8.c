#pragma warning(disable : 4996)
#include<stdio.h>
#include<Windows.h>
typedef int keytype;
#define MAXSIZE 100
typedef struct {
	keytype list[MAXSIZE+1];
	int len;
}table;

int w;//meau's control


void input(table* t) {
	printf("�������Ĵ�С(MAX is 100):");
	scanf("%d", &t->len);
	printf("����������ÿһ��ֵ:");
	for (int i = 0; i < t->len; i++) {
		scanf("%d", &t->list[i]);
	}
}
void print(table* t) {
	printf("���ֵΪ:");
	for (int i = 0; i < t->len; i++) {
		printf("%d   ", t->list[i]);
	}
}
void simple_select_sort(table* t) {
	for (int i = 0; i < t->len; i++) {
		int min = i;
		for (int j = i + 1; j < t->len; j++) {
			if (t->list[j] < t->list[min]) min = j;
		}
		if (i != min) {
			t->list[t->len] = t->list[min];
			t->list[min] = t->list[i];
			t->list[i] = t->list[t->len];
		}
	}
}
void insert_sort(table* t) {
	for (int i = 0; i < t->len; i++) {
		t->list[t->len] = t->list[i];
		int j = i - 1;
		while (t->list[t->len]<t->list[j] &&j>=0)
		{
			t->list[j+1] = t->list[j];
			j--;
		}
		t->list[j+1] = t->list[t->len];
	}
}
void quikly_sort(table* t, int left, int right) {
	if(left < right)
	{
		int i = left, j = right;
		t->list[t->len] = t->list[i];
		while (i!=j)
		{
			while (i < j && t->list[t->len]<t->list[j])j--;
			if (i < j) {
				t->list[i] = t->list[j];
				i++;
			}
			while (i < j && t->list[t->len] > t->list[i])i++;
			if (i < j) {
				t->list[j] = t->list[i];
			}
		}
		t->list[j] = t->list[t->len];
		quikly_sort(t, left, i - 1);
		quikly_sort(t, i + 1, right);
		
	}
}
void insert(table* t) {
	int n;
	
	printf("�������ʲô����:");
	scanf("%d", &n);
	
	t->len++;
	int i;
	for (i = t->len-1; i > 0; i--) {
		if (t->list[i-1] < n) {
			t->list[i] = n;
			break;
		}
		t->list[i] = t->list[i - 1];

	}
	if (i == 0) {
		t->list[0] = n;
	}

}
void del(table* t) {
	
	int n;
	printf("����ɾ���ڼ���?");
	scanf("%d", &n);
	for (int i = n - 1; i < t->len; i++) {
		t->list[i] = t->list[i + 1];
	}
	t->len -= 1;

}
void meau(table* t)
{
	int n = 10;
	
	while (n != 0)
	{
		int p = 1; 
		system("pause");
		system("cls");
		printf("1������(MAXSIZE is 100)\n");
		printf("2����ӡ\n");
		printf("3��insert �����룩\n");
		printf("4��ɾ��\n");
		printf("5��ֱ��ѡ������\n");
		printf("6��ֱ�Ӳ�������\n");
		printf("7����������\n");
		printf("��ǰ��"); print(t);
		printf("\n���������ѡ��( '0' �˳�)");
		scanf("%d", &n);
		switch (n)
		{
		case 0:p = 0; break;
		case 1: input(t); 
			break;
		case 2:print(t);p = 0;
			break;
		case 3:insert(t);
			break;
		case 4:del(t);
			break;
		case 5:simple_select_sort(t);
			break;
		case 6:insert_sort(t);
			break;
		case 7:printf("����ǰ:"); print(t); quikly_sort(t, 0, t->len - 1);
			break;
		}
		if (p == 1) {
			printf("������"); print(t);
		}
		
	}


}
void main() {
	table *t =  malloc(sizeof(table));
	t->len = 0;
	input(t);
	//printf("��������˵�");
	meau(t);
}
