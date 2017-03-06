#include<stdio.h>
#include"my.h"
extern struct proinfo *AI;
void entertainment(){
	printf("	我写了几个小游戏，无聊的时候可以玩下 kill time\n");
	printf("\n1.慧眼识字\n");
	printf("\n2.%s历险记\n",AI->name);
	printf("\n3.翻动棋子\n"); 
	//printf("\n0.输入0退回休闲时刻并返回地图（主菜单）\n"); 
	int cmd;
	while(1){
		printf("\n游戏|请选择(0->退出):");
		//scanf("%d",&cmd);
		cmd=singal_unsigned_in();
		if(!cmd) break;
		//getchar();
		switch(cmd){
			case 1:
				find_ch();
				break;
			case 2:
				tsp();
				break;
			case 3:
				roll_chess();
				break;
			default:
				printf("酝酿中……\n");
		}
	} 
	add_groth_value(1);
	printf("\n已经退出休闲一下，回到了地图\n");
}
//一般输入0或ctrl+z退出或者返回上一级 
