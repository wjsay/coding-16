#include"math_test.h"
#include<stdlib.h>
#include"my.h"
extern struct proinfo *AI;
void my_error(){
	char *cp="���Ȿ//��ѧ����.txt";//����ȫ������һ���ļ����ˣ��ҹ����Ǹ��ļ���ܴ�
	//һ�����Ѵ��ⶼ���������У�����������ռ�ڴ棬�� 
	struct exam_error *head,*p,*q;
	head=(struct exam_error*)malloc(sizeof(struct exam_error));
	if(head==NULL){
		printf("\n����ռ�ʧ�ܣ��쳣�˳�\n");
		exit(0); 
	}
	head->next=NULL;
	q=head;//��ʼ����İ�q��ֵΪhead->next;���汨��ʹ����Ұָ�� 
	
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("\n���Ȿ����,���˳�\n");
		return;
	}
	
	//�Ѵ����������
	p=(struct exam_error*)malloc(sizeof(struct exam_error));
	while(fread(p,sizeof(struct exam_error),1,fp)){
		q->next=p;
		q=p;
		p=(struct exam_error*)malloc(sizeof(struct exam_error));
		if(p==NULL){
			printf("\n����ռ�ʧ�ܣ��쳣�˳�\n");
			exit(0); 
		}
	} 
	fclose(fp);
	q->next=NULL;	
	
	int C=0,i=0;//���������һѯ���Ƿ���� ,i�Ǵ����� 
	p=head;
	while(p->next){
		p=p->next;
		printf("\n\n����%d\n",++i);
		int j;
		for(j=0;j<4;j++){
			printf("%.0lf %c ",p->a[j],p->b[j]);
		}
		printf("\n%sԭ���Ĵ𰸣�%.2lf\n",AI->me,p->user_res);
		printf("\n�������µĴ𰸣�");
		double user_ans;
		scanf("%lf",&user_ans);
		if(user_ans-p->std_res<0.01&&user_ans-p->std_res>-0.01){
			p->count++;
			printf("\n��ϲ�㣬����\n"); 
		}else {
			p->count=0; 
			printf("\n���ź����ٽ�����\n");
			printf("\n%s�Ĵ��ǣ�%.2lf\n",AI->name,p->std_res);
		}
		C++;//����Ǵ�˵�е� C++ 
		
		if(C>=5){
			printf("\n�Ƿ�����Ĵ���([����]1->������0->�˳�):");
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
	}//��û��ȫ���յĴ����ٴ�д����Ȿ 
	fclose(fp);
	printf("\n���˳����Ȿ\n");
}
