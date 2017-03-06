#include"my.h"
#include<string.h>
extern struct proinfo user,*AI;
int login(){
	//printf("登录\n");
	printf("请输入AI账号：");
	int num;
	//scanf("%d",&num);
	num=singal_unsigned_in();
	char s[100]="个人信息//info_",*cp=s,str[13];
	itoa(num,str,10);
	strcat(cp,str);strcat(cp,".txt");
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("抱歉，%d还未注册\n",num);
		printf("\n请重新输入口令：");
		return -1; //需要重新输入口令 
	}
	fread(AI,sizeof(user),1,fp);
	fclose(fp);
	char pswd[20];
	do{
		printf("请输入唤醒%s的口诀（密码）:",AI->name);
		scanf("%s",pswd);pswd[strlen(pswd)]='\0';
	}while(strcmp(pswd,AI->password)!=0);
	printf("\n\n%s: Hi,%s,开始快乐的学习之旅吧！\n\n",AI->name,AI->me);
	return 0;//正常结束 
}
