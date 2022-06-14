#include<string.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#define N 10
#define M 3/*科目数*/
struct student
{
	int num;
	char name[15];
	int score[M];
	float avg;
};
int count;
int sort_type = 0;
struct student stu[N];
void quit();
void waiting();
void sort();
void del();
void input();
void display();
void homepage();
void change();

int  main()
{
	int k;
	char a[20], b[15];
		printf("\n\n");
	printf(" \t####################################\n");
	printf(" \t#                                  #\n");
	printf(" \t#       欢迎使用学生管理系统       #\n");
	printf(" \t#                                  #\n");
	printf(" \t#           2020年5月20日          #\n");
	printf(" \t#           龙智亮制作             #\n"); 
	printf(" \t####################################\n");
	for (k = 1; k <= 5; k++)
	{
		printf("请输入账户名：\n");
		gets(a);
		printf("请输入账户密码：\n");
		gets(b);
		system("cls");
		if ((strcmp(a, "qw") == 0) && (strcmp(b, "123456") == 0))
		{
			printf("登入成功\n");
			break;
		}
		else
		{
			printf("登入失败\n");
			if (k == 5)
			{
				printf("错误次数达到5次，退出登入");
				quit();
			}
		}
	}
	homepage();
	
	return 0;
}


void homepage()
{
	char n;
	printf("\n\n");
	printf(" \t###################################\n");
	printf(" \t#                                 #\n");
	printf(" \t#         1.显示成绩              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         2.录入成绩              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         3.删除记录              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         4.排序                  #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         5.修改成绩              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         0.退出                  #\n");
	printf(" \t#                                 #\n");
	printf(" \t###################################\n");
	n = 10;
	while ((n != '1') && (n != '2') && (n != '3') && (n != '4') && (n != '5') && (n != '0'))
	{
		printf("\n请选择:");
		fflush(stdin);
		scanf("%c", &n);
		switch (n)
		{
		case '1':	display();	system("pause");	break;
		case '2': 	if (count < N)	input();
					else
		{
			printf("记录已满\n");
			Sleep(2000);
			system("cls");
			homepage();
		}
		case '3':	del();	break;
		case '4':   sort(); break;
		case '5':   change(); break;
		case '0':   quit(); break;
		default:	printf("\n选项错误\n");
		}
	}
}


void display()
{
	int i, j, sort_type=6;
	char c;
	system("cls");
	switch (sort_type)
	{
	case 0:
		printf("\t\t未排序\n\n"); break;
	case 1:
		printf("\t\t按学号排序:\n\n"); break;
	case 2:
		printf("\t\t按成绩1排序:\n\n"); break;
	case 3:
		printf("\t\t按成绩2排序:\n\n"); break;
	case 4:
		printf("\t\t按成绩3排序:\n\n"); break;
	case 5:
		printf("\t\t按平均成绩排序:\n\n"); break;
	default:
		printf("显示如下:\n");
	}
	printf("\t学号\t姓名\t成绩1\t成绩2\t成绩3\t平均成绩\n");
	for (i = 0; i < count; i++)
	{
		printf("\t%d\t%s", stu[i].num, stu[i].name);
		for (j = 0; j < M; j++)
			printf("\t%3d", stu[i].score[j]);
		printf("\t%5.2f\n", stu[i].avg);
	}
	system("pause");
	system("cls");
	homepage();
}


void input()
{
	int i, numcheck;
	float s;
	char c;
	system("cls");
	do {
		printf("学号:\n");
		scanf("%d", &stu[count].num);
		numcheck = 1;
		if (stu[count].num < 0)
		{
			printf("你要知道你必须要输入正确的数!\n再次输入:\n");
			numcheck = 0;
		}
		for (i = 0; i < count; i++)
		{
			if (stu[count].num == stu[i].num)
			{
				numcheck = 0;
				printf("学号重复啦，你要知道学号是唯一，再次输入:\n");
			}
		}
	} while (!numcheck);/*numcheck=1,结束循环*/
	printf("姓名:\n");
	gets(stu[count].name);
	fflush(stdin);
	gets(stu[count].name);
	s = 0;
	fflush(stdin);
	for (i = 0; i < M; i++)
	{
		printf("第%d门课成绩:\n",i+1);
		scanf("%d", &stu[count].score[i]);/*输入各门成绩*/
		s += stu[count].score[i];/*计算总和*/
	}
	stu[count].avg = s / M;
	count++;
	printf("是否继续输入(y/n):\n");
	do {
		fflush(stdin);
		c = getchar();
		if (c == 'y' || c == 'Y')
		{
			if (count < 10)	
				input();
			else {
				printf("记录已满\n");
				Sleep(2000);
				system("cls");
				homepage();
			}
		}
		else if (c == 'n' || c == 'N')
		{
			system("cls");
			homepage();
			break;
		}
		else
		{
			printf("叫你输入'是否'呐，重新输入:\n");
		}
	} while ((c != 'y') && (c != 'n') && (c != 'Y') && (c != 'N'));
}


