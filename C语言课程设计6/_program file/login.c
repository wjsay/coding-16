#include"my.h"
#include<string.h>
extern struct proinfo user,*AI;
int login(){
	//printf("��¼\n");
	printf("������AI�˺ţ�");
	int num;
	//scanf("%d",&num);
	num=singal_unsigned_in();
	char s[100]="������Ϣ//info_",*cp=s,str[13];
	itoa(num,str,10);
	strcat(cp,str);strcat(cp,".txt");
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("��Ǹ��%d��δע��\n",num);
		printf("\n������������");
		return -1; //��Ҫ����������� 
	}
	fread(AI,sizeof(user),1,fp);
	fclose(fp);
	char pswd[20];
	do{
		printf("�����뻽��%s�Ŀھ������룩:",AI->name);
		scanf("%s",pswd);pswd[strlen(pswd)]='\0';
	}while(strcmp(pswd,AI->password)!=0);
	printf("\n\n%s: Hi,%s,��ʼ���ֵ�ѧϰ֮�ðɣ�\n\n",AI->name,AI->me);
	return 0;//�������� 
}
