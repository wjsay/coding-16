#include"my.h"
#include"literature.h"
#include<string.h> 
#include<stdlib.h>

void guess(char *);
extern struct proinfo *AI;
void literature(){
	char *cp[3]={"��ѧ//������.txt","��ѧ//Ъ����.txt","��ѧ//�������.txt"};
	printf("\n        ��ѧ\n");
	printf("\n1.������\n");
	printf("\n2.Ъ����\n");
	printf("\n3.�������\n");
	printf("\n4.��Ŀ���\n");//����д�����вεģ������ʸ��ˣ����Ǵ��뺯�����ˣ��ҵ�һ����55555 
	printf("\n0.�˳�\n");
	add_groth_value(1);
	while(1){
		printf("\n��ѧ|��ѡ��(0->�˳�)��");
		unsigned cmd;
		cmd=singal_unsigned_in();
		if(cmd==0) break;
		if(cmd<4) guess(cp[cmd-1]);
		else if(cmd==4){
			literature_administrator(); 
		}else {
			printf("\n���벻�Ϸ�\n");
		} 
		/*switch(cmd){
			case 1:
				guess(cp[1]);
				break;
			case 2:
				guess(cp[2]);
				break;
			case 3:
				//idiom(cp[3]);
				break;
			case 4:
				literature_administrator(); 
				break;
			default:
				printf("\n���벻�Ϸ�\n"); 
		} */
	} 
}

void guess(char *cp){
	printf("\n      %s�����Ķ�%s\n",AI->me,cp+6);
	
	
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
	
	q=head;
	while(q->next){
		q=q->next;
		printf("\n\n\n%s:%s\n",AI->name,q->fname);
		char ans[100];
		for(;;){
			printf("\n(0->�˳���1->��һ��,2->�鿴��)���ǣ���");
			scanf("%s",ans);
			if(strlen(ans)==1){
				if(*ans=='0') return;
				if(*ans=='1') break;
				if(*ans=='2'){
					printf("%s:%s\n",AI->name,q->fans);
					continue;
				}
			}
			if(strcmp(ans,q->fans)==0){
				printf("\n����Great,����ˣ�����\n");
				break; 
			}else{
				printf("\n��һ�㣬������\n"); 
			}
		}
	} 
	printf("\n%s:ѽ��û��\n\n\n",AI->name);
}


