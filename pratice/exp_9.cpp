#pragma warning(disable:4996)
#include "stdio.h"    
#include "string.h"     
#include "stdlib.h"   
#include <windows.h> 

typedef struct student
{
	long int num;
	char name[10];
	char sex[5];
	long int phone;
	char address[100];
	float score;
};

struct student list[999];

int count = 0;//计数器

void Welcome();//欢迎界面
void ShowMenu();//菜单
void Insert();//插入
void Find();//查找
void Delete();//删除
void Update();//更新
void Readingfile();//读取文件
void Quit();//退出
void all();//学生信息总览
void write_file();//写入文件
void sort_Score();//按成绩排序
void sort_id();//按学号排序


void sort_id() {
	int done = 0;
	int k = count;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (list[j].num > list[j + 1].num) {
				list[999] = list[j];
				list[j] = list[j + 1];
				list[j + 1] = list[999];
				done = 1;
			}
		}
		if (done == 0) break;
	}
	count = k;
	printf("排序完成！！！");
}
int main()
{
	int choice;
	Readingfile();
	Welcome();
	ShowMenu();
	scanf("%d", &choice);

	do
	{
		Readingfile();
		switch (choice)
		{
		case 1:

			Insert();
			break;
		case 2:
			Find();
			break;
		case 3:
			Delete();
			break;
		case 4:
			Update();

			break;
		case 5:
			all();
			break;
		case 6:
			sort_Score();
			break;
		case 7:
			sort_id();
			break;
		default:
			write_file();
			Quit();
			exit(0);
		}
		write_file();
		Readingfile();
		ShowMenu();
		scanf("%d", &choice);
	} while (choice != 0);
}

void sort_Score() {
	int done = 0;
	int k = count;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (list[j].score > list[j + 1].score) {
				list[999] = list[j];
				list[j] = list[j + 1];
				list[j + 1] = list[999];
				done = 1;
			}
		}
		if (done == 0) break;
	}
	count = k;
	printf("排序完成！！！");
}

void all() {

	if (count == 0) {
		printf("当前文件为空!");
	}
	else {
		printf("学生的信息如下：\n");
		printf("序号   姓名      性别     学号        电话       家庭住址    入学成绩\n");
		for (int i = 0; i < count; i++)
		{
			printf("%d", i + 1);
			printf("%12s", list[i].name);
			printf("%6s", list[i].sex);
			printf("%12ld", list[i].num);
			printf("%12ld", list[i].phone);
			printf("%12s", list[i].address);
			printf("%12.1f\n", list[i].score);

		}
	}

}

//欢迎界面
void Welcome() {
	printf("正在进入学生通讯录管理系统............\n");
	printf("\n");
	Sleep(1000);
	printf("\n进入中...\n");
	printf("\n");
	Sleep(1000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录管理系统	       **\n");
	printf("*************************************************\n");
	Sleep(1000);
}


//菜单界面
void ShowMenu() {
	printf("\n");
	printf("\n正在加载菜单.........\n");
	Sleep(1000);
	printf("*************************************************\n");
	printf("**	        	 菜单		       **\n");
	printf("*************************************************\n");
	printf("\n当前系统中共有%d名学生\n", count);
	printf("\n1: 信息录入\n2：信息查询\n3：删除成员\n4：信息更新\n5、学生信息总览\n6、按入学成绩排序\n7、按学号排序\n0: 退出系统\n");
	printf("请选择要进行的操作：");
}



//读取文件
void Readingfile()
{
	FILE* fp;
	if ((fp = fopen("info.txt", "r")) == NULL)
	{
		printf("can't open file!\n");
		exit(0);
	}
	if (feof(fp)) count = 0;
	else {
		fscanf(fp, "%d", &count);
		while (!feof(fp))
		{
			for (int i = 0; i < count; i++) {
				fscanf(fp, "%s%s%ld%ld%s%f", &list[i].name, &list[i].sex, &list[i].num, &list[i].phone, &list[i].address, &list[i].score);
			}

		}
	}

	fclose(fp);

}


void write_file() {
	FILE* fp1;
	fp1 = fopen("info.txt", "w");
	if (fp1 == NULL)
	{
		puts("Fail to open file!");
		exit(1);
	}
	fprintf(fp1, "%d\n", count);
	for (int i = 0; i < count; i++) {
		fprintf(fp1, "%s %s %ld %ld %s %f\n", list[i].name, list[i].sex, list[i].num, list[i].phone, list[i].address, list[i].score);
	}

	fclose(fp1);
}

//手动输入数据
void Insert() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("请输入学生的\n姓名：");
	scanf("%s", &list[count].name);

	printf("请输入学生的\n性别(男/女)：");
	char InputSex[5];
	char Man[5] = "男";
	char Woman[7] = "女";
	scanf("%s", &InputSex);

	if (strcmp(InputSex, Man) == 0 || strcmp(InputSex, Woman) == 0)
	{
		strcpy(list[count].sex, InputSex);
	}

	else
	{
		printf("输入的性别格式错误!\n");
		exit(0);
	}

	printf("请输入学生的\n学号：");
	scanf("%ld", &list[count].num);

	printf("请输入学生的\n电话：");
	scanf("%ld", &list[count].phone);

	printf("请输入学生的\n住址：");
	scanf("%s", &list[count].address);

	printf("请输入学生的\n入学成绩：");
	scanf("%f", &list[count].score);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("提示：   信息录入成功!");
	count++;
}


