#include"my.h"
#include<time.h>
#include<windows.h> 

extern struct proinfo user,*AI;//����ȫ�ֱ���
 
void add_groth_value(int n);//������ӻ��ֵĺ��� 
void pre_progress(){//Ԥ������ȡѧϰ���ֺ�AI����Ϣ 
	//�뵽�Ļ������Լӵ㶫�� 
	//��ʵ����Ԥ�����Ƕ����û���Ϣ����ѧϰ���֣�������
	//ѧϰ���ּ��뵽���û���Ϣ�Ľṹ�����ˣ��û���Ϣ����Ϊ��ȫ�ֱ���������
	//Ԥ�������һ��end()����ûɶ����
	system("color 3E");
}


void add_groth_value(int n){
	srand(time(NULL));
	user.groth_value+=n*rand()%7;//n�Ǽ������� 
}
