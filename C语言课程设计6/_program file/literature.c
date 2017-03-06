#include"my.h"
#include"literature.h"
#include<string.h> 
#include<stdlib.h>

void guess(char *);
extern struct proinfo *AI;
void literature(){
	char *cp[3]={"文学//猜字谜.txt","文学//歇后语.txt","文学//成语故事.txt"};
	printf("\n        文学\n");
	printf("\n1.猜字谜\n");
	printf("\n2.歇后语\n");
	printf("\n3.成语故事\n");
	printf("\n4.题目入口\n");//函数写成了有参的，复用率高了，但是代码函数少了，我的一万行55555 
	printf("\n0.退出\n");
	add_groth_value(1);
	while(1){
		printf("\n文学|请选择(0->退出)：");
		unsigned cmd;
		cmd=singal_unsigned_in();
		if(cmd==0) break;
		if(cmd<4) guess(cp[cmd-1]);
		else if(cmd==4){
			literature_administrator(); 
		}else {
			printf("\n输入不合法\n");
		} 
		/*switch(cmd){
			case 1:
				guess(cp[1]);
				break;
			case 2:
				guess(cp[2]);
				break;
			case 3:
				//idiom(cp[3]);
				break;
			case 4:
				literature_administrator(); 
				break;
			default:
				printf("\n输入不合法\n"); 
		} */
	} 
}

void guess(char *cp){
	printf("\n      %s正在阅读%s\n",AI->me,cp+6);
	
	
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
	
	q=head;
	while(q->next){
		q=q->next;
		printf("\n\n\n%s:%s\n",AI->name,q->fname);
		char ans[100];
		for(;;){
			printf("\n(0->退出，1->下一个,2->查看答案)答案是？：");
			scanf("%s",ans);
			if(strlen(ans)==1){
				if(*ans=='0') return;
				if(*ans=='1') break;
				if(*ans=='2'){
					printf("%s:%s\n",AI->name,q->fans);
					continue;
				}
			}
			if(strcmp(ans,q->fans)==0){
				printf("\n★★★Great,答对了！★★★\n");
				break; 
			}else{
				printf("\n差一点，再想想\n"); 
			}
		}
	} 
	printf("\n%s:呀，没了\n\n\n",AI->name);
}


