#include"my.h"
#include"math_test.h" 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
extern struct proinfo *AI; 
void math_exam(int N); 
void math_test(){
	printf("\n	��ѧ����\n");
	printf("\n1.�Ӽ�����\n");
	printf("\n2.���������\n");
	printf("\n0.�˳�\n");

	while(1){
		printf("\n��ѡ�����ģʽ(0->�˳�):"); 
		int cmd;
		scanf("%d",&cmd);
		if(cmd==1){
			math_exam(2);
		}else if(cmd==2){
			math_exam(4);
		}else if(cmd==0) break;
	}
	add_groth_value(1);//�����Կɶ��һ������ 
}

void math_exam(int N){//N������������ 
	const int NUM=3;//�ֲ���̬���� 
	printf("\n%s׼����%d�������⣬������������ʼ��\n",AI->name,NUM); 
	//���������⣬���ǰ��Ĵ������ƣ��Լ��޸� 
	FILE *fp;
	const char *p="+-*/";
	char *cp="�����//��ѧ������.txt";//����һ���ĺ��������ļ� 
	srand(time(NULL)); 
	int i,j,right=0;
	
	struct exam_error *head,*pr,*q;//Ĭ��p�ǵ�ǰָ�룬q�� 
	head=(struct exam_error*)malloc(sizeof(struct exam_error));
	head->next=NULL;//����һ���յ�ͷ��� 
	q=head;	
	
	for(i=1;i<=NUM;i++){
		printf("Case %d:\n",i); 
		int num[4];
		char opt[4];
		fp=fopen(cp,"wt");
		for(j=0;j<3;j++) {
			num[j]=rand()%51;
			opt[j]=p[((unsigned)rand())%N];
			fprintf(fp,"%d %c ",num[j],opt[j]);
		}
		num[3]=rand()%51;
		opt[3]='\n';
		fprintf(fp,"%d \n",num[3]); 
		fclose(fp);//�Ѿ���ȡ������������ 
		show_txt(cp);
		printf("��ش�");
		
		double user_ans=0.0,std_ans=0.0;
		scanf("%lf",&user_ans);
		
		freopen(cp,"r",stdin);
		std_ans=compute();//��һ�ֻ�ȡstd_ans�ķ��� 
		freopen("CON", "r", stdin); //���½����붨�򵽿���̨ ��CON��DOS��windows����ϵͳ���ļ����� 
		//freopen("/dev/tty","r",stdin);//������������ϵͳ�����ô˾�����Ͼ� 
		
		char *cp2="�����//��.txt";
		if((fp=fopen(cp2,"r"))==NULL){
			printf("���ļ�ʧ�ܣ�%s�㲻������\n",AI->name);
		}else{
			fscanf(fp,"%lf",&std_ans);
			fclose(fp);
		}
		
		//���ֻ�ȡstd_ans�ķ���������֪Ϊ�ε�һ�ַ������� 
		//printf("fabs(std_ans-user_ans)=%lf\n",fabs(std_ans-user_ans));
		//if(fabs(std_ans-user_ans)<0.01) {//��ȷ��С�������λ ,�ж�������������˾Ͳ�׼ȷ��1.#QNAN0
		
		/*************************************************************************\
		**if(std_ans-user_ans<0.01&&std_ans-user_ans>-0.01) {
		**	right++;
		**	printf("Great,�������\n\n");
		**}
		**else printf("�������ϸ�ĵ㣬%s�Ĵ𰸣�%.2lf\n",AI->name,std_ans);
		**��ǰ��������ƣ����Ƕ��ڽ���Ĵ���ͬ
		\*************************************************************************/ 

		if(std_ans-user_ans<0.01&&std_ans-user_ans>-0.01) {
			right++;
		}else{
			pr=(struct exam_error*)malloc(sizeof(struct exam_error)) ;
			int i;
			for(i=0;i<4;i++){
				pr->a[i]=num[i];
				pr->b[i]=opt[i];
			}
			pr->count=0;
			pr->std_res=std_ans;
			pr->user_res=user_ans;
			q->next=pr;
			q=pr;
			q->next=NULL; //��� 
		}
		
	}
	//�Ѵ���д���ļ� 
	char *cp3="���Ȿ//��ѧ����.txt";
	if((fp=fopen(cp3,"at+"))==NULL){
		printf("\n�ļ�����,��ǿ���˳�\n");
		return; 
	}
	struct exam_error *sp=head;
	while(sp->next){
		sp=sp->next;
		fwrite(sp,sizeof(struct exam_error),1,fp);
	}
	fclose(fp); 
	//��Ҫ�鿴���⣬��ר�ŵĺ��� 
	printf("\n��ȷ�ʣ�%.2lf%%\n",(double)right/NUM*100);//NUMΪ���� 
}


