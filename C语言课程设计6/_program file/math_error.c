#include"math_test.h"
#include<stdlib.h>
#include"my.h"
extern struct proinfo *AI;
void my_error(){
	char *cp="错题本//数学测试.txt";//错题全被放在一个文件里了，我估计那个文件会很大
	//一会儿会把错题都读到链表中，估计链表会很占内存，改 
	struct exam_error *head,*p,*q;
	head=(struct exam_error*)malloc(sizeof(struct exam_error));
	if(head==NULL){
		printf("\n申请空间失败，异常退出\n");
		exit(0); 
	}
	head->next=NULL;
	q=head;//开始错误的把q赋值为head->next;下面报错：使用了野指针 
	
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("\n错题本丢了,已退出\n");
		return;
	}
	
	//把错题读入链表
	p=(struct exam_error*)malloc(sizeof(struct exam_error));
	while(fread(p,sizeof(struct exam_error),1,fp)){
		q->next=p;
		q=p;
		p=(struct exam_error*)malloc(sizeof(struct exam_error));
		if(p==NULL){
			printf("\n申请空间失败，异常退出\n");
			exit(0); 
		}
	} 
	fclose(fp);
	q->next=NULL;	
	
	int C=0,i=0;//改五道错题一询问是否继续 ,i是错题编号 
	p=head;
	while(p->next){
		p=p->next;
		printf("\n\n错题%d\n",++i);
		int j;
		for(j=0;j<4;j++){
			printf("%.0lf %c ",p->a[j],p->b[j]);
		}
		printf("\n%s原来的答案：%.2lf\n",AI->me,p->user_res);
		printf("\n请输入新的答案：");
		double user_ans;
		scanf("%lf",&user_ans);
		if(user_ans-p->std_res<0.01&&user_ans-p->std_res>-0.01){
			p->count++;
			printf("\n恭喜你，对了\n"); 
		}else {
			p->count=0; 
			printf("\n很遗憾，再接再厉\n");
			printf("\n%s的答案是：%.2lf\n",AI->name,p->std_res);
		}
		C++;//这就是传说中的 C++ 
		
		if(C>=5){
			printf("\n是否继续改错题([非零]1->继续，0->退出):");
			int cmd;
			scanf("%d",&cmd);
			if(cmd==0) break;
			else C=0; 
		} 
	}
	
	struct exam_error *sp=head;
	fp=fopen(cp,"wt");
	while(sp->next){
		sp=sp->next;
		if(sp->count<3)
			fwrite(sp,sizeof(struct exam_error),1,fp);
	}//把没完全掌握的错题再次写入错题本 
	fclose(fp);
	printf("\n已退出错题本\n");
}
