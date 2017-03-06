#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
/*********\ 
**��������
\*********/
void Qsort(int *a,int l,int r)
{//�ȿ���һ�Σ��ֳ�С��K�ʹ���K�������֣��ڷֱ�Qsort 
	if(l>=r)	return;
	int i=l,j=r,key=a[l];
	while(i<j)
	{
		while(i<j&&key<=a[j])	j--;
		a[i]=a[j]; 
		while(i<j&&key>=a[i])	i++;
		a[j]=a[i];
	}//���ڻ���С��ȡ�����������ǽ���
	a[i]=key;//�м����ع飬 
	Qsort(a,l,i-1);
	Qsort(a,i+1,r); 
}


//����ɸѡ������С�ڵ���n�������洢��������p�У��±��0��ʼ 
//���������ĸ���  

//�������� 
void toposort(){

#define maxn 510
	int m,n;
	int map[maxn][maxn];	
	int indegree[maxn];//������� 
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
		
		//�������������� 

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


//��״����Ӧ�� 
int intialization(){//��ʼ������ 
	int a[1010],c[1010],n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",a+i);
	return 0;
} 

void BuildTree(int *a,int *c,int n){//��a��c,n�� 
	memset(c,0,sizeof(c));
	int i,j;
	for( i=1;i<=n;i++){
		for( j=i-(i&(-i))+1;j<=i;j++){
			c[i]+=a[j];
		}
	}
}

//����c�±��1��ʼ���������״���� 
int Sum(int *c,int k) {//��ǰk���
//����c���ǽ�������״���� 
	int ret = 0; 
	while (k>0) {
		ret += c[k];
		k = k - (k&(-k));
	}
	return ret;
}

void Update(int lct, int x,int n,int *c) {//���������±�ά����״���� 
//����c���ǽ�������״���� 
	while (lct <= n) {
	//n������±� 
		c[lct] += x;
		lct = lct + lct&(-lct);
	}
}


//�ҵ��޷����������� 
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
