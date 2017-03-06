#include<stdio.h>

void tools(){
	printf("	百宝箱\n\n1.一般的计算器\n\n2.用不完的笔记本\n\n");
	printf("3.概率计算器\n\n");
	printf("0.关闭工具箱\n\n"); 
	//printf("附：一会儿使用某个神器时，按 Ctrl+Z 结束并返回到百宝箱，^-^\n");
	unsigned int cmd;
	add_groth_value();
	while(1){
		printf("\n百宝箱请选择(0->退出):");
		//scanf("%u",&cmd);
		cmd=singal_unsigned_in();
		if(cmd==0){
			printf("已经退出百宝箱，返回到了地图（主菜单）\n\n");
			return;
		} 	
		switch(cmd%4){//若使用者乱输入，会发现一个有趣的现象，执行mod 3余数的选项 
			case 1:
				calculator();
				break;
			case 2:
				notpad();
				break;
			case 3:
				probality();
				break;
			default:
				printf("联系我们，告诉我们您需要什么神器\n\n"); 
				break ;
		}	
	}
}

