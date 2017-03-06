#include "my.h"
extern struct proinfo *AI; 
void myAI(){
	/*char *cp="个人信息//information.txt";
	char *cp2="学习积分//groth_value.txt";
	FILE *fp;
	struct proinfo user, *p=&user;
	int tot,*p2=&tot;
	if((fp=fopen(cp,"r"))==NULL){
		puts("AI拒绝你读取TA的信息,程序异常退出\n");
		exit(0); 
	} 
	fread(p,sizeof(*p),1,fp);
	fclose(fp);
	if((fp=fopen(cp2,"r"))==NULL){
		puts("读取学习积分失败，程序异常退出\n");
		exit(0);
	}
	fscanf(fp,"%d",p2);
	fclose(fp);
	//read_txt(p,cp);
	//read_txt(p2,cp2);*/ //程序修改以后，这些都用不着了 
	printf("\nAI编号(登录账号)：%d\n",AI->ID);
	printf("\f\n\n1.AI昵称：%s\n",AI->name);
	printf("\n2.我的昵称：%s\n",AI->me);
	printf("\n3.年级：%d\n",AI->grade);
	printf("\n4.地址：%s\n",AI->dress);
	printf("\n5.备注：%s\n",AI->ps);
	printf("\n邮箱用于找回密码\n");
	printf("\n当前学习积分：%d\n\n\n",AI->groth_value);
	
	//printf("\n调试专用\nAI->path_p:%s\n",AI->path_p);
	unsigned cmd;
	while(1){	
		printf("\n修改信息序号(0->退出)：");
		cmd=singal_unsigned_in();
		if(!cmd){
			break ;
		} 
		switch(cmd){
			case 1:
				printf("\n请输入新的AI昵称：");
				scanf("%s",AI->name);
				break;
			case 2:
				printf("\n请输入新的昵称：");
				scanf("%s",AI->me);
				break;
			case 3:
				printf("\n请输入新的年级：");
				AI->grade=singal_unsigned_in();
				break;
			case 4:
				printf("\n更新地址：");
				scanf("%s",AI->dress);
				break;
			case 5:
				printf("\n新的备注：");
				scanf("%s",AI->ps); 
				break;
		}
	}
	FILE *fp;
	if((fp=fopen(AI->path,"wt"))==NULL){
		printf("\n写入文件失败，异常返回\n");
		return; 
	}
	fwrite(AI,sizeof(struct proinfo),1,fp);
	fclose(fp);
	printf("\n更改信息完成\n"); 
}
