#include<stdio.h>

void tools(){
	printf("	�ٱ���\n\n1.һ��ļ�����\n\n2.�ò���ıʼǱ�\n\n");
	printf("3.���ʼ�����\n\n");
	printf("0.�رչ�����\n\n"); 
	//printf("����һ���ʹ��ĳ������ʱ���� Ctrl+Z ���������ص��ٱ��䣬^-^\n");
	unsigned int cmd;
	add_groth_value();
	while(1){
		printf("\n�ٱ�����ѡ��(0->�˳�):");
		//scanf("%u",&cmd);
		cmd=singal_unsigned_in();
		if(cmd==0){
			printf("�Ѿ��˳��ٱ��䣬���ص��˵�ͼ�����˵���\n\n");
			return;
		} 	
		switch(cmd%4){//��ʹ���������룬�ᷢ��һ����Ȥ������ִ��mod 3������ѡ�� 
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
				printf("��ϵ���ǣ�������������Ҫʲô����\n\n"); 
				break ;
		}	
	}
}

