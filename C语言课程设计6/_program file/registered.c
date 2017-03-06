#include"my.h"
#include<stdlib.h>
#include<string.h>
extern struct proinfo *AI;
extern struct proinfo user;
void registered(){
	//printf("注册\n");//调试用 
	char *cp_user_ID="个人信息//用户总数.txt";
	FILE *fp; 
	char pswd[20];
	if((fp=fopen(cp_user_ID,"r"))==NULL){
		printf("打开文件失败，无法得到AI编号\n");
		exit(0);
	}
	fscanf(fp,"%u",&user.ID);
	fclose(fp); //读完立马关闭 
	AI->ID++;//新建的ID编号
	char str[12]; 
	itoa(AI->ID,str,10);//把十进制的ID号转化为字符串 ,(会补'\0') 
	strcpy(AI->path,"个人信息//info_");
	strcat(AI->path,str);strcat(AI->path,".txt");//建立好路径，以后可能用 
	AI->path_p=AI->path;
	printf("您的AI编号是：%u\n",AI->ID);
	printf("请输入AI的信息，赋予其生命\n");
	printf("昵称：");
	scanf("%s",AI->name);
	do{
		printf("设置密码：");
		scanf("%s",AI->password);
		AI->password[strlen(AI->password)]='\0'; //printf("%s\n",p->password);
												//若不加'\0',密码看上去一样，但不相等 
		printf("请再次输入确认：");
		scanf("%s",pswd);
		pswd[strlen(pswd)]='\0';  //printf("%s\n",pswd);
	}while(strcmp(pswd,AI->password)!=0); //直到两次输入密码一样 
	printf("年级（数字）：");
	//scanf("%d",&(AI->grade));
	AI->grade=singal_unsigned_in();
	printf("邮箱将作为找回密码的唯一途径，请谨慎输入!\n");
	printf("邮箱：");
	scanf("%s",AI->mail);
	printf("地址：");
	scanf("%s",AI->dress); 
	printf("备注：");
	scanf("%s",AI->ps);
	printf("最后，你希望AI怎样称呼你呢：");
	scanf("%s",AI->me);
	fp=fopen(AI->path,"wt");
	fwrite(AI,sizeof(struct proinfo),1,fp);
	fclose(fp);
	fp=fopen(cp_user_ID,"wt");//更新用户总数 
	fprintf(fp,"%u\n",AI->ID);
	fclose(fp);
	printf("\n\n恭喜你拥有了AI小伙伴:%s\n开启冒险之旅吧！\n\n",AI->name); 
}//注册账号 
