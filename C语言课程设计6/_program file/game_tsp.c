#include<string.h>
#include<time.h>
#include"my.h"
extern struct proinfo *AI;
//��������Ϸ
void tsp(){
	//����p��Ϊͣһ�µĹ��򿪵� 
	//�������10����� 
	int n,score[10],p[10],rule[101],count=0,begin,end,time1,turn,i;
	//int a[maxn];
	//while(~scanf("%d",a+count)&&a[count]) count++;//countΪ�����ӵõ�����
	printf("\n	%s���ռ�\n",AI->name);
	printf("\n�淨���������������һ������\n") ;
	srand(time(NULL));
	while(1){
		printf("\n�������������(1-9)(0->�˳�)��");
		//scanf("%d",&n);
		n=singal_unsigned_in();
		if(n<=0||n>=10) break;
		memset(rule,0,sizeof(rule));
		memset(p,0,sizeof(p));
		
		//��Ϸ������ļ��ж�ȡ
		FILE *fp;
		char *cp="��Ϸ//TSP//���ռ���Ϸ����.txt"; 
		if((fp=fopen(cp,"rt"))==NULL){
			printf("\n�޷���ȡ����Ϸ����\n");
			break;
		}
		while(fscanf(fp,"%d%d",&begin,&end)&&(begin||end)){ 
			rule[begin]=end;//��begin����end 
		}
		
		while(fscanf(fp,"%d",&time1)&&time1){//time1Ϊ����仯��λ�� 
			if(time1<0) rule[-time1]=-1;//time1�Ǹ�λ��ͣһ�� 
			else if(time1>0) rule[time1]=1;//����һ�λ��� 
		}
		fclose(fp);
		//��Ϸ��������ɣ������������� 
		turn=1;//��ұ�� 
		memset(score,0,sizeof(score));
		
		int cur_x,cur_y;
		get_point(&cur_x,&cur_y);
		int x0=cur_x+2,y0=0;
		int x[12],y[11]={0},i;
		for(i=0;i<12;i++) x[i]=x0+i*2;//ÿ��ѡ�ַ������� 
		//for(i=0;i<count;i++){//0��count  ����� 
		while(1){
			move_point_to(x[0],5);
			printf("��ǰ�������ߣ�%d��",turn); 
			move_point_to(x[turn],0);
			printf("%d�� ������������",turn);
			//fflush(stdin);
			//char str[10];
			//gets(str);//��������Ұ�һ�¼���ȷ��
			press_key();//��Ϊʹ������ע�͵ģ����ƶ���꣬���ÿ��� 
			int num=rand()%6+1;
			printf("%d ",num); 
			if(p[turn]==-1){
				p[turn]=0;
				turn=turn%n+1;
				continue;//�е�bug,ͣ��һ��ʱ���������������ӣ����ǲ���ӣ������Խ��� 
			}//n����� 
			if(score[turn]+num<=100)
				score[turn]+=num;//sorce �ﵽ100��Ӯ�� 
			printf("��ǰλ�ã�%d                             ",score[turn]);
			if(score[turn]==100) break;
			if(rule[score[turn]]){
				move_point_to(x[turn],36);
				if(rule[score[turn]]==1){
					printf("����һ��      ");
					continue;
				} 
				if(rule[score[turn]]==-1) {
					printf("Er..ͣ��һ��"); 
					p[turn]=-1;
					turn=turn%n+1;
					continue;
				}
				
				score[turn]=rule[score[turn]];
			}
			turn=turn%n+1;
		}
		move_point_to(x[n]+4,0); 
		printf("\n�������%dӮ�ˡ���\n",turn); 
	} 
	printf("\n���˳����ռ���Ϸ\n");
}	


/*#include<string.h>
#include<time.h>
#include"my.h"
extern struct proinfo *AI;
//��������Ϸ
void tsp(){
	//����p��Ϊͣһ�µĹ��򿪵� 
	//�������10����� 
	int n,score[10],p[10],rule[101],count=0,begin,end,time1,turn,i;
	//int a[maxn];
	//while(~scanf("%d",a+count)&&a[count]) count++;//countΪ�����ӵõ�����
	printf("\n	%s���ռ�\n",AI->name);
	printf("\n�淨�����س���ȷ�ϣ���������\n") ;
	srand(time(NULL));
	while(1){
		printf("\n�������������(1-9)(0->�˳�)��");
		//scanf("%d",&n);
		n=singal_unsigned_in();
		if(n<=0||n>=10) break;
		memset(rule,0,sizeof(rule));
		memset(p,0,sizeof(p));
		
		//��Ϸ������ļ��ж�ȡ
		FILE *fp;
		char *cp="��Ϸ//TSP//���ռ���Ϸ����.txt"; 
		if((fp=fopen(cp,"rt"))==NULL){
			printf("\n�޷���ȡ����Ϸ����\n");
			break;
		}
		while(fscanf(fp,"%d%d",&begin,&end)&&(begin||end)){ 
			rule[begin]=end;//��begin����end 
		}
		
		while(fscanf(fp,"%d",&time1)&&time1){//time1Ϊ����仯��λ�� 
			if(time1<0) rule[-time1]=-1;//time1�Ǹ�λ��ͣһ�� 
			else if(time1>0) rule[time1]=1;//����һ�λ��� 
		}
		fclose(fp);
		//��Ϸ��������ɣ������������� 
		turn=1;//��ұ�� 
		memset(score,0,sizeof(score));
		

		//for(i=0;i<count;i++){//0��count  ����� 
		while(1){
			printf("%d�ţ�������-> ",turn);
			fflush(stdin);
			char str[10];
			gets(str);//��������Ұ�һ�¼���ȷ��
			int num=rand()%6+1;
			printf("get_number(������) = %d\n",num); 
			if(p[turn]==-1){
				p[turn]=0;
				turn=turn%n+1;
			}//n����� 
			if(score[turn]+num<=100)
				score[turn]+=num;//sorce �ﵽ100��Ӯ�� 
			printf("num.%d is now at(λ��)��%d\n\n",turn,score[turn]);
			if(score[turn]==100) break;
			if(rule[score[turn]]){
				if(rule[score[turn]]==1){
					printf("%d�Ż������һ�εĻ���\n",turn);
					continue;
				} 
				if(rule[score[turn]]==-1) {
					printf("Er..���%d��ͣ��һ��\n\n",turn); 
					p[turn]=-1;
					turn=turn%n+1;
					continue;
				}
				score[turn]=rule[score[turn]];
			}
			turn=turn%n+1;
		}
		printf("\n�������%dӮ�ˡ���\n",turn); 
	} 
	printf("\n���˳����ռ���Ϸ\n");
}	
*/
