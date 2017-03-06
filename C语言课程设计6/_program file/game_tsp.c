#include<string.h>
#include<time.h>
#include"my.h"
extern struct proinfo *AI;
//旅行商游戏
void tsp(){
	//数组p是为停一下的规则开的 
	//最多限制10个玩家 
	int n,score[10],p[10],rule[101],count=0,begin,end,time1,turn,i;
	//int a[maxn];
	//while(~scanf("%d",a+count)&&a[count]) count++;//count为掷骰子得到的数
	printf("\n	%s历险记\n",AI->name);
	printf("\n玩法：按两次任意键掷一次骰子\n") ;
	srand(time(NULL));
	while(1){
		printf("\n请输入玩家人数(1-9)(0->退出)：");
		//scanf("%d",&n);
		n=singal_unsigned_in();
		if(n<=0||n>=10) break;
		memset(rule,0,sizeof(rule));
		memset(p,0,sizeof(p));
		
		//游戏规则从文件中读取
		FILE *fp;
		char *cp="游戏//TSP//历险记游戏规则.txt"; 
		if((fp=fopen(cp,"rt"))==NULL){
			printf("\n无法读取到游戏规则\n");
			break;
		}
		while(fscanf(fp,"%d%d",&begin,&end)&&(begin||end)){ 
			rule[begin]=end;//从begin跳到end 
		}
		
		while(fscanf(fp,"%d",&time1)&&time1){//time1为机会变化的位置 
			if(time1<0) rule[-time1]=-1;//time1那个位置停一次 
			else if(time1>0) rule[time1]=1;//增加一次机会 
		}
		fclose(fp);
		//游戏已设置完成，可以掷骰子了 
		turn=1;//玩家编号 
		memset(score,0,sizeof(score));
		
		int cur_x,cur_y;
		get_point(&cur_x,&cur_y);
		int x0=cur_x+2,y0=0;
		int x[12],y[11]={0},i;
		for(i=0;i<12;i++) x[i]=x0+i*2;//每个选手分配两行 
		//for(i=0;i<count;i++){//0到count  随机数 
		while(1){
			move_point_to(x[0],5);
			printf("当前掷骰子者：%d号",turn); 
			move_point_to(x[turn],0);
			printf("%d号 掷的骰子数：",turn);
			//fflush(stdin);
			//char str[10];
			//gets(str);//就是让玩家按一下键盘确认
			press_key();//因为使用上面注释的，会移动光标，不好控制 
			int num=rand()%6+1;
			printf("%d ",num); 
			if(p[turn]==-1){
				p[turn]=0;
				turn=turn%n+1;
				continue;//有点bug,停掷一轮时，还会让其掷骰子，但是不会加，还可以进行 
			}//n个玩家 
			if(score[turn]+num<=100)
				score[turn]+=num;//sorce 达到100就赢了 
			printf("当前位置：%d                             ",score[turn]);
			if(score[turn]==100) break;
			if(rule[score[turn]]){
				move_point_to(x[turn],36);
				if(rule[score[turn]]==1){
					printf("再掷一次      ");
					continue;
				} 
				if(rule[score[turn]]==-1) {
					printf("Er..停掷一轮"); 
					p[turn]=-1;
					turn=turn%n+1;
					continue;
				}
				
				score[turn]=rule[score[turn]];
			}
			turn=turn%n+1;
		}
		move_point_to(x[n]+4,0); 
		printf("\n★★★玩家%d赢了★★★\n",turn); 
	} 
	printf("\n已退出历险记游戏\n");
}	


/*#include<string.h>
#include<time.h>
#include"my.h"
extern struct proinfo *AI;
//旅行商游戏
void tsp(){
	//数组p是为停一下的规则开的 
	//最多限制10个玩家 
	int n,score[10],p[10],rule[101],count=0,begin,end,time1,turn,i;
	//int a[maxn];
	//while(~scanf("%d",a+count)&&a[count]) count++;//count为掷骰子得到的数
	printf("\n	%s历险记\n",AI->name);
	printf("\n玩法：按回车（确认）键掷骰子\n") ;
	srand(time(NULL));
	while(1){
		printf("\n请输入玩家人数(1-9)(0->退出)：");
		//scanf("%d",&n);
		n=singal_unsigned_in();
		if(n<=0||n>=10) break;
		memset(rule,0,sizeof(rule));
		memset(p,0,sizeof(p));
		
		//游戏规则从文件中读取
		FILE *fp;
		char *cp="游戏//TSP//历险记游戏规则.txt"; 
		if((fp=fopen(cp,"rt"))==NULL){
			printf("\n无法读取到游戏规则\n");
			break;
		}
		while(fscanf(fp,"%d%d",&begin,&end)&&(begin||end)){ 
			rule[begin]=end;//从begin跳到end 
		}
		
		while(fscanf(fp,"%d",&time1)&&time1){//time1为机会变化的位置 
			if(time1<0) rule[-time1]=-1;//time1那个位置停一次 
			else if(time1>0) rule[time1]=1;//增加一次机会 
		}
		fclose(fp);
		//游戏已设置完成，可以掷骰子了 
		turn=1;//玩家编号 
		memset(score,0,sizeof(score));
		

		//for(i=0;i<count;i++){//0到count  随机数 
		while(1){
			printf("%d号，掷骰子-> ",turn);
			fflush(stdin);
			char str[10];
			gets(str);//就是让玩家按一下键盘确认
			int num=rand()%6+1;
			printf("get_number(骰子数) = %d\n",num); 
			if(p[turn]==-1){
				p[turn]=0;
				turn=turn%n+1;
			}//n个玩家 
			if(score[turn]+num<=100)
				score[turn]+=num;//sorce 达到100就赢了 
			printf("num.%d is now at(位置)：%d\n\n",turn,score[turn]);
			if(score[turn]==100) break;
			if(rule[score[turn]]){
				if(rule[score[turn]]==1){
					printf("%d号获得再掷一次的机会\n",turn);
					continue;
				} 
				if(rule[score[turn]]==-1) {
					printf("Er..额。。%d号停掷一轮\n\n",turn); 
					p[turn]=-1;
					turn=turn%n+1;
					continue;
				}
				score[turn]=rule[score[turn]];
			}
			turn=turn%n+1;
		}
		printf("\n★★★玩家%d赢了★★★\n",turn); 
	} 
	printf("\n已退出历险记游戏\n");
}	
*/
