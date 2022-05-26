#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<iostream>
using namespace std;
typedef struct node {
	int lev;
	char data;
} levelnode;
void print(levelnode array[])
{
	char p[20];
	scanf("%s",p);
	printf("%c", p[1]);
}
void input(levelnode array[])//C++·½·¨
{
	string s1;	
	int p = 0;
	cin >> s1;
	while (s1 != "#") {
		int len = s1.size();
		array[p].data = (char)s1[len - 1];
		char c[20];
		strcpy(c, s1.substr(0, len - 1).c_str());
		array[p].lev = atoi(c);
		p++;
		cin >> s1;
	}
}
void main() 
{
	levelnode l1[20];
	//input(l1);
	//cout<<l1[0].data<<l1[0].lev;
	print(l1);
}