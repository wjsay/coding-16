#include<stdio.h>
#include<string.h>
#include"literature.h" 
#include<stdlib.h>
#include"my.h"
#include<string.h>

extern struct proinfo *AI;

void modify_info(char *cp);
void l_admin(char *cp);
void query_info(char *cp);
void literature_administrator(){
	char key[100];
	/*do{
		printf("\n������������룺");
		scanf("%s",key);
		if(strlen(key)==1&&*key=='0')
			return;
	}while(strcmp(key,AI->me));*/
	char *cp[3]={"��ѧ//������.txt","��ѧ//Ъ����.txt","��ѧ//�������.txt"};
	int i=0;
	for(i=0;i<3;i++)
		creat_file(cp[i]);//�����ֶ�������������
	printf("\n********�������********\n"); 
	int cmd;
	while(1){
		printf("\n1.�Ķ�������\n");
		printf("\n2.�Ķ�Ъ����\n");
		printf("\n3.�Ķ��������\n");
		printf("\n0.�˳�\n");		
		printf("\n��ѡ��(0->�˳�)��");
		cmd=singal_unsigned_in();
		if(!cmd) return;
		if(cmd>3) continue;
		l_admin(cp[cmd-1]);
	} 
}

void add_info(char *cp);
void mydelete_info(char *);
void modify_info(char *);
void query_info(char *);

void l_admin(char *cp){
	printf("\n        ��ɾ�Ĳ�%s\n",&cp[6]);
	printf("\n1.������Ϣ\n");
	printf("\n2.ɾ����Ϣ\n");
	printf("\n3.�޸���Ϣ\n");
	printf("\n4.��ѯ��Ϣ\n");
	printf("\n0.�˳�\n");
	while(1){
		printf("\n��ɾ�Ĳ�|��ѡ��(0->�˳�)��");
		unsigned cmd;
		cmd=singal_unsigned_in();
		if(!cmd) return;
		switch(cmd){
			case 1:
				add_info(cp);
				break;
			case 2:
				mydelete_info(cp);
				break;
			case 3:
				modify_info(cp);
				break;
			case 4:
				query_info(cp);
				break;	 
		} 
	}
}
void mydelete_info(char *cp){//���ļ�cp��ɾ���Ľ��� 
	printf("\n�����ڲ������ļ��ǣ�%s\n",&cp[6]);
//�ȶ������� 
	struct l_link *head,*p,*q;
	head=(struct l_link *)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("\n��ȡ�ļ�ʧ��\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));//��ʼ������������ռ� 
		if(p==NULL){
			printf("\n����ռ�ʧ��\n");
			return; 
		}		
		
	}//����Ϣ 
	q->next=NULL;
	fclose(fp);
//����ʾ��Ϣ
	p=head;
	while(p->next){
		p=p->next; //��д�˴��룬����������д 
		printf("\n��Ŀ��%s\n��:%s\n\n",p->fname,p->fans);
	}
	for(;;){
		int flag=0;
		printf("\n����Ҫɾ������Ŀ���ߴ�(0->�˳�)��");
		char buffer[100];
		scanf("%s",buffer);
		if(strlen(buffer)==1&&*buffer=='0'){
			break;//mdzz//�տ�ʼ����д����return�����������һ��"wt" 
		}
		q=head;
		//������ɾ��ĳһ�ڵ� 
		while(q->next){
			struct l_link *t=q;
			q=q->next;
			if(strcmp(q->fname,buffer)==0||strcmp(q->fans,buffer)==0){//q����Ҫɾ���Ľڵ��ַ 
				t->next=q->next;
				//����ȫ�ֱ��� 
				flag=1;
				free(q); 
				break;
			}
		}
		if (flag) printf("\nɾ���ɹ�\n");
		else printf("\n���Ҳ�����ɾ��ʧ��\n"); 
	}
	p=head;
	if((fp=fopen(cp,"w"))==NULL){
		printf("\nд��ʧ��\n");
		return; 
	}
	while(p->next){
		p=p->next;
		fwrite(p,sizeof(struct l_link),1,fp);
		//pritnf("����ר��\n��Ŀ��%s\n��:%s",p->fname,p->fans);
	} 
	fclose(fp);
	printf("\nд�����\n"); 
}

//�����Ϣ 
void add_info(char *cp){
	printf("\nҪ������ļ��ǣ�%s\n",&cp[6]);
	FILE *fp;
	if((fp=fopen(cp,"at+"))==NULL){
		printf("\n���ļ�ʧ��\n");
		return ; 
	}
	
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n�����ڴ�ʧ��\n");
		return; 
	}
	head->next=NULL;
	q=head;
	char name[100],ans[100];
	while(1){
		printf("\n������������Ŀ(0->�˳�):");
		scanf("%s",name);
		if(strlen(name)==1&& *name=='0') break;
		printf("\n������𰸣�");
		scanf("%s",ans);
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n�����ڴ�ʧ��\n");
			break; 
		}
		strcpy(p->fname,name);
		strcpy(p->fans,ans);
		q->next=p;
		q=p;
	}
	q->next=NULL;
	p=head;
	while(p->next){
		p=p->next;
		fwrite(p,sizeof(struct l_link),1,fp);
	}
	fclose(fp);
	printf("\nд�����\n\n\n");
	 
}


