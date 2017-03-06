#include<stdio.h>
#include<string.h>
#include"literature.h" 
#include<stdlib.h>
#include"my.h"
#include<string.h>

extern struct proinfo *AI;

void modify_info(char *cp);
void l_admin(char *cp);
void query_info(char *cp);
void literature_administrator(){
	char key[100];
	/*do{
		printf("\n请输入管理密码：");
		scanf("%s",key);
		if(strlen(key)==1&&*key=='0')
			return;
	}while(strcmp(key,AI->me));*/
	char *cp[3]={"文学//猜字谜.txt","文学//歇后语.txt","文学//成语故事.txt"};
	int i=0;
	for(i=0;i<3;i++)
		creat_file(cp[i]);//懒得手动建立，还保险
	printf("\n********出题改题********\n"); 
	int cmd;
	while(1){
		printf("\n1.改动猜字谜\n");
		printf("\n2.改动歇后语\n");
		printf("\n3.改动成语故事\n");
		printf("\n0.退出\n");		
		printf("\n请选择(0->退出)：");
		cmd=singal_unsigned_in();
		if(!cmd) return;
		if(cmd>3) continue;
		l_admin(cp[cmd-1]);
	} 
}

void add_info(char *cp);
void mydelete_info(char *);
void modify_info(char *);
void query_info(char *);

void l_admin(char *cp){
	printf("\n        增删改查%s\n",&cp[6]);
	printf("\n1.增加信息\n");
	printf("\n2.删除信息\n");
	printf("\n3.修改信息\n");
	printf("\n4.查询信息\n");
	printf("\n0.退出\n");
	while(1){
		printf("\n增删改查|请选择(0->退出)：");
		unsigned cmd;
		cmd=singal_unsigned_in();
		if(!cmd) return;
		switch(cmd){
			case 1:
				add_info(cp);
				break;
			case 2:
				mydelete_info(cp);
				break;
			case 3:
				modify_info(cp);
				break;
			case 4:
				query_info(cp);
				break;	 
		} 
	}
}
void mydelete_info(char *cp){//从文件cp中删除的界面 
	printf("\n您正在操作的文件是：%s\n",&cp[6]);
//先读入数据 
	struct l_link *head,*p,*q;
	head=(struct l_link *)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("\n读取文件失败\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));//开始这里忘了申请空间 
		if(p==NULL){
			printf("\n申请空间失败\n");
			return; 
		}		
		
	}//读信息 
	q->next=NULL;
	fclose(fp);
//再显示信息
	p=head;
	while(p->next){
		p=p->next; //重写了代码，这里又忘了写 
		printf("\n题目：%s\n答案:%s\n\n",p->fname,p->fans);
	}
	for(;;){
		int flag=0;
		printf("\n输入要删除的题目或者答案(0->退出)：");
		char buffer[100];
		scanf("%s",buffer);
		if(strlen(buffer)==1&&*buffer=='0'){
			break;//mdzz//刚开始这里写成了return，跳过了最后一步"wt" 
		}
		q=head;
		//下面是删除某一节点 
		while(q->next){
			struct l_link *t=q;
			q=q->next;
			if(strcmp(q->fname,buffer)==0||strcmp(q->fans,buffer)==0){//q就是要删除的节点地址 
				t->next=q->next;
				//不是全局变量 
				flag=1;
				free(q); 
				break;
			}
		}
		if (flag) printf("\n删除成功\n");
		else printf("\n查找不到，删除失败\n"); 
	}
	p=head;
	if((fp=fopen(cp,"w"))==NULL){
		printf("\n写入失败\n");
		return; 
	}
	while(p->next){
		p=p->next;
		fwrite(p,sizeof(struct l_link),1,fp);
		//pritnf("调试专用\n题目：%s\n答案:%s",p->fname,p->fans);
	} 
	fclose(fp);
	printf("\n写入完成\n"); 
}

