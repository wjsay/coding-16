#include"my.h"
extern struct proinfo *AI;//������������struct proinfo�������ֲ�����������.��
						// ��extern Ϊ�λ�Ҫ���Ͻṹ������ 
void end(){		

	add_groth_value(1);//����ѧϰ���ֵĺ���
	printf("\n��ǰѧϰ���֣�%d\n",AI->groth_value); 
	printf("\n\n\n	    ���㿴����������ʱ�򣬴˴�ð��֮�þ���Ľ����ˡ�");
	printf("\n	ף����ѧϰ������bye.\n"); 
	fflush(stdin);
	getchar();
}
