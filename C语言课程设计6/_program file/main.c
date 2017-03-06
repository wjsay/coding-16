#include "my.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct proinfo user,*AI=&user; //个人信息结构体指针p 

int main(int argc, char *argv[]) {
	pre_progress();	
	welcome(); //欢迎用户的界面，可以个性化
	login_registered();//登录/注册处理
	function_menu();
	function(); 
	end();
	return 0;
}