//添加信息 
void add_info(char *cp){
	printf("\n要处理的文件是：%s\n",&cp[6]);
	FILE *fp;
	if((fp=fopen(cp,"at+"))==NULL){
		printf("\n打开文件失败\n");
		return ; 
	}
	
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n申请内存失败\n");
		return; 
	}
	head->next=NULL;
	q=head;
	char name[100],ans[100];
	while(1){
		printf("\n请输入新增题目(0->退出):");
		scanf("%s",name);
		if(strlen(name)==1&& *name=='0') break;
		printf("\n请输入答案：");
		scanf("%s",ans);
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n申请内存失败\n");
			break; 
		}
		strcpy(p->fname,name);
		strcpy(p->fans,ans);
		q->next=p;
		q=p;
	}
	q->next=NULL;
	p=head;
	while(p->next){
		p=p->next;
		fwrite(p,sizeof(struct l_link),1,fp);
	}
	fclose(fp);
	printf("\n写入完成\n\n\n");
	 
}


//int l_link_space(struct l_link*p){
//	if(p==NULL){
//		printf("\n申请空间失败\n");
//		return -1; 
//	}
//	return 0;
//}

//从文件cp中，根据buffer删除一条记录
int delete_info(char *cp,char *buffer){//没有用到 
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		printf("\n读取文件失败\n");
		return; 
	} 
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n申请空间失败\n");
			break ; 
		} 
	}//读取文件
	q->next=NULL;
	fclose(fp);
	if((fp=fopen(cp,"w"))==NULL){
		printf("\n写入文件失败\n");
		return ; 
	}
	p=head;
	while(p->next){
		p=p->next;
		if(strcmp(buffer,p->fname)||strcmp(buffer,p->fans)){
			fwrite(p,sizeof(struct l_link),1,fp);
			return 0;//删除成功 
		}	
	}
	return -1;//删除失败 
}

void modify_info(char *cp){
	printf("\n正在修改的文件：%s\n\n",cp+6);
//读入信息
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		printf("\n读取文件失败\n");
		return; 
	} 
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n申请空间失败\n");
			break ; 
		} 
	}//读取文件
	q->next=NULL;
	fclose(fp);//读入信息都是套路，没有写成函数，因为不想定义全局变量 
//再显示信息
	p=head;
	while(p->next){
		p=p->next; //重写了代码，这里又忘了写 
		printf("\n题目：%s\n答案:%s\n\n",p->fname,p->fans);
	} 
//输入要修改的 a to b
	char buffer[100], buffer2[100];
	while(1){
		printf("\n输入要修改的题目或答案(0->退出)：") ;
		scanf("%s",buffer);
		if(strlen(buffer)==1&&*buffer=='0'){
			break;
		}
		printf("\n要改成？：");
		scanf("%s",buffer2);
		
		if((fp=fopen(cp,"w"))==NULL){
			printf("\n写入文件失败\n");
			return; 
		}
		p=head;
		while(p->next){
			p=p->next;
			if(strcmp(p->fans,buffer)==0) strcpy(p->fans,buffer2);
			if(strcmp(p->fname,buffer)==0) strcpy(p->fname,buffer2);
			fwrite(p,sizeof(struct l_link),1,fp);
		}
		fclose(fp);
		printf("\n写入文件完成\n");
	} 
}

void query_info(char *cp){
	printf("\n正在查询的文件：%s\n\n",cp+6);
//读入信息
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		printf("\n读取文件失败\n");
		return; 
	} 
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n申请空间失败\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n申请空间失败\n");
			break ; 
		} 
	}//读取文件
	q->next=NULL;
	//读入信息都是套路，没有写成函数，因为不想定义全局变量 
//再显示信息
	p=head;
	while(p->next){
		p=p->next; //重写了代码，这里又忘了写 
		printf("\n题目：%s\n答案:%s\n\n",p->fname,p->fans);
	} 
//输入要修改的 a to b
	char buffer[100];
	int flag; 
	while(1){
		flag=0;
		printf("\n\n输入要查询的题目或答案(0->退出)：") ;
		scanf("%s",buffer);
		if(strlen(buffer)==1&&*buffer=='0'){
			break;
		}
		p=head;
		while(p->next){
			p=p->next;
			if(strcmp(buffer,p->fname)==0||strcmp(buffer,p->fans)==0){
				printf("\n查询结果：\n");
				printf("题目：%s\n",p->fname);
				printf("答案：%s\n",p->fans);
				flag=1;
				break;
			}
		}
		if(!flag) {
			printf("\n没有查找到\n"); 
		}
	}
	fclose(fp);
}
