#include"my.h"
#include<stdlib.h>
extern user,*AI;

void login_registered(){
	
	//��д���棬��д���ܺ���������ע�ͣ�Ĭ�ϴ�ϰ�� 
	printf("\n            O(��_��)O��\n\n");
	printf("\n        1. ��¼     ������AIѧϰ���\n") ;
	printf("\n        2. ע��     ������ͬѧ\n");
	printf("\n        3. �޸�����\n");
	printf("\n        0. �˳�����\n\n");
	//**********************************
	//�����Ǻ��Ĺ����� 
	int num;
	while(1){
		printf("��ѡ��"); 
		//scanf("%d",&num);
		num=singal_unsigned_in();
		if(!num) exit(0);//�˳����г���
		if(num==2) {registered();break;}//�����û� 
		else if(num==3) modify_pswd();//�޸�����
		else {if(login()==0)break;}//��¼ 
	}
	add_groth_value(1);
	/*while(~scanf("%d",&num)&&num){
		if(num==2) {registered();break;}//�����û� 
		else if(num==3) modify_pswd();//�޸�����
		else {login();break;}//��¼ //��bug,����Ctrl+Z,�������룬�����˻� 
	}*/ 
} 
//ʹ����һ������itoa(); 
