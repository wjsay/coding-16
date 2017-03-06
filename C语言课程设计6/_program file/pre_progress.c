#include"my.h"
#include<time.h>
#include<windows.h> 

extern struct proinfo user,*AI;//引用全局变量
 
void add_groth_value(int n);//随机增加积分的函数 
void pre_progress(){//预处理：读取学习积分和AI的信息 
	//想到的话，可以加点东西 
	//其实本来预处理是读入用户信息，和学习积分，但后来
	//学习积分加入到了用户信息的结构体里了，用户信息又作为了全局变量，所以
	//预处理和另一个end()函数没啥用了
	system("color 3E");
}


void add_groth_value(int n){
	srand(time(NULL));
	user.groth_value+=n*rand()%7;//n是几倍奖励 
}
