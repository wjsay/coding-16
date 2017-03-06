#include"my.h"
#include<time.h>
#include<math.h>
extern struct proinfo *AI;

void arithmetic(int N); 
void mathematic(){
	printf("	数学王国\n");
	//int N=4;
	//printf("几位数的四则运算，由%s的输入决定：",AI->me);
	//scanf("%d",&N); N%=100;//N太大没啥意思
	
	//该函数主要为小学生玩，可以作为家庭作业，或者练习用 
	printf("\n1.加减运算\n");
	printf("\n2.四则运算\n");
	printf("\n3.算术测试\n");
	printf("\n4.错题集\n"); 
	printf("\n0.退出\n"); 
	while(1){
		printf("\n请选择运算难度或错题本(0->退出)："); 
		int cmd;
		//scanf("%d",&cmd);
		cmd=singal_unsigned_in();
		if(cmd==1){
			arithmetic(2);
		}else if(cmd==2){
			arithmetic(4);
		}else if(cmd==3){
			math_test();
		} else if(cmd==4){
			my_error();
		}else if(!cmd) break;
	}
	add_groth_value(1);
	printf("\n已离开数学王国\n");
}

void arithmetic(int N){
	FILE *fp;
	const char *p="+-*/";
	char *cp="随机数//数学计算题.txt";
	srand(time(NULL));
	printf("\n将有7道加减题，%s, Go!\n",AI->me);
	int i,j,right=0;
	for(i=1;i<=7;i++){
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
		fprintf(fp,"%d \n",num[3]); 
		fclose(fp);//获取随机试题 
		show_txt(cp);
		printf("请回答：");
		
		double user_ans=0.0,std_ans=0.0;
		scanf("%lf",&user_ans);
		
		freopen(cp,"r",stdin);
		std_ans=compute();//第一种获取std_ans的方法 
		freopen("CON", "r", stdin); //重新将输入定向到控制台 （CON是DOS和windows操作系统的文件名） 
		//freopen("/dev/tty","r",stdin);//若是其他操作系统，可用此句替代上句 
		
		char *ccp="随机数//答案.txt";
		if((fp=fopen(ccp,"r"))==NULL){
			printf("打开文件失败，%s算不出来了\n",AI->name);
		}else{
			fscanf(fp,"%lf",&std_ans);
			fclose(fp);
		}
		
		//两种获取std_ans的方法，但不知为何第一种方法错了 
		//printf("fabs(std_ans-user_ans)=%lf\n",fabs(std_ans-user_ans));
		//if(fabs(std_ans-user_ans)<0.01) {//精确到小数点后两位 ,有毒，计算次数多了就不准确了1.#QNAN0
		if(std_ans-user_ans<0.01&&std_ans-user_ans>-0.01) {
			right++;
			printf("Great,你真棒！\n\n");
		}
		else printf("你可以再细心点，%s的答案：%.2lf\n",AI->name,std_ans);
	}
	if(right<=0) printf("\n你确实需要努力了\n");
	else if(right<=2) printf("%s 获得了 ★\n",AI->me);
	else if(right<=5) printf("%s 获得了 ★★\n",AI->me);
	else printf("%s 获得了 ★★★\n",AI->me);
}

 
