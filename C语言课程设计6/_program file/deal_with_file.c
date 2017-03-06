#include<stdio.h>
#include<stdlib.h>

/*显示文本文档全部内容的函数 show_txt
需要一个文件地址的指针参数，无返回值 */
void show_txt(char *cp){//便于代码重用 
	FILE *fp;
	//char *p="欢迎用户界面//welcome.txt";//调试该函数用的 
	if((fp=fopen(cp,"rt"))==NULL){
		printf("找不到该打开的文件，请联系程序员\n");
		exit(0);
	}
	char str[88];
	while(fgets(str,80,fp)){
		puts(str);
	}
	fclose(fp);
}


//如果路径cp不存在，就建立一个文件 
int creat_file(char *cp){
	FILE *fp;
	if((fp=(fopen(cp,"r")))==NULL) {
		if((fp=fopen(cp,"w"))==NULL){
			return -1;
		}
	}
	fclose(fp);
	return 1;
}


int write_txt(char *filetxt,int n){
	char *p=filetxt,ch;
	int count=0;
	while(count<3&&p<filetxt+n){
		*p=getchar();
		if(*p++=='\n') count++; 
		else count=0;
	}//写文档 
	return p-filetxt;
}

/****************************************************
void read_txt(void *pt,char *cp){//空指针 文件路径 
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		puts("读取文件失败，程序异常退出\n");
		getchar();
		exit(0);
	} 
	fread(pt,sizeof(*pt),1,fp);
	fclose(fp);
}//失败的函数定义及应用 ，应该错在空指针那里 
****************************************************/
