#include"my.h"
extern struct proinfo *AI;
void newtxt(){
	char filepath[100]="�ʼǱ�//�û� (",*cp=filepath,str[13];
	itoa(AI->ID,str,10);
	strcat(cp,str);strcat(cp,")//");
	printf("�����½��ĵ�������(0->�˳�)��");//�ʼǱ�//�û� (AI->ID)// filename.txt
	char filename[50];
	fflush(stdin);
	gets(filename);
	if(strlen(filename)==1&&*filename==0){
		printf("���˳�\n");
		return; 
	} 
	strcat(strcat(cp,filename),".txt");
	printf("�������������������س�����ʾд����\n"); 
	char filetxt[2400],*p=filetxt,ch;
	int count=0;
	while(count<3){
		*p=getchar();
		if(*p++=='\n') count++; 
		else count=0;
	}//д�ĵ� 
	FILE *fp;
	fp=fopen(cp,"wt");
	fwrite(filetxt,p-filetxt,1,fp);//ָ��p��������һ�� 
	fclose(fp);
	
	char contents[100]="�ʼǱ�//�û� (";
	strcat(strcat(contents,str),")//Ŀ¼.txt");
	if((fp=fopen(contents,"a+"))==NULL){
		printf("�ļ�����,������ѭ��\n");
		while(1);
	}
	fprintf(fp,"%s\n\r",filename);
	fclose(fp);
	printf("\n\nд����ɣ��Ѵ洢����\n"); 
}
//ʹ���º���system("mkdir,folder"); 
