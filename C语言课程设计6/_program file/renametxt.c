/*#include"my.h"
#include"file_link_node.h" 
extern struct proinfo *AI;
void deletetxt(){
	printf("	�������ļ�\n");
	char contents[100]="�ʼǱ�//�û� (";
	char str[13];
	itoa(AI->ID,str,10); 
	strcat(strcat(contents,str),")//Ŀ¼.txt");//�ʼǱ�//�û� (AI->ID)//Ŀ¼.txt 
	printf("\n�����ļ�:\n");
	show_txt(contents);//���ƵĲ鿴�ļ��Ĵ��� 
	
	FILE *fp;
	while(1){
		char filepath[100]="�ʼǱ�//�û� (",*cp=filepath;//�ʼǱ�//�û� ( 
		strcat(strcat(cp,str),")//");//�ʼǱ�//�û� (AI->ID)// 
		char newname[100],contents[100];
		strcpy(contents,cp);
		strcat(newname,"��������");//�ʼǱ�//�û� (AI->ID)//��ɾ�� 
		printf("������Ҫ���������ļ���(0->����)��");
		char filename[50];
		fflush(stdin);
		gets(filename);
		if(strlen(filename)==1&&filename[0]=='0') {
			printf("���˳�\n"); 
			break; 
		}
		strcat(contents,"Ŀ¼.txt");
		FILE *fp;
		if((fp=fopen(contents,"rt"))==NULL){
			printf("û�и��ļ���������ʧ��\n");
			continue; 
		}
		
		//================================
		//С�ģ�����������//������ɾ���ļ� 
		//================================
		struct LNode *head,*p,*q;
		head=(struct LNode *)malloc(sizeof(struct LNode));
		head->next=NULL;
		q=head; 
		//pΪָ��ǰ�ڵ��ָ�룬qΪָ�����һ���ڵ��ָ�� 
		char cap[100];
		while(~fscanf(fp,"%s",cap)){
			printf("���ļ���\ncap:%s\nfilename:%s\n",cap,filename);//ֻ�ڵ���ʱ�� 
			if(strcmp(cap,filename)){//����Ⱦ�ֱ�ӱ��� 
				p=(struct LNode*)malloc(sizeof(struct LNode));//�տ�ʼ���Ǽ�* 
				strcpy(p->filename,cap);
				q->next=p; 
				q=p;
			} 
			else{
				p=(struct LNode*)malloc(sizeof(struct LNode));//�տ�ʼ���Ǽ�* 
				strcpy(p->filename,newname);
				q->next=p; 
				q=p;				
			} 
		}
		q->next=NULL;
		fclose(fp);
		strcat(strcat(cp,filename),".txt");
		strcat(newname,filename);
		rename(cp,newname);//��������������ɾ����(������û����չ��) 
		//������û��ɾ��ԭ�ļ���dos����ͻ�ɾ��������
		remove(cp); 
		fp=fopen(contents,"wt");
		p=head->next;
		while(p){
			fprintf(fp,"%s\n\r",p->filename);
			printf("���� %s\n",p->filename);//����ר�� 
			p=p->next;
		}//û���ͷŽڵ㣬����������ȫ�ֱ���������������������ռ���ڴ�Ӧ�ûᱻ�ͷ� 
		fclose(fp);//���ǹر��ļ�,������ûд�룬����������д���� 
		printf("��ɾ���ļ���%s\n",filename); 
	} 
} *///��������д�� 