//int l_link_space(struct l_link*p){
//	if(p==NULL){
//		printf("\n����ռ�ʧ��\n");
//		return -1; 
//	}
//	return 0;
//}

//���ļ�cp�У�����bufferɾ��һ����¼
int delete_info(char *cp,char *buffer){//û���õ� 
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		printf("\n��ȡ�ļ�ʧ��\n");
		return; 
	} 
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n����ռ�ʧ��\n");
			break ; 
		} 
	}//��ȡ�ļ�
	q->next=NULL;
	fclose(fp);
	if((fp=fopen(cp,"w"))==NULL){
		printf("\nд���ļ�ʧ��\n");
		return ; 
	}
	p=head;
	while(p->next){
		p=p->next;
		if(strcmp(buffer,p->fname)||strcmp(buffer,p->fans)){
			fwrite(p,sizeof(struct l_link),1,fp);
			return 0;//ɾ���ɹ� 
		}	
	}
	return -1;//ɾ��ʧ�� 
}

void modify_info(char *cp){
	printf("\n�����޸ĵ��ļ���%s\n\n",cp+6);
//������Ϣ
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		printf("\n��ȡ�ļ�ʧ��\n");
		return; 
	} 
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n����ռ�ʧ��\n");
			break ; 
		} 
	}//��ȡ�ļ�
	q->next=NULL;
	fclose(fp);//������Ϣ������·��û��д�ɺ�������Ϊ���붨��ȫ�ֱ��� 
//����ʾ��Ϣ
	p=head;
	while(p->next){
		p=p->next; //��д�˴��룬����������д 
		printf("\n��Ŀ��%s\n��:%s\n\n",p->fname,p->fans);
	} 
//����Ҫ�޸ĵ� a to b
	char buffer[100], buffer2[100];
	while(1){
		printf("\n����Ҫ�޸ĵ���Ŀ���(0->�˳�)��") ;
		scanf("%s",buffer);
		if(strlen(buffer)==1&&*buffer=='0'){
			break;
		}
		printf("\nҪ�ĳɣ���");
		scanf("%s",buffer2);
		
		if((fp=fopen(cp,"w"))==NULL){
			printf("\nд���ļ�ʧ��\n");
			return; 
		}
		p=head;
		while(p->next){
			p=p->next;
			if(strcmp(p->fans,buffer)==0) strcpy(p->fans,buffer2);
			if(strcmp(p->fname,buffer)==0) strcpy(p->fname,buffer2);
			fwrite(p,sizeof(struct l_link),1,fp);
		}
		fclose(fp);
		printf("\nд���ļ����\n");
	} 
}

void query_info(char *cp){
	printf("\n���ڲ�ѯ���ļ���%s\n\n",cp+6);
//������Ϣ
	struct l_link *head,*p,*q;
	head=(struct l_link*)malloc(sizeof(struct l_link));
	if(head==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	
	FILE *fp;
	if((fp=fopen(cp,"r"))==NULL){
		printf("\n��ȡ�ļ�ʧ��\n");
		return; 
	} 
	head->next=NULL;
	q=head;
	p=(struct l_link*)malloc(sizeof(struct l_link));
	if(p==NULL){
		printf("\n����ռ�ʧ��\n");
		return; 
	}
	while(fread(p,sizeof(struct l_link),1,fp)){
		q->next=p;
		q=p;
		p=(struct l_link*)malloc(sizeof(struct l_link));
		if(p==NULL){
			printf("\n����ռ�ʧ��\n");
			break ; 
		} 
	}//��ȡ�ļ�
	q->next=NULL;
	//������Ϣ������·��û��д�ɺ�������Ϊ���붨��ȫ�ֱ��� 
//����ʾ��Ϣ
	p=head;
	while(p->next){
		p=p->next; //��д�˴��룬����������д 
		printf("\n��Ŀ��%s\n��:%s\n\n",p->fname,p->fans);
	} 
//����Ҫ�޸ĵ� a to b
	char buffer[100];
	int flag; 
	while(1){
		flag=0;
		printf("\n\n����Ҫ��ѯ����Ŀ���(0->�˳�)��") ;
		scanf("%s",buffer);
		if(strlen(buffer)==1&&*buffer=='0'){
			break;
		}
		p=head;
		while(p->next){
			p=p->next;
			if(strcmp(buffer,p->fname)==0||strcmp(buffer,p->fans)==0){
				printf("\n��ѯ�����\n");
				printf("��Ŀ��%s\n",p->fname);
				printf("�𰸣�%s\n",p->fans);
				flag=1;
				break;
			}
		}
		if(!flag) {
			printf("\nû�в��ҵ�\n"); 
		}
	}
	fclose(fp);
}
