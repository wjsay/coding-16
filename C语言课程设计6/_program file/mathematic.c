#include"my.h"
#include<time.h>
#include<math.h>
extern struct proinfo *AI;

void arithmetic(int N); 
void mathematic(){
	printf("	��ѧ����\n");
	//int N=4;
	//printf("��λ�����������㣬��%s�����������",AI->me);
	//scanf("%d",&N); N%=100;//N̫��ûɶ��˼
	
	//�ú�����ҪΪСѧ���棬������Ϊ��ͥ��ҵ��������ϰ�� 
	printf("\n1.�Ӽ�����\n");
	printf("\n2.��������\n");
	printf("\n3.��������\n");
	printf("\n4.���⼯\n"); 
	printf("\n0.�˳�\n"); 
	while(1){
		printf("\n��ѡ�������ѶȻ���Ȿ(0->�˳�)��"); 
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
	printf("\n���뿪��ѧ����\n");
}

void arithmetic(int N){
	FILE *fp;
	const char *p="+-*/";
	char *cp="�����//��ѧ������.txt";
	srand(time(NULL));
	printf("\n����7���Ӽ��⣬%s, Go!\n",AI->me);
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
		fclose(fp);//��ȡ������� 
		show_txt(cp);
		printf("��ش�");
		
		double user_ans=0.0,std_ans=0.0;
		scanf("%lf",&user_ans);
		
		freopen(cp,"r",stdin);
		std_ans=compute();//��һ�ֻ�ȡstd_ans�ķ��� 
		freopen("CON", "r", stdin); //���½����붨�򵽿���̨ ��CON��DOS��windows����ϵͳ���ļ����� 
		//freopen("/dev/tty","r",stdin);//������������ϵͳ�����ô˾�����Ͼ� 
		
		char *ccp="�����//��.txt";
		if((fp=fopen(ccp,"r"))==NULL){
			printf("���ļ�ʧ�ܣ�%s�㲻������\n",AI->name);
		}else{
			fscanf(fp,"%lf",&std_ans);
			fclose(fp);
		}
		
		//���ֻ�ȡstd_ans�ķ���������֪Ϊ�ε�һ�ַ������� 
		//printf("fabs(std_ans-user_ans)=%lf\n",fabs(std_ans-user_ans));
		//if(fabs(std_ans-user_ans)<0.01) {//��ȷ��С�������λ ,�ж�������������˾Ͳ�׼ȷ��1.#QNAN0
		if(std_ans-user_ans<0.01&&std_ans-user_ans>-0.01) {
			right++;
			printf("Great,�������\n\n");
		}
		else printf("�������ϸ�ĵ㣬%s�Ĵ𰸣�%.2lf\n",AI->name,std_ans);
	}
	if(right<=0) printf("\n��ȷʵ��ҪŬ����\n");
	else if(right<=2) printf("%s ����� ��\n",AI->me);
	else if(right<=5) printf("%s ����� ���\n",AI->me);
	else printf("%s ����� ����\n",AI->me);
}

 
