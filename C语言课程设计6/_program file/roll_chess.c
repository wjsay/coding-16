#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> 

int roll_judge(int(*a)[20], int row, int column) {//行指针 
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


//后来增加随机棋盘，就加了if判断和两个goto语句 
void roll_chess() {
	//coord.X=0;//光标的列号
	//coord.Y=0;//光标的行号 
	int map[20][20];
	int i, j, x0, y0, x, y, row, column,ox,oy;
	int cur_x, cur_y;		//以后x0,y0就是图案的左上角， 		
	HANDLE hout;//声明句柄 		COORD coord;//声明光标位置 		

	char p[2][3] = { "○","●" };
	printf("	翻动棋子\n");
	printf("\n游戏规则：按上下左右控制键,只有走过的位置颜色会变化，\n棋子同色可获胜\n\n");
	lable2:
	printf("\n1.生成随机图\n");
	printf("\n>=2.从文件中读数据\n");
	printf("\n0.退出\n如果想退出，按两次Esc键(键盘左上角)\n");
	printf("\n请选择：");
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

		
	char *cp = "游戏//翻动棋子//地图.txt";
	FILE *fp;
	if ((fp = fopen(cp, "rt")) == NULL) {
		printf("\n打开图谱失败\n");
		return;
	}
	while (1) {
		printf("\n输入非零进行翻动棋子游戏(0->退出)：");
		int cd=singal_unsigned_in(); 
		if(!cd) {
			fclose(fp);
			break;
		}



		if(fscanf(fp, "%d%d", &row, &column)==EOF){
			printf("\n已通关\n"); 
			fclose(fp);
			break;
		}
		fscanf(fp, "%d%d", &x0, &y0);//起始点 
		

		for (i = 0; i<row; i++) {
			for (j = 0; j<column; j++) {
				fscanf(fp, "%d", &map[i][j]);
			}
		}
		//fclose(fp);	//从文件读入数据
		
		lable:			//(2,10);
		get_point(&cur_x, &cur_y);
		cur_y=0; 
		ox = 2, oy = 10;
		x = cur_x + ox;	y = cur_y + oy;
		move_point_to(x, y);;//光标下移两行 

		for (i = 0; i<row; i++) {
			for (j = 0; j<column; j++) {
				printf("%s", p[map[i][j]]);
			}
			move_point_to(++x, y);//光标下移一行 
		}
		x -= row;//写了row行,在减回去 
				 //宽：column         高：row
		int step = 0, ch;
		move_point_to(cur_x + oy, cur_y + 50);//打印步数的地方 
		printf("翻转次数:%d", step);
		x+=x0;
		y+=y0*2;//和文件有关，而且别忘了乘以2 
		while (1) {

			move_point_to(x, y);//再把光标移回来 
								//do{//避免乱输入 
			getch();
			ch = getch();
			//	if(ch==27) return 0;//Esc
			//}while(!(ch==72||ch==80||ch==75||ch==77));

			int tempx = x, tempy = y;//保存移动前的位置 
			switch (ch) {
			case 72://上 
				if (x - 1 >= cur_x + ox) {
					--x;
				}
				break;
			case 80://下 
				if (x + 1<cur_x + ox + row) {
					++x;
				}
				break;
				//小心带不带等号 ，左上带
				//水平移动，移两格 
			case 75://左 
				if (y - 2 >= oy + cur_y) {
					y -= 2;;
				}
				break;
			case 77://右 
					//注意是加上column*2
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
				*bl ^= 1;//异或转换 
				printf("%s", p[*bl]);
				step++;//为了便于调试，加了几个临时变量 
				move_point_to(cur_x + oy, cur_y + 50);//打印步数的地方 
				printf("翻转次数:%d", step);
				if (roll_judge(map, row, column))
					break;
				move_point_to(x, y);
			}
		}
		move_point_to(cur_x + row + 3, 0);
		printf("\n★★★恭喜你赢了★★★\n");
		if(cmd==1) goto lable2;

	}
	fclose(fp);
}

//文件格式 行 列 起始坐标(y,x)或许(0,0) 行*列 个数 



//以上是重写的代码，加了几个函数，定义在console.c 
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
	printf("	翻动棋子\n");
	printf("\n游戏规则：将所有棋子翻成同一种颜色即可获胜\n\n");
	//coord.X=0;//光标的列号
	//coord.Y=0;//光标的行号 
	 char p[2][3]={"○","●"};
	system("color 3E"); 
	printf("	翻动棋子\n");
	printf("\n游戏规则：按上下左右控制键，走过的位置颜色会变化，\n棋子同色可获胜(赢不了可以撞墙)\n\n");
	int map[20][20];
	int i,j,y0=5,x0=10,x,y,row,column;
	//x0,y0自己定义 
	//y0行坐标
	//x0列坐标 
	
	HANDLE hout;//声明句柄 
	COORD coord;//声明光标位置 
	
 	char *cp="游戏//翻动棋子//地图.txt";
	FILE *fp;
	if((fp=fopen(cp,"rt"))==NULL){
		printf("\n打开图谱失败\n");
		return;
	}
	fscanf(fp,"%d%d",&row,&column);
	fscanf(fp,"%d%d",&y,&x);
	coord.Y=y0;
	coord.X=x0;//初始坐标(x,y) 
	hout=GetStdHandle(STD_OUTPUT_HANDLE);//设置句柄输出 
	SetConsoleCursorPosition(hout,coord);//设置控制台指针位置
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			fscanf(fp,"%d",&map[i][j]);
		}
	}
	fclose(fp);	
	for(i=0;i<row;i++){
		
		/*for(j=0;j<column;j++){
			if(map[i][j]==1) printf("●");
			else printf("○");
		}*///因为那两个点事两个字节
/*1		for(j=0;j<column;j++){
			printf("%s",p[map[i][j]]);
		} 
		coord.Y++;
	    SetConsoleCursorPosition(hout,coord);//设置控制台指针位置
	}
	coord.Y=y;
	coord.X=x;
	 //(读入的x,y是起始坐标,不一定就在左上角x0,y0)
	SetConsoleCursorPosition(hout,coord);//设置控制台指针位置
	
	//宽：column         高：row
	//左上角，(x0,y0)
	int n=y,m=x;//n行坐标，m列坐标 
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
		SetConsoleCursorPosition(hout,coord);//设置控制台指针位置
		printf("翻转次数:%d",step);
		coord.Y=n;
		coord.X=m;
		SetConsoleCursorPosition(hout,coord);//设置控制台指针位置
		//0 1转换 
		map[n-y0][m-x0-(m-x0)/2]^=1;//异或转换 
		/* 
		if(map[y0][x0+(m-x0)/2]==0){
			map[y0][x0+(m-x0)/2]=1;
		}else{
			map[y0][x0+(m-x0)/2]=0;
		}*/
		
/*1		printf("%s",p[map[n-y0][m-x0-(m-x0)/2]]);
		switch(ch){
			case 72://上 
				if(n-1>=y0){
					coord.Y=--n;
				}
				break;
			case 80://下 
				if(n+1<y0+row){
					coord.Y=++n;
				}				
				break;		
				
						
			//小心带不带等号 ，左上带
			//水平移动，移两格 
			case 75://左 
				if(m-2>=x0){
					--m;
					coord.X=--m;
				}
				break;
			case 77://右 
			//注意是加上column*2
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
			break;//赢了 
		}
		SetConsoleCursorPosition(hout,coord);//设置控制台指针位置
	}
	SetConsoleCursorPosition(hout,coord);//设置控制台指针位置
	printf("\n★★★恭喜你赢了★★★\n");
	//printf("\n失败了，这一关是不是难了点\n");
	
	/*for(i=0;i<8;i++){
		getch();
		int ch=getch();
		printf("%d\n",ch);
	}*/

	//printf("\n已经退出该游戏\n"); 
	
/*1} 

//文件格式 行 列 起始坐标(y,x) 行*列 个数 


//void　roll_chess(){
//
//} 
*/
