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

int count = 0;//������

void Welcome();//��ӭ����
void ShowMenu();//�˵�
void Insert();//����
void Find();//����
void Delete();//ɾ��
void Update();//����
void Readingfile();//��ȡ�ļ�
void Quit();//�˳�
void all();//ѧ����Ϣ����
void write_file();//д���ļ�
void sort_Score();//���ɼ�����
void sort_id();//��ѧ������


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
	printf("������ɣ�����");
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
	printf("������ɣ�����");
}

void all() {

	if (count == 0) {
		printf("��ǰ�ļ�Ϊ��!");
	}
	else {
		printf("ѧ������Ϣ���£�\n");
		printf("���   ����      �Ա�     ѧ��        �绰       ��ͥסַ    ��ѧ�ɼ�\n");
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

//��ӭ����
void Welcome() {
	printf("���ڽ���ѧ��ͨѶ¼����ϵͳ............\n");
	printf("\n");
	Sleep(1000);
	printf("\n������...\n");
	printf("\n");
	Sleep(1000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼����ϵͳ	       **\n");
	printf("*************************************************\n");
	Sleep(1000);
}


//�˵�����
void ShowMenu() {
	printf("\n");
	printf("\n���ڼ��ز˵�.........\n");
	Sleep(1000);
	printf("*************************************************\n");
	printf("**	        	 �˵�		       **\n");
	printf("*************************************************\n");
	printf("\n��ǰϵͳ�й���%d��ѧ��\n", count);
	printf("\n1: ��Ϣ¼��\n2����Ϣ��ѯ\n3��ɾ����Ա\n4����Ϣ����\n5��ѧ����Ϣ����\n6������ѧ�ɼ�����\n7����ѧ������\n0: �˳�ϵͳ\n");
	printf("��ѡ��Ҫ���еĲ�����");
}



//��ȡ�ļ�
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

//�ֶ���������
void Insert() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("������ѧ����\n������");
	scanf("%s", &list[count].name);

	printf("������ѧ����\n�Ա�(��/Ů)��");
	char InputSex[5];
	char Man[5] = "��";
	char Woman[7] = "Ů";
	scanf("%s", &InputSex);

	if (strcmp(InputSex, Man) == 0 || strcmp(InputSex, Woman) == 0)
	{
		strcpy(list[count].sex, InputSex);
	}

	else
	{
		printf("������Ա��ʽ����!\n");
		exit(0);
	}

	printf("������ѧ����\nѧ�ţ�");
	scanf("%ld", &list[count].num);

	printf("������ѧ����\n�绰��");
	scanf("%ld", &list[count].phone);

	printf("������ѧ����\nסַ��");
	scanf("%s", &list[count].address);

	printf("������ѧ����\n��ѧ�ɼ���");
	scanf("%f", &list[count].score);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("��ʾ��   ��Ϣ¼��ɹ�!");
	count++;
}


//��ѯ
void Find()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n���ڽ���ѧ��ͨѶ¼��ѯϵͳ.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼��ѯϵͳ	       **\n");
	printf("*************************************************\n");
	char FindName[10] = { 0 };
	printf("��������Ҫ��ѯ��ѧ��������:\n");
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
			printf("��ѧ������Ϣ���£�\n");
			printf("������%s\n", list[i].name);
			printf("�Ա�%s\n", list[i].sex);
			printf("ѧ�ţ�%ld\n", list[i].num);
			printf("�绰��%ld\n", list[i].phone);
			printf("��ͥסַ��%s\n", list[i].address);
			printf("��ѧ�ɼ���%f\n", list[i].score);
		}
		
	}
	if (p == 0)
	{
		printf("\n");

		printf("��ʾ��    û���ҵ���ѧ����\n");
	}
}
//ɾ��
void Delete()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n���ڽ���ѧ��ͨѶ¼ɾ��ϵͳ.........\n");
	Sleep(1000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼ɾ��ϵͳ	       **\n");
	printf("*************************************************\n");
	char DeleteName[10] = { 0 };
	printf("��������Ҫɾ����ѧ����������\n");
	scanf("%s", &DeleteName);
	int p = 0;
	for (int i = 0; i < count; i++)
	{

		if (strcmp(DeleteName, list[i].name) == 0)
		{
			p = 1;
			list[i] = list[i + 1];
			printf("\n");


			printf("��ʾ��     ��Ϣɾ���ɹ���\n");
			count--;
		}

	}
	if (p == 0)
	{
		printf("\n");
		printf("��ʾ��    û���ҵ���ѧ����\n");
	}
}



//����
void Update()
{

	printf("\n");
	printf("\n���ڽ���ѧ��ͨѶ¼����ϵͳ.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼����ϵͳ	       **\n");
	printf("*************************************************\n");
	char UpdateName[10] = { 0 };
	int choice = 0;
	printf("��������Ҫ������Ϣ��ѧ����������\n");
	scanf("%s", &UpdateName);
	int p = 0;

	for (int i = 0; i < count; i++)
	{

		if (strcmp(UpdateName, list[i].name) == 0)
		{
			p = 1;
			do
			{
				printf("��������Ҫ���ĵ���Ŀ��\n");
				printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t0 ���ز˵�\n");
				scanf("%d", &choice);
				if (choice == 0) break;
				switch (choice)
				{
				case 1:
					printf("��������ѧ�ţ�");
					long int newnum;
					scanf("%ld", &newnum);
					list[i].num = newnum;


					break;
				case 2:
					printf("���������Ա�");
					char newsex[5];
					scanf("%s", &newsex);
					strcpy(list[i].sex, newsex);

					break;
				case 3:
					printf("�������µ绰��");
					long int newphone;
					scanf("%ld", &newphone);
					list[i].phone = newphone;

					break;
				case 4:
					printf("��������סַ��");
					char newaddress[100];
					scanf("%s", &newaddress);
					strcpy(list[i].address, newaddress);

					break;

				default:
					printf("��������ȷ��ѡ�\n");

					break;
				}

				printf("��������Ҫ���ĵ���Ŀ��\n");
				printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t5 ��ѧ�ɼ�\t0 ���ز˵�\n");
				scanf("%d", &choice);
			} while (choice != 0);
		}

	}
	if (p == 0)
	{
		printf("\n");


		printf("��ʾ��    û���ҵ���ѧ����\n");
	}
}



//�˳�ϵͳ
void Quit()
{
	printf("\n�����˳�.........\n");
	Sleep(3000);
	printf("��ʾ��    �˳��ɹ���");
}