#include<stdio.h> 
#include<string.h>
#include<math.h>
#define maxn 10000
int vis[maxn]; 
int prm[1230],e[1230];
int c,p,q,r,s;

int get_primes(int n,int *p){
	int i,j;
	int m=(int)sqrt(n+0.5);
	memset(vis,0,sizeof(vis));
	for( i=2;i<=m;i++)
		if(!vis[i]){
			for( j=i*i;j<=n;j+=i)
				vis[j]=1;
		}
	int c=0;
	for( i=2;i<=n;i++)
		if(!vis[i]) prm[c++]=i;//从0开始
	return c; 
}//素数筛选法 

//乘以或除以n. d=1表示乘，d=-1表示除 
void add_integer(int n,int d){
	int i; 
	for( i=0;i<c;i++){
		while(n%prm[i]==0){
			n/=prm[i];
			e[i]+=d;
		}
		if(n==1) break;//由于无素数1，指数不会再变化了，提前终止循环，节约时间 
	} 
}//最终结果分解成素数的乘积，这里改变指数 

void add_factorial(int n,int d){
	int i;
	for( i=1;i<=n;i++) add_integer(i,d); 
}//这个阶乘并不是直接的有1乘到n,实际上，参见add_integer(); 

void probality(){
	c=get_primes(maxn,prm);//c=1229
	printf("	计算概率，在排列组合中，C(m,n)=m!/(n!*(m-n)!),其中m>=n\n");
	printf("现给出计算C(p,q)/C(r,s)的计算器，请输入4个非负整数:(Ctrl+Z->退出)\n");
	while(~scanf("%d%d%d%d",&p,&q,&r,&s)){
		memset(e,0,sizeof(e));
		add_factorial(p,1);
		add_factorial(q,-1);
		add_factorial(p-q,-1);
		add_factorial(r,-1);
		add_factorial(s,1);
		add_factorial(r-s,1);
		double ans=1.0;
		int i;
		for( i=0;i<c;i++)
			ans*=pow(prm[i],e[i]);
		printf("%.5lf\n",ans);
	}
	printf("已退出概率计算器\n"); 
}
