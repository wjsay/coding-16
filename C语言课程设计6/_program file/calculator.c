#include<stdio.h>
#include"my.h"
#include<string.h>
extern struct proinfo *AI;
double cal(double num1,char opt, double num2){
	switch(opt){
		case '+': return num1+num2;
		case '-': return num1-num2;
		case '*': return num1*num2;
		case '/': return num1/num2;
	}
}

//如果改为有括号的，遇到左括号进入一个新的活动，遇到右括号，返回值 
double compute(){//该函数功能若是写成非边输入边处理的会好很多 
	const char *cp="+-*/\n";
	double num[3];
	char opt[2];//本来想模拟栈，写着写着发现不用 
	scanf("%lf",&num[0]);
	while(!strchr(cp,opt[0]=getchar()));/*这里会把\n读进去 */if(opt[0]=='\n') return num[0]; 
	scanf("%lf",&num[1]);//预先输入 num1 opt num2 
	while(1){
		while(!strchr(cp,opt[1]=getchar()));//有点乱
		if(opt[1]=='\n') break;
		scanf("%lf",&num[2]);
		if((opt[0]=='+'||opt[0]=='-')&&(opt[1]=='*'||opt[1]=='/')){//← 
			num[1]=cal(num[1],opt[1],num[2]);	
		} else{//→ 
			num[0]=cal(num[0],opt[0],num[1]);
			opt[0]=opt[1];
			num[1]=num[2];
		}
	} 
	//return cal(num[0],opt[0],num[1]);
	double ans=cal(num[0],opt[0],num[1]);
	FILE *fp;
	char *ccp="随机数//答案.txt";
	fp=fopen(ccp,"w");
	fprintf(fp,"%lf\n",ans);
	fclose(fp); 
	return ans;
} 

void calculator(){
	printf("%s:我会不带括号的四则运算\n\n",AI->name);
	printf("请输入:");
	printf("结果：%.2lf\n",compute());
}
