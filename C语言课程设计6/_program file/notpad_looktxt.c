#include"my.h"
extern struct proinfo *AI;
void looktxt(){
	printf("	�鿴�ļ�\n\n");
	
	char contents[100]="�ʼǱ�//�û� (";
	char str[13];
	itoa(AI->ID,str,10); 
	strcat(strcat(contents,str),")//Ŀ¼.txt");//����Ŀ¼·���ľ������ 
	printf("�����ļ�:\n");
	show_txt(contents);
	FILE *fp;
	while(1){
		char filepath[100]="�ʼǱ�//�û� (",*cp=filepath;
		strcat(strcat(cp,str),")//");
		
		printf("������Ҫ�鿴���ļ���(0->����)��");
		char filename[50];
		fflush(stdin);
		gets(filename);
		if(strlen(filename)==1&&filename[0]=='0') {
			printf("���˳��鿴\n"); 
			break; 
		}
		strcat(strcat(cp,filename),".txt");
		if((fp=fopen(cp,"rt"))==NULL){
			printf("û���ļ���%s\n",filename);
			continue;
		} 
		fclose(fp);
		show_txt(cp);
	} 
} 
