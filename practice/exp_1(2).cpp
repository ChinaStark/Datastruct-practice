//ĳ�������ѧ����ÿ������һ��ѧ����Ϣ��ѧ����Ϣ����ѧ�š��������Ա����ѧ������
//���һ����������ѧ����Ϣ����ͨ��ָ�뷽ʽ�����Щ��Ϣ��
//�塢ʵ���������
#pragma warning(disable : 4996)
#include <stdio.h>
struct Student
{
	int  id;
	char name[90] ;
	char sex[90] ;
	float score;
}stu[5];
void ave(Student ty[], int len)
{
	float score = 0;
	int b;
	char* p ,*a;
	for (int i = 0; i < len; i++)
	{
		printf("��%d��ѧ���Ա�,����,ѧ�ź���ѧ����", i + 1);
		scanf("%s%s%d%f", stu[i].sex, stu[i].name,&stu[i].id,&stu[i].score);
		 
		
	}
}
void print(Student ty[], int len)
{
	int i = 1;
	Student* p;
	p = ty;
	while (i<6)
	{
		printf("\nѧ��%d�ĸ�����Ϣ\n", i);
		printf("ѧ�ţ�%d\n", p->id);
		printf("������%s\n", p->name);
		printf("������%0.2f\n", p->score);
		printf("�Ա�%s \n", p->sex);
		i++;
		p++;
	
	}
	
}
void main()
{
	ave(stu, 5);
	print(stu, 5);

}