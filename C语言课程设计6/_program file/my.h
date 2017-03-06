#include <stdio.h>

struct proinfo{
	unsigned int ID;
	char path[100];//存放个人信息的路径
	char *path_p; //为何不用&(AI->path)? 傻了吧 
	char name[50];
	char password[20];
	int grade;
	char mail[50];
	char dress[60];
	char ps[1000];
	char me[50];
	int groth_value;
};


