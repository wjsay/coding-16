#include"my.h"
extern struct proinfo *AI;
void newtxt(){
	char filepath[100]="笔记本//用户 (",*cp=filepath,str[13];
	itoa(AI->ID,str,10);
	strcat(cp,str);strcat(cp,")//");
	printf("输入新建文档的名字(0->退出)：");//笔记本//用户 (AI->ID)// filename.txt
	char filename[50];
	fflush(stdin);
	gets(filename);
	if(strlen(filename)==1&&*filename==0){
		printf("已退出\n");
		return; 
	} 
	strcat(strcat(cp,filename),".txt");
	printf("附：输入连续的三个回车键表示写完啦\n"); 
	char filetxt[2400],*p=filetxt,ch;
	int count=0;
	while(count<3){
		*p=getchar();
		if(*p++=='\n') count++; 
		else count=0;
	}//写文档 
	FILE *fp;
	fp=fopen(cp,"wt");
	fwrite(filetxt,p-filetxt,1,fp);//指针p还可以用一下 
	fclose(fp);
	
	char contents[100]="笔记本//用户 (";
	strcat(strcat(contents,str),")//目录.txt");
	if((fp=fopen(contents,"a+"))==NULL){
		printf("文件受损,进入死循环\n");
		while(1);
	}
	fprintf(fp,"%s\n\r",filename);
	fclose(fp);
	printf("\n\n写入完成，已存储好了\n"); 
}
//使用新函数system("mkdir,folder"); 
