#include<stdio.h> 
struct exam_error {
	double a[4];//num[]
	char b[3];//opt[]
	double std_res;//result,��� 		double user_res;//user_ans 
	double user_res;
	int count;//�����������ԵĴ������ﵽ���ξͲ��ڼ��� 		struct exam_error *next;
	struct exam_error *next;
};//����һ���������ڴ�ż����������� 

