#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> 

int roll_judge(int(*a)[20], int row, int column) {//��ָ�� 
	int sum = 0;
	int i, j;
	for (i = 0; i<row; i++)
		for (j = 0; j<column; j++)
			sum += a[i][j];
	if (sum == row*column || sum == 0) {
		return 1;
	}
	return 0;
}


//��������������̣��ͼ���if�жϺ�����goto��� 
void roll_chess() {
	//coord.X=0;//�����к�
	//coord.Y=0;//�����к� 
	int map[20][20];
	int i, j, x0, y0, x, y, row, column,ox,oy;
	int cur_x, cur_y;		//�Ժ�x0,y0����ͼ�������Ͻǣ� 		
	HANDLE hout;//������� 		COORD coord;//�������λ�� 		

	char p[2][3] = { "��","��" };
	printf("	��������\n");
	printf("\n��Ϸ���򣺰��������ҿ��Ƽ�,ֻ���߹���λ����ɫ��仯��\n����ͬɫ�ɻ�ʤ\n\n");
	lable2:
	printf("\n1.�������ͼ\n");
	printf("\n>=2.���ļ��ж�����\n");
	printf("\n0.�˳�\n������˳���������Esc��(�������Ͻ�)\n");
	printf("\n��ѡ��");
	unsigned cmd=singal_unsigned_in();
	if(!cmd) return; 
	if(cmd==1){
		srand(time(NULL));
		row=rand()%15+1;
		column=rand()%15+1;
		x0=rand()%row;
		y0=rand()%column;
		for(i=0;i<row;i++)
			for(j=0;j<column;j++)
				map[i][j]=rand()%2; 
		goto lable;
	}

		
	char *cp = "��Ϸ//��������//��ͼ.txt";
	FILE *fp;
	if ((fp = fopen(cp, "rt")) == NULL) {
		printf("\n��ͼ��ʧ��\n");
		return;
	}
	while (1) {
		printf("\n���������з���������Ϸ(0->�˳�)��");
		int cd=singal_unsigned_in(); 
		if(!cd) {
			fclose(fp);
			break;
		}



		if(fscanf(fp, "%d%d", &row, &column)==EOF){
			printf("\n��ͨ��\n"); 
			fclose(fp);
			break;
		}
		fscanf(fp, "%d%d", &x0, &y0);//��ʼ�� 
		

		for (i = 0; i<row; i++) {
			for (j = 0; j<column; j++) {
				fscanf(fp, "%d", &map[i][j]);
			}
		}
		//fclose(fp);	//���ļ���������
		
		lable:			//(2,10);
		get_point(&cur_x, &cur_y);
		cur_y=0; 
		ox = 2, oy = 10;
		x = cur_x + ox;	y = cur_y + oy;
		move_point_to(x, y);;//����������� 

		for (i = 0; i<row; i++) {
			for (j = 0; j<column; j++) {
				printf("%s", p[map[i][j]]);
			}
			move_point_to(++x, y);//�������һ�� 
		}
		x -= row;//д��row��,�ڼ���ȥ 
				 //��column         �ߣ�row
		int step = 0, ch;
		move_point_to(cur_x + oy, cur_y + 50);//��ӡ�����ĵط� 
		printf("��ת����:%d", step);
		x+=x0;
		y+=y0*2;//���ļ��йأ����ұ����˳���2 
		while (1) {

			move_point_to(x, y);//�ٰѹ���ƻ��� 
								//do{//���������� 
			getch();
			ch = getch();
			//	if(ch==27) return 0;//Esc
			//}while(!(ch==72||ch==80||ch==75||ch==77));

			int tempx = x, tempy = y;//�����ƶ�ǰ��λ�� 
			switch (ch) {
			case 72://�� 
				if (x - 1 >= cur_x + ox) {
					--x;
				}
				break;
			case 80://�� 
				if (x + 1<cur_x + ox + row) {
					++x;
				}
				break;
				//С�Ĵ������Ⱥ� �����ϴ�
				//ˮƽ�ƶ��������� 
			case 75://�� 
				if (y - 2 >= oy + cur_y) {
					y -= 2;;
				}
				break;
			case 77://�� 
					//ע���Ǽ���column*2
				if (y + 2<oy + cur_y + column * 2) {
					y += 2;
				}
				break;
			case 27:
				move_point_to(cur_x + row + 3, 0);
				return; 
			}
			if (!(x == tempx&&y == tempy)) {
				int xx = tempx - ox - cur_x;
				int yy = (tempy - oy - cur_y) / 2;
				int *bl = &map[xx][yy];
				*bl ^= 1;//���ת�� 
				printf("%s", p[*bl]);
				step++;//Ϊ�˱��ڵ��ԣ����˼�����ʱ���� 
				move_point_to(cur_x + oy, cur_y + 50);//��ӡ�����ĵط� 
				printf("��ת����:%d", step);
				if (roll_judge(map, row, column))
					break;
				move_point_to(x, y);
			}
		}
		move_point_to(cur_x + row + 3, 0);
		printf("\n���﹧ϲ��Ӯ�ˡ���\n");
		if(cmd==1) goto lable2;

	}
	fclose(fp);
}

