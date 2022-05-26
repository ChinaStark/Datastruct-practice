//某组有五个学生，每个人有一条学生信息，学生信息包括学号、姓名、性别和入学分数。
//设计一个程序，输入学生信息，再通过指针方式输出这些信息。
//五、实验结果与分析
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
		printf("第%d个学生性别,姓名,学号和入学分数", i + 1);
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
		printf("\n学生%d的个人信息\n", i);
		printf("学号：%d\n", p->id);
		printf("姓名：%s\n", p->name);
		printf("分数：%0.2f\n", p->score);
		printf("性别：%s \n", p->sex);
		i++;
		p++;
	
	}
	
}
void main()
{
	ave(stu, 5);
	print(stu, 5);

}