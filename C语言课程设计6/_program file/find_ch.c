#include<stdio.h>
#include"my.h"
#define maxn 1000000//6��0
char str[maxn];
extern struct proinfo *AI;
void find_ch(){
	printf("	Ѱ���ַ����еĺ��֣�����û��˭\n\n������%s����",AI->name);
	printf("��˫�ۣ�%s����һ���ַ�����\n\n��������ٸ����֣�\n\n",AI->me);
	while(gets(str)){
		char *p=str;
		int count=0;
		while(*p) 
			if(*p++<0) count++;
		printf("%d��\n",count/2);
		printf("\nֱ������,����(Ctrl+Z ->�˳�):\n");
	}
	printf("���˳�����ʶ�֣����ص���Ϸ�˵�\n"); 
} 