void del()
{
	int i, j, del_num, match = 0;
	char c;
	system("cls");
	printf("请输入要删除的学生学号:\n");
	scanf("%d", &del_num);
	waiting();
	for (i = 0; i < count; i++)
	{
		if (stu[i].num == del_num)
		{
			match = 1;
			for (j = i; j < count; j++)
				stu[j] = stu[j + 1];/*覆盖清除*/
			count--;
			display();
		}
	}
	if (!match)
		printf("没有要找的学生号.\n");
	printf("是否继续删除?(y/n)");
	fflush(stdin);
	do {
		c = getchar();
		if (c == 'y' || c == 'Y')
		{
			count--;
			del();
		}
		else if (c == 'n' || c == 'N')
		{
			system("cls");
			homepage();
			break;
		}
		else
			printf("无法识别标志符\n");
	} while ((c != 'y') && (c != 'n'));
}


void sort()
{
	int i, j;
	int choice;
	struct student temp;/*中间结构体，用于交换数值*/
	system("cls");
	printf("\t\t请选择排序功能:\n");
	printf("\t1.按学号排序\n");
	printf("\t2.按成绩1排序\n");
	printf("\t3.按成绩2排序\n");
	printf("\t4.按成绩3排序\n");
	printf("\t5.按平均成绩排序\n");
	fflush(stdin);
	do
	{
		scanf("%d", &choice);
	} while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5));
	switch (choice)
	{
	case 1:
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				if (stu[i].num > stu[j].num)/*从stu[0]开始与stu[j](j=0-9)比较，若大于则交换数值，i+1。*/
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}

		}
		sort_type = 1; break;
	case 2:
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				if (stu[i].score[0] > stu[j].score[0])
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}

		}
		sort_type = 2;	break;
	case 3:
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count - 1; j++)
			{
				if (stu[i].score[1] > stu[j].score[1])
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}

		}
		sort_type = 3;	break;
	case 4:
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				if (stu[i].score[2] > stu[j].score[2])
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}

		} sort_type = 4;	break;
	case 5:
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				if (stu[i].avg > stu[j].avg)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}

		} sort_type = 5;	break;
	}
	system("cls");
	waiting();
	display();
	homepage();
}
void change()
{
	int num,i,j,k,p,l,point,t,s;
	char c;
	printf("请输入修改学生的学号\n");
	scanf("%d",&num);
	for (i = 0; i <= count; i++)
	{
		if (stu[i].num == num)
		{
			for (l = 0; l < 1; l++)
			{
				printf("请选择需要修改的科目：\n");
				scanf("%d", &p);
				if (p > 0 && p <= M)
				{
					switch (p)
					{
					case 1:printf("当前分值为%d,请输入新分值\n", stu[i].score[0]);
						scanf("%d", &point);
						stu[i].score[0] = point;
						printf("修改成功，新成绩为%d\n", stu[i].score[0]);
						break;
					case 2:printf("当前分值为%d,请输入新分值\n", stu[i].score[1]);
						scanf("%d", &point);
						stu[i].score[1] = point;
						printf("修改成功，新成绩为%d\n", stu[i].score[1]);
						break;
					case 3:printf("当前分值为%d,请输入新分值\n", stu[i].score[2]);
						scanf("%d", &point);
						stu[i].score[2] = point;
						printf("修改成功，新成绩为%d\n", &stu[i].score[2]);
						break;
					}
					system("cls");
					s = 0;
					for (t = 0; t < M; t++)
						s += stu[i].score[t];
					stu[i].avg = s / M;
					printf("请选择是否需要再次更改，Y/N?\n");
					scanf("%c", &c);
					do {
						c = getchar();
						if (c == 'y' || c == 'Y')
						{
							l = l - 1;
						}
						else if (c == 'n' || c == 'N')
						{
							system("cls");
							waiting();
							homepage();
						}
						else
							printf("无法识别标志符\n");
					} while ((c != 'y') && (c != 'n'));
				}
			}
		}
		
	}
	
		
	printf("未查找到该学号，请选择是否重新输入，Y/N?\n");
	scanf("%c", &c);
	fflush(stdin);
	do {
		c = getchar();
		if (c == 'y' || c == 'Y')
		{
			change();
		}
		else if (c == 'n' || c == 'N')
		{
			system("cls");
			homepage();
			break;
		}
		else
			printf("无法识别标志符\n");
	} while ((c != 'y') && (c != 'n'));
	
}


void waiting()
{
	int i;
	printf("\n\..t请稍侯.....");
	for (i = 0; i < 25; i++)
	{
		switch (i % 4)
		{
		case 1:printf("\b\\"); break;
		case 2:printf("\b"); break;
		case 3:printf("\b/"); break;
		case 0:printf("\b|"); break;
		}
		Sleep(1);
	}
	system("cls");
}

void quit()
{
	printf("\n\n\n");
	printf("                   ^^^^^^^^^^^^^^\n");
	printf("\n\n");
	printf("                   ^感谢您的使用^\n");
	printf("\n\n");
	printf("                   ^^^^^^^^^^^^^^\n");
	printf("\n\n\n");
	exit(0);
}