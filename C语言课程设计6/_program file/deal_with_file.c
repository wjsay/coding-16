#include<stdio.h>
#include<stdlib.h>

/*��ʾ�ı��ĵ�ȫ�����ݵĺ��� show_txt
��Ҫһ���ļ���ַ��ָ��������޷���ֵ */
void show_txt(char *cp){//���ڴ������� 
	FILE *fp;
	//char *p="��ӭ�û�����//welcome.txt";//���Ըú����õ� 
	if((fp=fopen(cp,"rt"))==NULL){
		printf("�Ҳ����ô򿪵��ļ�������ϵ����Ա\n");
		exit(0);
	}
	char str[88];
	while(fgets(str,80,fp)){
		puts(str);
	}
	fclose(fp);
}


//���·��cp�����ڣ��ͽ���һ���ļ� 
int creat_file(char *cp){
	FILE *fp;
	if((fp=(fopen(cp,"r")))==NULL) {
		if((fp=fopen(cp,"w"))==NULL){
			return -1;
		}
	}
	fclose(fp);
	return 1;
}


int write_txt(char *filetxt,int n){
	char *p=filetxt,ch;
	int count=0;
	while(count<3&&p<filetxt+n){
		*p=getchar();
		if(*p++=='\n') count++; 
		else count=0;
	}//д�ĵ� 
	return p-filetxt;
}

/****************************************************
void read_txt(void *pt,char *cp){//��ָ�� �ļ�·�� 
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		puts("��ȡ�ļ�ʧ�ܣ������쳣�˳�\n");
		getchar();
		exit(0);
	} 
	fread(pt,sizeof(*pt),1,fp);
	fclose(fp);
}//ʧ�ܵĺ������弰Ӧ�� ��Ӧ�ô��ڿ�ָ������ 
****************************************************/
