#include "my.h"
void function(){
	int n;
	while(1){
		printf("\n地图模块|请选择(0->退出):"); 
		//scanf("%d",&n);
		n=singal_unsigned_in();
		if(!n) break;
		switch(n){
			case 1:
				literature();
				break;
			case 2:
				mathematic();
				break;
			case 3:
				entertainment();
				break;
			case 4:
				tools();
				break;
			case 5:
				myAI();
				break;
			case 6:
				contact_us();
				break;
			default://待开发区 
				desert();
				break;
		}
		add_groth_value(1);//每使用一个功能项，就会获得几个积分 
	}

}
