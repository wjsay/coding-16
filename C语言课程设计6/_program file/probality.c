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
		if(!vis[i]) prm[c++]=i;//��0��ʼ
	return c; 
}//����ɸѡ�� 

//���Ի����n. d=1��ʾ�ˣ�d=-1��ʾ�� 
void add_integer(int n,int d){
	int i; 
	for( i=0;i<c;i++){
		while(n%prm[i]==0){
			n/=prm[i];
			e[i]+=d;
		}
		if(n==1) break;//����������1��ָ�������ٱ仯�ˣ���ǰ��ֹѭ������Լʱ�� 
	} 
}//���ս���ֽ�������ĳ˻�������ı�ָ�� 

void add_factorial(int n,int d){
	int i;
	for( i=1;i<=n;i++) add_integer(i,d); 
}//����׳˲�����ֱ�ӵ���1�˵�n,ʵ���ϣ��μ�add_integer(); 

void probality(){
	c=get_primes(maxn,prm);//c=1229
	printf("	������ʣ�����������У�C(m,n)=m!/(n!*(m-n)!),����m>=n\n");
	printf("�ָ�������C(p,q)/C(r,s)�ļ�������������4���Ǹ�����:(Ctrl+Z->�˳�)\n");
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
	printf("���˳����ʼ�����\n"); 
}
