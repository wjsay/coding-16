#include"my.h"
extern struct proinfo user,*AI;
void modify_pswd(){
	//printf("�޸�����\n");
	
	int num; 
	printf("������Ҫ�޸ĵ�AI�˺ţ�");
	scanf("%d",&num);
	char s[100]="������Ϣ//info_",*cp=s,str[13];
	itoa(num,str,10);
	strcat(cp,str);strcat(cp,".txt");
	FILE *fp; 
	if((fp=fopen(cp,"rt"))==NULL){
		puts("�����ļ��������ǲ��ǻ�ûע��[����]\n");
		printf("�Ѿ��˳��޸�����ĳ�ʽ��������������");
		return; 
	}
	fread(AI,sizeof(struct proinfo),1,fp);
	fclose(fp);
	do{
		printf("������%s��ԭ���룺",AI->name);
		char oldpswd[20]; 
		scanf("%s",oldpswd);oldpswd[strlen(oldpswd)]='\0';
		if(strcmp(oldpswd,AI->password)==0){
			printf("�����������룺");
			scanf("%s",oldpswd);
			char newpswd[20];
			printf("���ٴ���������ȷ�ϣ�");
		 	scanf("%s",newpswd);
		 	if(strcmp(oldpswd,newpswd)==0){
		 		newpswd[strlen(newpswd)]='\0';
		 		strcpy(AI->password,newpswd);
	 		  	fp=fopen(cp,"wt");
		 		fwrite(AI,sizeof(user),1,fp);
		 		fclose(fp);
		 		puts("�����޸ĳɹ������μ������밡\n");
		 		break;
		 	}else puts("�������벻һ���������޸�ʧ��\n");
		}
	}while(1);//�������޸Ĳ��ɹ���һֱѭ�������˳�����ڿ�����ϽǵĲ��� 	
}//�޸�����
