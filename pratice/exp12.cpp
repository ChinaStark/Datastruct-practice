#include<string.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#define N 10
#define M 3/*��Ŀ��*/
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
	printf(" \t#       ��ӭʹ��ѧ������ϵͳ       #\n");
	printf(" \t#                                  #\n");
	printf(" \t#           2020��5��20��          #\n");
	printf(" \t#           ����������             #\n"); 
	printf(" \t####################################\n");
	for (k = 1; k <= 5; k++)
	{
		printf("�������˻�����\n");
		gets(a);
		printf("�������˻����룺\n");
		gets(b);
		system("cls");
		if ((strcmp(a, "qw") == 0) && (strcmp(b, "123456") == 0))
		{
			printf("����ɹ�\n");
			break;
		}
		else
		{
			printf("����ʧ��\n");
			if (k == 5)
			{
				printf("��������ﵽ5�Σ��˳�����");
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
	printf(" \t#         1.��ʾ�ɼ�              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         2.¼��ɼ�              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         3.ɾ����¼              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         4.����                  #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         5.�޸ĳɼ�              #\n");
	printf(" \t#                                 #\n");
	printf(" \t#         0.�˳�                  #\n");
	printf(" \t#                                 #\n");
	printf(" \t###################################\n");
	n = 10;
	while ((n != '1') && (n != '2') && (n != '3') && (n != '4') && (n != '5') && (n != '0'))
	{
		printf("\n��ѡ��:");
		fflush(stdin);
		scanf("%c", &n);
		switch (n)
		{
		case '1':	display();	system("pause");	break;
		case '2': 	if (count < N)	input();
					else
		{
			printf("��¼����\n");
			Sleep(2000);
			system("cls");
			homepage();
		}
		case '3':	del();	break;
		case '4':   sort(); break;
		case '5':   change(); break;
		case '0':   quit(); break;
		default:	printf("\nѡ�����\n");
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
		printf("\t\tδ����\n\n"); break;
	case 1:
		printf("\t\t��ѧ������:\n\n"); break;
	case 2:
		printf("\t\t���ɼ�1����:\n\n"); break;
	case 3:
		printf("\t\t���ɼ�2����:\n\n"); break;
	case 4:
		printf("\t\t���ɼ�3����:\n\n"); break;
	case 5:
		printf("\t\t��ƽ���ɼ�����:\n\n"); break;
	default:
		printf("��ʾ����:\n");
	}
	printf("\tѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ���ɼ�\n");
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
		printf("ѧ��:\n");
		scanf("%d", &stu[count].num);
		numcheck = 1;
		if (stu[count].num < 0)
		{
			printf("��Ҫ֪�������Ҫ������ȷ����!\n�ٴ�����:\n");
			numcheck = 0;
		}
		for (i = 0; i < count; i++)
		{
			if (stu[count].num == stu[i].num)
			{
				numcheck = 0;
				printf("ѧ���ظ�������Ҫ֪��ѧ����Ψһ���ٴ�����:\n");
			}
		}
	} while (!numcheck);/*numcheck=1,����ѭ��*/
	printf("����:\n");
	gets(stu[count].name);
	fflush(stdin);
	gets(stu[count].name);
	s = 0;
	fflush(stdin);
	for (i = 0; i < M; i++)
	{
		printf("��%d�ſγɼ�:\n",i+1);
		scanf("%d", &stu[count].score[i]);/*������ųɼ�*/
		s += stu[count].score[i];/*�����ܺ�*/
	}
	stu[count].avg = s / M;
	count++;
	printf("�Ƿ��������(y/n):\n");
	do {
		fflush(stdin);
		c = getchar();
		if (c == 'y' || c == 'Y')
		{
			if (count < 10)	
				input();
			else {
				printf("��¼����\n");
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
			printf("��������'�Ƿ�'�ţ���������:\n");
		}
	} while ((c != 'y') && (c != 'n') && (c != 'Y') && (c != 'N'));
}


void del()
{
	int i, j, del_num, match = 0;
	char c;
	system("cls");
	printf("������Ҫɾ����ѧ��ѧ��:\n");
	scanf("%d", &del_num);
	waiting();
	for (i = 0; i < count; i++)
	{
		if (stu[i].num == del_num)
		{
			match = 1;
			for (j = i; j < count; j++)
				stu[j] = stu[j + 1];/*�������*/
			count--;
			display();
		}
	}
	if (!match)
		printf("û��Ҫ�ҵ�ѧ����.\n");
	printf("�Ƿ����ɾ��?(y/n)");
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
			printf("�޷�ʶ���־��\n");
	} while ((c != 'y') && (c != 'n'));
}


void sort()
{
	int i, j;
	int choice;
	struct student temp;/*�м�ṹ�壬���ڽ�����ֵ*/
	system("cls");
	printf("\t\t��ѡ��������:\n");
	printf("\t1.��ѧ������\n");
	printf("\t2.���ɼ�1����\n");
	printf("\t3.���ɼ�2����\n");
	printf("\t4.���ɼ�3����\n");
	printf("\t5.��ƽ���ɼ�����\n");
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
				if (stu[i].num > stu[j].num)/*��stu[0]��ʼ��stu[j](j=0-9)�Ƚϣ��������򽻻���ֵ��i+1��*/
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
	printf("�������޸�ѧ����ѧ��\n");
	scanf("%d",&num);
	for (i = 0; i <= count; i++)
	{
		if (stu[i].num == num)
		{
			for (l = 0; l < 1; l++)
			{
				printf("��ѡ����Ҫ�޸ĵĿ�Ŀ��\n");
				scanf("%d", &p);
				if (p > 0 && p <= M)
				{
					switch (p)
					{
					case 1:printf("��ǰ��ֵΪ%d,�������·�ֵ\n", stu[i].score[0]);
						scanf("%d", &point);
						stu[i].score[0] = point;
						printf("�޸ĳɹ����³ɼ�Ϊ%d\n", stu[i].score[0]);
						break;
					case 2:printf("��ǰ��ֵΪ%d,�������·�ֵ\n", stu[i].score[1]);
						scanf("%d", &point);
						stu[i].score[1] = point;
						printf("�޸ĳɹ����³ɼ�Ϊ%d\n", stu[i].score[1]);
						break;
					case 3:printf("��ǰ��ֵΪ%d,�������·�ֵ\n", stu[i].score[2]);
						scanf("%d", &point);
						stu[i].score[2] = point;
						printf("�޸ĳɹ����³ɼ�Ϊ%d\n", &stu[i].score[2]);
						break;
					}
					system("cls");
					s = 0;
					for (t = 0; t < M; t++)
						s += stu[i].score[t];
					stu[i].avg = s / M;
					printf("��ѡ���Ƿ���Ҫ�ٴθ��ģ�Y/N?\n");
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
							printf("�޷�ʶ���־��\n");
					} while ((c != 'y') && (c != 'n'));
				}
			}
		}
		
	}
	
		
	printf("δ���ҵ���ѧ�ţ���ѡ���Ƿ��������룬Y/N?\n");
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
			printf("�޷�ʶ���־��\n");
	} while ((c != 'y') && (c != 'n'));
	
}


void waiting()
{
	int i;
	printf("\n\..t���Ժ�.....");
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
	printf("                   ^��л����ʹ��^\n");
	printf("\n\n");
	printf("                   ^^^^^^^^^^^^^^\n");
	printf("\n\n\n");
	exit(0);
}