//查询
void Find()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n正在进入学生通讯录查询系统.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录查询系统	       **\n");
	printf("*************************************************\n");
	char FindName[10] = { 0 };
	printf("请输入需要查询的学生的姓名:\n");
	scanf("%s", &FindName);

	int p = 0;
	for (int i = 0; i <= count; i++)
	{
		if (strcmp(FindName, list[i].name) == 0)
		{
			p = 1;
			printf("\n");
			printf("\n");
			printf("\n");
			printf("该学生的信息如下：\n");
			printf("姓名：%s\n", list[i].name);
			printf("性别：%s\n", list[i].sex);
			printf("学号：%ld\n", list[i].num);
			printf("电话：%ld\n", list[i].phone);
			printf("家庭住址：%s\n", list[i].address);
			printf("入学成绩：%f\n", list[i].score);
		}
		
	}
	if (p == 0)
	{
		printf("\n");

		printf("提示：    没有找到该学生！\n");
	}
}
//删除
void Delete()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n正在进入学生通讯录删除系统.........\n");
	Sleep(1000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录删除系统	       **\n");
	printf("*************************************************\n");
	char DeleteName[10] = { 0 };
	printf("请输入需要删除的学生的姓名：\n");
	scanf("%s", &DeleteName);
	int p = 0;
	for (int i = 0; i < count; i++)
	{

		if (strcmp(DeleteName, list[i].name) == 0)
		{
			p = 1;
			list[i] = list[i + 1];
			printf("\n");


			printf("提示：     信息删除成功！\n");
			count--;
		}

	}
	if (p == 0)
	{
		printf("\n");
		printf("提示：    没有找到该学生！\n");
	}
}



//更新
void Update()
{

	printf("\n");
	printf("\n正在进入学生通讯录更新系统.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录更新系统	       **\n");
	printf("*************************************************\n");
	char UpdateName[10] = { 0 };
	int choice = 0;
	printf("请输入需要更新信息的学生的姓名：\n");
	scanf("%s", &UpdateName);
	int p = 0;

	for (int i = 0; i < count; i++)
	{

		if (strcmp(UpdateName, list[i].name) == 0)
		{
			p = 1;
			do
			{
				printf("请输入需要更改的项目：\n");
				printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t0 返回菜单\n");
				scanf("%d", &choice);
				if (choice == 0) break;
				switch (choice)
				{
				case 1:
					printf("请输入新学号：");
					long int newnum;
					scanf("%ld", &newnum);
					list[i].num = newnum;


					break;
				case 2:
					printf("请输入新性别：");
					char newsex[5];
					scanf("%s", &newsex);
					strcpy(list[i].sex, newsex);

					break;
				case 3:
					printf("请输入新电话：");
					long int newphone;
					scanf("%ld", &newphone);
					list[i].phone = newphone;

					break;
				case 4:
					printf("请输入新住址：");
					char newaddress[100];
					scanf("%s", &newaddress);
					strcpy(list[i].address, newaddress);

					break;

				default:
					printf("请输入正确的选项！\n");

					break;
				}

				printf("请输入需要更改的项目：\n");
				printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t5 入学成绩\t0 返回菜单\n");
				scanf("%d", &choice);
			} while (choice != 0);
		}

	}
	if (p == 0)
	{
		printf("\n");


		printf("提示：    没有找到该学生！\n");
	}
}



//退出系统
void Quit()
{
	printf("\n正在退出.........\n");
	Sleep(3000);
	printf("提示：    退出成功！");
}