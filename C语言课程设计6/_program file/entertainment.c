#include<stdio.h>
#include"my.h"
extern struct proinfo *AI;
void entertainment(){
	printf("	��д�˼���С��Ϸ�����ĵ�ʱ��������� kill time\n");
	printf("\n1.����ʶ��\n");
	printf("\n2.%s���ռ�\n",AI->name);
	printf("\n3.��������\n"); 
	//printf("\n0.����0�˻�����ʱ�̲����ص�ͼ�����˵���\n"); 
	int cmd;
	while(1){
		printf("\n��Ϸ|��ѡ��(0->�˳�):");
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
				printf("�����С���\n");
		}
	} 
	add_groth_value(1);
	printf("\n�Ѿ��˳�����һ�£��ص��˵�ͼ\n");
}
//һ������0��ctrl+z�˳����߷�����һ�� 
