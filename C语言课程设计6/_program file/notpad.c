#include<stdio.h>
void notpad(){
	printf("\n	�ʼǱ�\n");
	printf("\n1.�½��ĵ�\n");
	printf("\n2.�鿴�ҵ��ĵ�\n");
	printf("\n3.ɾ���ض��ĵ�\n");
	//printf("\n4.�޸�ĳ���ĵ�\n");//�޸��ļ�Ӧ�õ��޸�Ŀ¼���� 
	printf("\n0.�˳��ʼǱ�\n");
	int cmd;
	while(1){
		printf("\n�ʼǱ�|��ѡ��"); 
		scanf("%d",&cmd);
		if(!cmd) break;
		switch(cmd){
			case 1:
				newtxt();
				break;
			case 2:
				looktxt();
				break;
			case 3:
				deletetxt();
				break;
			//case 4:
				//renewtxt();
				//break;
			default:
				printf("���벻�Ϸ�\n");
		}
	} 
	printf("\n�����˳��ʼǱ�\n");
} 
