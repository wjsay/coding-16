#include"my.h"
#include<stdlib.h>
extern user,*AI;

void login_registered(){
	
	//先写界面，再写功能函数，若无注释，默认此习惯 
	printf("\n            O(∩_∩)O！\n\n");
	printf("\n        1. 登录     我已有AI学习伙伴\n") ;
	printf("\n        2. 注册     我是新同学\n");
	printf("\n        3. 修改密码\n");
	printf("\n        0. 退出程序\n\n");
	//**********************************
	//下面是核心功能区 
	int num;
	while(1){
		printf("请选择："); 
		//scanf("%d",&num);
		num=singal_unsigned_in();
		if(!num) exit(0);//退出所有程序
		if(num==2) {registered();break;}//创建用户 
		else if(num==3) modify_pswd();//修改密码
		else {if(login()==0)break;}//登录 
	}
	add_groth_value(1);
	/*while(~scanf("%d",&num)&&num){
		if(num==2) {registered();break;}//创建用户 
		else if(num==3) modify_pswd();//修改密码
		else {login();break;}//登录 //有bug,输入Ctrl+Z,跳过密码，进入账户 
	}*/ 
} 
//使用了一个函数itoa(); 
