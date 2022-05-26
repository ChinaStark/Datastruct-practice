#pragma warning(disable : 4996)
#include <stdio.h>
struct Student
{
	float sx;
	float yw;
	float yy;
	float score;
}stu[5];
void ave(Student ty[], int len)
{
	float a, b, c, total = 0;
	
	for (int i = 0; i < len; i++)
	{
		printf("第%d个学生语文，数学，英语成绩", i + 1);
		scanf("%f%f%f", &a, &b, &c);
		stu[i].sx = b;
		stu[i].yw = a;
		stu[i].yy = c;
		
		stu[i].score = a + b + c;
	}
}
void print(Student ty[], int len)
{
	
	for (int i = 0; i < len; i++)
	{
		printf("学生%d的平均分是：%0.2f\n",i+1,ty[i].score / 3);
	}

}
void ave2(Student ty[], int len)
{
	float y = 0, u = 0, o = 0;
	for (int i = 0; i < len; i++)
	{

		y += ty[i].sx;
		u += ty[i].yw;
		o += ty[i].yy;

	}
	printf("语文平均分为：%0.2f\n", u / 5);
	printf("数学平均分为：%0.2f\n", y / 5);
	printf("英语平均分为：%0.2f\n", o / 5);
}
void main()
{
	ave(stu, 5);
	ave2(stu, 5);
	print(stu, 5);
	
}