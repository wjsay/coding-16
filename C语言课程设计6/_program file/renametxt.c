/*#include"my.h"
#include"file_link_node.h" 
extern struct proinfo *AI;
void deletetxt(){
	printf("	重命名文件\n");
	char contents[100]="笔记本//用户 (";
	char str[13];
	itoa(AI->ID,str,10); 
	strcat(strcat(contents,str),")//目录.txt");//笔记本//用户 (AI->ID)//目录.txt 
	printf("\n所有文件:\n");
	show_txt(contents);//复制的查看文件的代码 
	
	FILE *fp;
	while(1){
		char filepath[100]="笔记本//用户 (",*cp=filepath;//笔记本//用户 ( 
		strcat(strcat(cp,str),")//");//笔记本//用户 (AI->ID)// 
		char newname[100],contents[100];
		strcpy(contents,cp);
		strcat(newname,"已重命名");//笔记本//用户 (AI->ID)//已删除 
		printf("请输入要重命名的文件名(0->结束)：");
		char filename[50];
		fflush(stdin);
		gets(filename);
		if(strlen(filename)==1&&filename[0]=='0') {
			printf("已退出\n"); 
			break; 
		}
		strcat(contents,"目录.txt");
		FILE *fp;
		if((fp=fopen(contents,"rt"))==NULL){
			printf("没有该文件，重命名失败\n");
			continue; 
		}
		
		//================================
		//小心，下面是链表//类似于删除文件 
		//================================
		struct LNode *head,*p,*q;
		head=(struct LNode *)malloc(sizeof(struct LNode));
		head->next=NULL;
		q=head; 
		//p为指向当前节点的指针，q为指向最后一个节点的指针 
		char cap[100];
		while(~fscanf(fp,"%s",cap)){
			printf("读文件：\ncap:%s\nfilename:%s\n",cap,filename);//只在调试时用 
			if(strcmp(cap,filename)){//不相等就直接保存 
				p=(struct LNode*)malloc(sizeof(struct LNode));//刚开始忘记加* 
				strcpy(p->filename,cap);
				q->next=p; 
				q=p;
			} 
			else{
				p=(struct LNode*)malloc(sizeof(struct LNode));//刚开始忘记加* 
				strcpy(p->filename,newname);
				q->next=p; 
				q=p;				
			} 
		}
		q->next=NULL;
		fclose(fp);
		strcat(strcat(cp,filename),".txt");
		strcat(newname,filename);
		rename(cp,newname);//重命名，表面上删除了(新名字没加拓展名) 
		//重命名没有删除原文件，dos命令就会删除？？？
		remove(cp); 
		fp=fopen(contents,"wt");
		p=head->next;
		while(p){
			fprintf(fp,"%s\n\r",p->filename);
			printf("链表 %s\n",p->filename);//调试专用 
			p=p->next;
		}//没有释放节点，该链表不属于全局变量，函数结束户，链表占得内存应该会被释放 
		fclose(fp);//忘记关闭文件,调试中没写入，函数结束后写入了 
		printf("已删除文件：%s\n",filename); 
	} 
} *///重命名不写了 
