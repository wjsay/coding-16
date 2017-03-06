#include"my.h"
extern struct proinfo *AI;
void looktxt(){
	printf("	查看文件\n\n");
	
	char contents[100]="笔记本//用户 (";
	char str[13];
	itoa(AI->ID,str,10); 
	strcat(strcat(contents,str),")//目录.txt");//建立目录路径的绝句代码 
	printf("所有文件:\n");
	show_txt(contents);
	FILE *fp;
	while(1){
		char filepath[100]="笔记本//用户 (",*cp=filepath;
		strcat(strcat(cp,str),")//");
		
		printf("请输入要查看的文件名(0->结束)：");
		char filename[50];
		fflush(stdin);
		gets(filename);
		if(strlen(filename)==1&&filename[0]=='0') {
			printf("已退出查看\n"); 
			break; 
		}
		strcat(strcat(cp,filename),".txt");
		if((fp=fopen(cp,"rt"))==NULL){
			printf("没有文件：%s\n",filename);
			continue;
		} 
		fclose(fp);
		show_txt(cp);
	} 
} 
