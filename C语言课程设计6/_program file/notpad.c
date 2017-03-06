#include<stdio.h>
void notpad(){
	printf("\n	笔记本\n");
	printf("\n1.新建文档\n");
	printf("\n2.查看我的文档\n");
	printf("\n3.删除特定文档\n");
	//printf("\n4.修改某个文档\n");//修改文件应用到修改目录上了 
	printf("\n0.退出笔记本\n");
	int cmd;
	while(1){
		printf("\n笔记本|请选择："); 
		scanf("%d",&cmd);
		if(!cmd) break;
		switch(cmd){
			case 1:
				newtxt();
				break;
			case 2:
				looktxt();
				break;
			case 3:
				deletetxt();
				break;
			//case 4:
				//renewtxt();
				//break;
			default:
				printf("输入不合法\n");
		}
	} 
	printf("\n您已退出笔记本\n");
} 
