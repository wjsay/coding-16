#include "my.h"
extern struct proinfo *AI; 
void myAI(){
	/*char *cp="������Ϣ//information.txt";
	char *cp2="ѧϰ����//groth_value.txt";
	FILE *fp;
	struct proinfo user, *p=&user;
	int tot,*p2=&tot;
	if((fp=fopen(cp,"r"))==NULL){
		puts("AI�ܾ����ȡTA����Ϣ,�����쳣�˳�\n");
		exit(0); 
	} 
	fread(p,sizeof(*p),1,fp);
	fclose(fp);
	if((fp=fopen(cp2,"r"))==NULL){
		puts("��ȡѧϰ����ʧ�ܣ������쳣�˳�\n");
		exit(0);
	}
	fscanf(fp,"%d",p2);
	fclose(fp);
	//read_txt(p,cp);
	//read_txt(p2,cp2);*/ //�����޸��Ժ���Щ���ò����� 
	printf("\nAI���(��¼�˺�)��%d\n",AI->ID);
	printf("\f\n\n1.AI�ǳƣ�%s\n",AI->name);
	printf("\n2.�ҵ��ǳƣ�%s\n",AI->me);
	printf("\n3.�꼶��%d\n",AI->grade);
	printf("\n4.��ַ��%s\n",AI->dress);
	printf("\n5.��ע��%s\n",AI->ps);
	printf("\n���������һ�����\n");
	printf("\n��ǰѧϰ���֣�%d\n\n\n",AI->groth_value);
	
	//printf("\n����ר��\nAI->path_p:%s\n",AI->path_p);
	unsigned cmd;
	while(1){	
		printf("\n�޸���Ϣ���(0->�˳�)��");
		cmd=singal_unsigned_in();
		if(!cmd){
			break ;
		} 
		switch(cmd){
			case 1:
				printf("\n�������µ�AI�ǳƣ�");
				scanf("%s",AI->name);
				break;
			case 2:
				printf("\n�������µ��ǳƣ�");
				scanf("%s",AI->me);
				break;
			case 3:
				printf("\n�������µ��꼶��");
				AI->grade=singal_unsigned_in();
				break;
			case 4:
				printf("\n���µ�ַ��");
				scanf("%s",AI->dress);
				break;
			case 5:
				printf("\n�µı�ע��");
				scanf("%s",AI->ps); 
				break;
		}
	}
	FILE *fp;
	if((fp=fopen(AI->path,"wt"))==NULL){
		printf("\nд���ļ�ʧ�ܣ��쳣����\n");
		return; 
	}
	fwrite(AI,sizeof(struct proinfo),1,fp);
	fclose(fp);
	printf("\n������Ϣ���\n"); 
}
