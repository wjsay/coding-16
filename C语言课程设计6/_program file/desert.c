#include<stdio.h>
#include<string.h>
void desert(){//�ޱ�ɳĮ���Ǵ�����������˼����������һЩ�µĹ��� 
	char *cp="�ޱ�ɳĮ//desert.txt";
	show_txt(cp); 
}

void contact_us(){//��ϵ���� �� �ޱ�ɳĮ �������ƣ�д��һ���ļ��� 
	{
		char *cp="��ϵ����//contact_us.txt";
		show_txt(cp);
	}
	
	printf("\n�����ùؼ�������һ����������(0->�˳�)��");
	char filename[80]="��ϵ����//",*cp=filename,buffer[50];
	scanf("%s",buffer);
	getchar();
	if(strlen(buffer)==1&&*buffer=='0') return; 
	strcat(cp,buffer);
	strcat(cp,".txt");
	FILE *fp;
	if((fp=fopen(cp,"w"))==NULL){
		printf("\nд���ļ�����\n");
		return;
	}
	printf("\n����ϸ������������(3���س���������):\n");
	char filetxt[2400],*p=filetxt,ch;
	int count=0;
	while(count<3){
		*p=getchar();
		if(*p++=='\n') count++; 
		else count=0;
	}//д�ĵ� 
	fwrite(filetxt,p-filetxt,1,fp);//���ǱʼǱ����ֵĴ��� 
	fclose(fp);	
	//�ϴ��ļ� 
	add_groth_value(3);//������Ϣ�ɵ����ݻ��� 
	printf("\n��л���ķ�����\n");
}
