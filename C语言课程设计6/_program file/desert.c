#include<stdio.h>
#include<string.h>
void desert(){//无边沙漠就是待开发区的意思，可以增加一些新的功能 
	char *cp="无边沙漠//desert.txt";
	show_txt(cp); 
}

void contact_us(){//联系我们 和 无边沙漠 功能类似，写在一个文件内 
	{
		char *cp="联系我们//contact_us.txt";
		show_txt(cp);
	}
	
	printf("\n请先用关键字描述一下您的问题(0->退出)：");
	char filename[80]="联系我们//",*cp=filename,buffer[50];
	scanf("%s",buffer);
	getchar();
	if(strlen(buffer)==1&&*buffer=='0') return; 
	strcat(cp,buffer);
	strcat(cp,".txt");
	FILE *fp;
	if((fp=fopen(cp,"w"))==NULL){
		printf("\n写入文件出错\n");
		return;
	}
	printf("\n请详细描述您的问题(3个回车结束输入):\n");
	char filetxt[2400],*p=filetxt,ch;
	int count=0;
	while(count<3){
		*p=getchar();
		if(*p++=='\n') count++; 
		else count=0;
	}//写文档 
	fwrite(filetxt,p-filetxt,1,fp);//这是笔记本部分的代码 
	fclose(fp);	
	//上传文件 
	add_groth_value(3);//反馈信息可得三份积分 
	printf("\n感谢您的反馈！\n");
}
