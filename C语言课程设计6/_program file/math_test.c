#include"my.h"
#include"math_test.h" 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
extern struct proinfo *AI; 
void math_exam(int N); 
void math_test(){
	printf("\n	数学测试\n");
	printf("\n1.加减测试\n");
	printf("\n2.四则运算测\n");
	printf("\n0.退出\n");

	while(1){
		printf("\n请选择测评模式(0->退出):"); 
		int cmd;
		scanf("%d",&cmd);
		if(cmd==1){
			math_exam(2);
		}else if(cmd==2){
			math_exam(4);
		}else if(cmd==0) break;
	}
	add_groth_value(1);//做测试可多得一倍奖励 
}

void math_exam(int N){//N决定几种运算 
	const int NUM=3;//局部静态变量 
	printf("\n%s准备了%d道计算题，静下心来，开始：\n",AI->name,NUM); 
	//先生成试题，这和前面的代码类似，稍加修改 
	FILE *fp;
	const char *p="+-*/";
	char *cp="随机数//数学计算题.txt";//与上一级的函数公用文件 
	srand(time(NULL)); 
	int i,j,right=0;
	
	struct exam_error *head,*pr,*q;//默认p是当前指针，q是 
	head=(struct exam_error*)malloc(sizeof(struct exam_error));
	head->next=NULL;//建立一个空的头结点 
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
		fclose(fp);//已经获取随机试题的数据 
		show_txt(cp);
		printf("请回答：");
		
		double user_ans=0.0,std_ans=0.0;
		scanf("%lf",&user_ans);
		
		freopen(cp,"r",stdin);
		std_ans=compute();//第一种获取std_ans的方法 
		freopen("CON", "r", stdin); //重新将输入定向到控制台 （CON是DOS和windows操作系统的文件名） 
		//freopen("/dev/tty","r",stdin);//若是其他操作系统，可用此句替代上句 
		
		char *cp2="随机数//答案.txt";
		if((fp=fopen(cp2,"r"))==NULL){
			printf("打开文件失败，%s算不出来了\n",AI->name);
		}else{
			fscanf(fp,"%lf",&std_ans);
			fclose(fp);
		}
		
		//两种获取std_ans的方法，但不知为何第一种方法错了 
		//printf("fabs(std_ans-user_ans)=%lf\n",fabs(std_ans-user_ans));
		//if(fabs(std_ans-user_ans)<0.01) {//精确到小数点后两位 ,有毒，计算次数多了就不准确了1.#QNAN0
		
		/*************************************************************************\
		**if(std_ans-user_ans<0.01&&std_ans-user_ans>-0.01) {
		**	right++;
		**	printf("Great,你真棒！\n\n");
		**}
		**else printf("你可以再细心点，%s的答案：%.2lf\n",AI->name,std_ans);
		**和前面代码类似，就是对于结果的处理不同
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
			q->next=NULL; //打结 
		}
		
	}
	//把错题写入文件 
	char *cp3="错题本//数学测试.txt";
	if((fp=fopen(cp3,"at+"))==NULL){
		printf("\n文件受损,已强制退出\n");
		return; 
	}
	struct exam_error *sp=head;
	while(sp->next){
		sp=sp->next;
		fwrite(sp,sizeof(struct exam_error),1,fp);
	}
	fclose(fp); 
	//若要查看错题，有专门的函数 
	printf("\n正确率：%.2lf%%\n",(double)right/NUM*100);//NUM为题数 
}


