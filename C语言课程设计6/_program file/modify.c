#include"my.h"
extern struct proinfo user,*AI;
void modify_pswd(){
	//printf("修改密码\n");
	
	int num; 
	printf("请输入要修改的AI账号：");
	scanf("%d",&num);
	char s[100]="个人信息//info_",*cp=s,str[13];
	itoa(num,str,10);
	strcat(cp,str);strcat(cp,".txt");
	FILE *fp; 
	if((fp=fopen(cp,"rt"))==NULL){
		puts("读入文件错误，您是不是还没注册[流汗]\n");
		printf("已经退出修改密码的程式，请重新输入口令：");
		return; 
	}
	fread(AI,sizeof(struct proinfo),1,fp);
	fclose(fp);
	do{
		printf("请输入%s的原密码：",AI->name);
		char oldpswd[20]; 
		scanf("%s",oldpswd);oldpswd[strlen(oldpswd)]='\0';
		if(strcmp(oldpswd,AI->password)==0){
			printf("请输入新密码：");
			scanf("%s",oldpswd);
			char newpswd[20];
			printf("请再次输入密码确认：");
		 	scanf("%s",newpswd);
		 	if(strcmp(oldpswd,newpswd)==0){
		 		newpswd[strlen(newpswd)]='\0';
		 		strcpy(AI->password,newpswd);
	 		  	fp=fopen(cp,"wt");
		 		fwrite(AI,sizeof(user),1,fp);
		 		fclose(fp);
		 		puts("密码修改成功，请牢记新密码啊\n");
		 		break;
		 	}else puts("两次输入不一样，密码修改失败\n");
		}
	}while(1);//若密码修改不成功就一直循环。想退出，点黑框框右上角的叉子 	
}//修改密码