//�ļ���ʽ �� �� ��ʼ����(y,x)����(0,0) ��*�� ���� 



//��������д�Ĵ��룬���˼���������������console.c 
/*1int roll_judge(int (*a)[20],int row,int column){
	int sum=0;
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			sum+=a[i][j];
	if(sum==row*column||sum==0){
		return 1;
	}
	return 0;
}

void roll_chess(){
	printf("	��������\n");
	printf("\n��Ϸ���򣺽��������ӷ���ͬһ����ɫ���ɻ�ʤ\n\n");
	//coord.X=0;//�����к�
	//coord.Y=0;//�����к� 
	 char p[2][3]={"��","��"};
	system("color 3E"); 
	printf("	��������\n");
	printf("\n��Ϸ���򣺰��������ҿ��Ƽ����߹���λ����ɫ��仯��\n����ͬɫ�ɻ�ʤ(Ӯ���˿���ײǽ)\n\n");
	int map[20][20];
	int i,j,y0=5,x0=10,x,y,row,column;
	//x0,y0�Լ����� 
	//y0������
	//x0������ 
	
	HANDLE hout;//������� 
	COORD coord;//�������λ�� 
	
 	char *cp="��Ϸ//��������//��ͼ.txt";
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("\n��ͼ��ʧ��\n");
		return;
	}
	fscanf(fp,"%d%d",&row,&column);
	fscanf(fp,"%d%d",&y,&x);
	coord.Y=y0;
	coord.X=x0;//��ʼ����(x,y) 
	hout=GetStdHandle(STD_OUTPUT_HANDLE);//���þ����� 
	SetConsoleCursorPosition(hout,coord);//���ÿ���ָ̨��λ��
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			fscanf(fp,"%d",&map[i][j]);
		}
	}
	fclose(fp);	
	for(i=0;i<row;i++){
		
		/*for(j=0;j<column;j++){
			if(map[i][j]==1) printf("��");
			else printf("��");
		}*///��Ϊ���������������ֽ�
/*1		for(j=0;j<column;j++){
			printf("%s",p[map[i][j]]);
		} 
		coord.Y++;
	    SetConsoleCursorPosition(hout,coord);//���ÿ���ָ̨��λ��
	}
	coord.Y=y;
	coord.X=x;
	 //(�����x,y����ʼ����,��һ���������Ͻ�x0,y0)
	SetConsoleCursorPosition(hout,coord);//���ÿ���ָ̨��λ��
	
	//��column         �ߣ�row
	//���Ͻǣ�(x0,y0)
	int n=y,m=x;//n�����꣬m������ 
	int step=0,ch;
	while(1){
		do{
			getch();
			ch=getch();
			if(ch==27) return;
		}while(!(ch==72||ch==80||ch==75||ch==77));
		
		step++;
		coord.Y=14;
		coord.X=58;
		SetConsoleCursorPosition(hout,coord);//���ÿ���ָ̨��λ��
		printf("��ת����:%d",step);
		coord.Y=n;
		coord.X=m;
		SetConsoleCursorPosition(hout,coord);//���ÿ���ָ̨��λ��
		//0 1ת�� 
		map[n-y0][m-x0-(m-x0)/2]^=1;//���ת�� 
		/* 
		if(map[y0][x0+(m-x0)/2]==0){
			map[y0][x0+(m-x0)/2]=1;
		}else{
			map[y0][x0+(m-x0)/2]=0;
		}*/
		
/*1		printf("%s",p[map[n-y0][m-x0-(m-x0)/2]]);
		switch(ch){
			case 72://�� 
				if(n-1>=y0){
					coord.Y=--n;
				}
				break;
			case 80://�� 
				if(n+1<y0+row){
					coord.Y=++n;
				}				
				break;		
				
						
			//С�Ĵ������Ⱥ� �����ϴ�
			//ˮƽ�ƶ��������� 
			case 75://�� 
				if(m-2>=x0){
					--m;
					coord.X=--m;
				}
				break;
			case 77://�� 
			//ע���Ǽ���column*2
				if(m+2<x0+column*2){
					++m;
					coord.X=++m;
				}
				break;
			default:
				break;
		}
		if(roll_judge(map,row,column)){
			coord.Y=x0+row+3;
			coord.X=y0+column+3; 
			break;//Ӯ�� 
		}
		SetConsoleCursorPosition(hout,coord);//���ÿ���ָ̨��λ��
	}
	SetConsoleCursorPosition(hout,coord);//���ÿ���ָ̨��λ��
	printf("\n���﹧ϲ��Ӯ�ˡ���\n");
	//printf("\nʧ���ˣ���һ���ǲ������˵�\n");
	
	/*for(i=0;i<8;i++){
		getch();
		int ch=getch();
		printf("%d\n",ch);
	}*/

	//printf("\n�Ѿ��˳�����Ϸ\n"); 
	
/*1} 

//�ļ���ʽ �� �� ��ʼ����(y,x) ��*�� ���� 


//void��roll_chess(){
//
//} 
*/
