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

//�����Ϊ�����ŵģ����������Ž���һ���µĻ�����������ţ�����ֵ 
double compute(){//�ú�����������д�ɷǱ�����ߴ���Ļ�úܶ� 
	const char *cp="+-*/\n";
	double num[3];
	char opt[2];//������ģ��ջ��д��д�ŷ��ֲ��� 
	scanf("%lf",&num[0]);
	while(!strchr(cp,opt[0]=getchar()));/*������\n����ȥ */if(opt[0]=='\n') return num[0]; 
	scanf("%lf",&num[1]);//Ԥ������ num1 opt num2 
	while(1){
		while(!strchr(cp,opt[1]=getchar()));//�е���
		if(opt[1]=='\n') break;
		scanf("%lf",&num[2]);
		if((opt[0]=='+'||opt[0]=='-')&&(opt[1]=='*'||opt[1]=='/')){//�� 
			num[1]=cal(num[1],opt[1],num[2]);	
		} else{//�� 
			num[0]=cal(num[0],opt[0],num[1]);
			opt[0]=opt[1];
			num[1]=num[2];
		}
	} 
	//return cal(num[0],opt[0],num[1]);
	double ans=cal(num[0],opt[0],num[1]);
	FILE *fp;
	char *ccp="�����//��.txt";
	fp=fopen(ccp,"w");
	fprintf(fp,"%lf\n",ans);
	fclose(fp); 
	return ans;
} 

void calculator(){
	printf("%s:�һ᲻�����ŵ���������\n\n",AI->name);
	printf("������:");
	printf("�����%.2lf\n",compute());
}
