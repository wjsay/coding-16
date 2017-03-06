#include<stdio.h> 
struct exam_error {
	double a[4];//num[]
	char b[3];//opt[]
	double std_res;//result,结果 		double user_res;//user_ans 
	double user_res;
	int count;//重新做，做对的次数，达到三次就不在计入 		struct exam_error *next;
	struct exam_error *next;
};//建立一个链表，用于存放计算错误的试题 

