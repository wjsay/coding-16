#include "my.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct proinfo user,*AI=&user; //������Ϣ�ṹ��ָ��p 

int main(int argc, char *argv[]) {
	pre_progress();	
	welcome(); //��ӭ�û��Ľ��棬���Ը��Ի�
	login_registered();//��¼/ע�ᴦ��
	function_menu();
	function(); 
	end();
	return 0;
}
