#include"my.h"
#include<stdlib.h>
#include<string.h>
extern struct proinfo *AI;
extern struct proinfo user;
void registered(){
	//printf("ע��\n");//������ 
	char *cp_user_ID="������Ϣ//�û�����.txt";
	FILE *fp; 
	char pswd[20];
	if((fp=fopen(cp_user_ID,"r"))==NULL){
		printf("���ļ�ʧ�ܣ��޷��õ�AI���\n");
		exit(0);
	}
	fscanf(fp,"%u",&user.ID);
	fclose(fp); //��������ر� 
	AI->ID++;//�½���ID���
	char str[12]; 
	itoa(AI->ID,str,10);//��ʮ���Ƶ�ID��ת��Ϊ�ַ��� ,(�Ჹ'\0') 
	strcpy(AI->path,"������Ϣ//info_");
	strcat(AI->path,str);strcat(AI->path,".txt");//������·�����Ժ������ 
	AI->path_p=AI->path;
	printf("����AI����ǣ�%u\n",AI->ID);
	printf("������AI����Ϣ������������\n");
	printf("�ǳƣ�");
	scanf("%s",AI->name);
	do{
		printf("�������룺");
		scanf("%s",AI->password);
		AI->password[strlen(AI->password)]='\0'; //printf("%s\n",p->password);
												//������'\0',���뿴��ȥһ����������� 
		printf("���ٴ�����ȷ�ϣ�");
		scanf("%s",pswd);
		pswd[strlen(pswd)]='\0';  //printf("%s\n",pswd);
	}while(strcmp(pswd,AI->password)!=0); //ֱ��������������һ�� 
	printf("�꼶�����֣���");
	//scanf("%d",&(AI->grade));
	AI->grade=singal_unsigned_in();
	printf("���佫��Ϊ�һ������Ψһ;�������������!\n");
	printf("���䣺");
	scanf("%s",AI->mail);
	printf("��ַ��");
	scanf("%s",AI->dress); 
	printf("��ע��");
	scanf("%s",AI->ps);
	printf("�����ϣ��AI�����ƺ����أ�");
	scanf("%s",AI->me);
	fp=fopen(AI->path,"wt");
	fwrite(AI,sizeof(struct proinfo),1,fp);
	fclose(fp);
	fp=fopen(cp_user_ID,"wt");//�����û����� 
	fprintf(fp,"%u\n",AI->ID);
	fclose(fp);
	printf("\n\n��ϲ��ӵ����AIС���:%s\n����ð��֮�ðɣ�\n\n",AI->name); 
}//ע���˺� 
