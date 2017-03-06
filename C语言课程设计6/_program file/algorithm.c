#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
/*********\ 
**快速排序
\*********/
void Qsort(int *a,int l,int r)
{//先快排一次，分成小于K和大于K的两部分，在分别Qsort 
	if(l>=r)	return;
	int i=l,j=r,key=a[l];
	while(i<j)
	{
		while(i<j&&key<=a[j])	j--;
		a[i]=a[j]; 
		while(i<j&&key>=a[i])	i++;
		a[j]=a[i];
	}//大于还是小于取决于是升序还是降序
	a[i]=key;//中间数回归， 
	Qsort(a,l,i-1);
	Qsort(a,i+1,r); 
}


//素数筛选法，把小于等于n的素数存储到，数组p中，下标从0开始 
//返回素数的个数  

//拓扑排序 
void toposort(){

#define maxn 510
	int m,n;
	int map[maxn][maxn];	
	int indegree[maxn];//入度数组 
	int i,j,k;
	int p1,p2;
	while(scanf("%d%d",&n,&m)==2){
		memset(map,0,sizeof(map));
		memset(indegree,0,sizeof(indegree));
		for( i=0;i<m;i++){
			scanf("%d%d",&p1,&p2);
			if(!map[p1][p2]){
				map[p1][p2]=1;
				indegree[p2]++;
			}
		}
		
		//以下是拓扑排序 

		for( i=1;i<=n;i++)
			for( j=1;j<=n;j++){
				if(indegree[j]==0){ 
					indegree[j]--;
					if(i!=n) printf("%d ",j);
					else printf("%d",j);
					for( k=1;k<=n;k++){
						if(map[j][k]==1)
							indegree[k]--;
					}
					break;
				}
			}
	} 
}


//树状数组应用 
int intialization(){//初始化数组 
	int a[1010],c[1010],n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",a+i);
	return 0;
} 

void BuildTree(int *a,int *c,int n){//由a建c,n个 
	memset(c,0,sizeof(c));
	int i,j;
	for( i=1;i<=n;i++){
		for( j=i-(i&(-i))+1;j<=i;j++){
			c[i]+=a[j];
		}
	}
}

//数组c下标从1开始，其就是树状数组 
int Sum(int *c,int k) {//求前k项和
//数组c就是建立的树状数组 
	int ret = 0; 
	while (k>0) {
		ret += c[k];
		k = k - (k&(-k));
	}
	return ret;
}

void Update(int lct, int x,int n,int *c) {//根据数组下标维护树状数组 
//数组c就是建立的树状数组 
	while (lct <= n) {
	//n是最大下标 
		c[lct] += x;
		lct = lct + lct&(-lct);
	}
}


//我的无符号整型输入 
unsigned singal_unsigned_in(){
	char ch;
	while((ch=getchar())=='\n'||ch==' '||ch=='\t');
	unsigned ret=0;
	for(;;){
		if('0'<=ch&&ch<='9')
			ret=ret*10+ch-'0';	
		ch=getchar();	
		if(ch=='\n') return ret;	
	}
}
