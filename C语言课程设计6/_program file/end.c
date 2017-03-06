#include"my.h"
extern struct proinfo *AI;//我明明定义了struct proinfo，还出现不完整的引用.而
						// 且extern 为何还要加上结构体类型 
void end(){		

	add_groth_value(1);//增加学习积分的函数
	printf("\n当前学习积分：%d\n",AI->groth_value); 
	printf("\n\n\n	    当你看到这个画面的时候，此次冒险之旅就真的结束了。");
	printf("\n	祝你在学习进步，bye.\n"); 
	fflush(stdin);
	getchar();
}
