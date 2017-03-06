#include<stdio.h>
#include"my.h"
#define maxn 1000000//6个0
char str[maxn];
extern struct proinfo *AI;
void find_ch(){
	printf("	寻找字符串中的汉字，至今还没有谁\n\n能逃脱%s锐利",AI->name);
	printf("的双眼，%s输入一串字符，我\n\n能秒出多少个汉字：\n\n",AI->me);
	while(gets(str)){
		char *p=str;
		int count=0;
		while(*p) 
			if(*p++<0) count++;
		printf("%d个\n",count/2);
		printf("\n直接输入,继续(Ctrl+Z ->退出):\n");
	}
	printf("已退出慧眼识字，返回到游戏菜单\n"); 
} 
