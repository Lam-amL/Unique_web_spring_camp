/*�������򷽷�����������һ��sort�ļ��У��ٶ���Ŀ�Ƕ�һ��int���͵����������д�С����������������������������ֵ�������������û����壩���������� */ 
#include<stdio.h>
#include<stdlib.h>
void bubblesort(int *p,int n);
void direct_insertsort(int *p,int n);
void half_insertsort(int *p,int n);
void shell_insertsort(int *p,int n);
void mergesort(int *p,int low,int high);
void merge(int *p,int low,int high);
void quicksort(int *p,int low,int high);
void heapify(int *p,int n,int i);
void build_heap(int *p,int n);
void heapsort(int *p,int n);
int main(void){
	int n;
	int *pr=NULL;
	printf("���������ĸ�����"); 
	scanf("%d",&n);
	pr=(int *)malloc(sizeof(int)*n);
	printf("������һ����:");
	for(int i=0;i<n;i++){
		scanf("%d",pr+i);
	}
	getchar(); 
	printf("���������򷽷���");
	switch(getchar()){
		case 'b': bubblesort(pr,n);break;
		case 'd': direct_insertsort(pr,n);break;
		case 'h': half_insertsort(pr,n);break;
		case 's': shell_insertsort(pr,n);break;
		case 'm': mergesort(pr,0,n-1);break;
		case 'q': quicksort(pr,0,n-1);break;
		case 'H': heapsort(pr,n);break;
		default: printf("fatal:there is no such sort!\n"); 
	}
	for(int i=0;i<n;i++){
		printf("%d ",*(pr+i));
	}
	return 0;
}
void bubblesort(int *p,int n){
	for(int i=0;i<n-1;i++){						//��Ȼʱ�临�Ӷ�ΪO(n^2) 
		for(int j=0;j<n-j-1;j++){
			if(p[j]>p[j+1]){
				p[j]=p[j]^p[j+1];
				p[j+1]=p[j]^p[j+1];
				p[j]=p[j]^p[j+1];
			}
		}
	}
//Ȼ������ð�ݣ������ظ����������⣬��ǰ�漸���Ѿ��ź���ʱ�����Կ��ñ�ǩ�����Ż�
//�Ż�˼·����û�з�������ʱ�������ź�����
//	int flag=1;
//	while(n>1&&flag==1){
//		flag=0;
//		for(int i=0;i<n-1;i++){
//			if(p[i]>p[i+1]){
//				flag=1;
//				p[i]=p[i]^p[i+1];
//				p[i+1]=p[i]^p[i+1];
//				p[i]=p[i]^p[i+1];
//			}
//		}
//	n--;
//	} 
}
//���ݲ��ҷ�ʽ�Ĳ�ͬ�������ֲ������򷽷� 
void direct_insertsort(int *p,int n){					//ʱ�临�Ӷ�ΪO(n^2) 
	//Ϊ����������ͱ����������ȡ�Ӻ���ǰ����
	int temp,j;
	for(int i=1;i<n;i++){
		if(p[i]<p[i-1]){
			temp=p[i];
			p[i]=p[i-1];
			for(j=i-2;temp<p[j]&&j>=0;j--){
				p[j+1]=p[j];
			}
			p[j+1]=temp;
		}
	}
}
void half_insertsort(int *p,int n){//��϶��ֲ��� 
	int temp,m;
	for(int i=1;i<n;i++){
		temp=p[i];
		int low=0,high=i-1;
		while(low<=high){
			m=low+(high-low)/2;
			if(temp>p[m]) low=m+1;
			else high=m-1;
		}
		for(int j=i;j>high;j--){		//ʱ�临�ӶȻ���0(n^2)����Ϊ�ƶ���ʱ�临�Ӷ�ʼ��ΪO(n) ,Ҫ�Ż���������ṹ 
			p[j]=p[j-1];
		}
		p[high+1]=temp;
	} 
}
void shell_insertsort(int *p,int n){		//ֱ�Ӳ���������ϣ����������Ϊ1������ϣ��������Ż����ڽ������������������ֱ�Ӳ���������һЩ 
	int t,k;
	printf("������ϣ�������������");// ϣ��������ʱ�临�Ӷ��������У������������Ĳ�ͬ����ͬ�����漰һЩ��ѧ����δ��������⣬������n����ʱ��ΪO(n(logn)^2). 
	scanf("%d",&t);
	int *dk=(int *)malloc(sizeof(int)*t);//tΪϣ�������������dk[]Ϊÿ�˵�����
	printf("��ֱ�����ÿ�˵�����(Ϊ1ʱ����Ϊֱ�Ӳ�������)��");
	for(int i=0;i<t;i++){
		scanf("%d",&dk[i]);
		for(int j=dk[i];j<n;j++){
			if(p[j]<p[j-dk[i]]){
				int temp=p[j];
				for(k=j-dk[i];k>=0&&p[k]>temp;k-=dk[i]){
					p[k+dk[i]]=p[k];
				}
				p[k+dk[i]]=temp;
			}
		}
	}
} 
void mergesort(int *p,int low,int high){//��һ�ֶ��ֵ���ʽ�ֶ���֮��ʱ�临�Ӷ�ΪO(nlogn) ,����˼�� 
	int mid=low+(high-low)/2;
	if(low==high) return;
	else{
		mergesort(p,low,mid);
		mergesort(p,mid+1,high);
		merge(p,low,high);
	}
}
void merge(int *p,int low,int high){
	int mid=low+(high-low)/2;
	int temp[high-low+1];
	int i=low,j=mid+1,k=0;
	while(i<=mid&&j<=high){
		if(p[i]<p[j]) temp[k++]=p[i++];
		else temp[k++]=p[j++];
	}
	while(i<=mid) temp[k++]=p[i++];
	while(j<=high) temp[k++]=p[j++];
	k=0;
	for(int i=low;i<=high;i++){
		p[i]=temp[k++];
	}
}
void quicksort(int *p,int low,int high){//ʱ�临�Ӷ�ΪO(nlogn) 
	if(low>=high) return;
	int i=low,j=high,pivot=p[low],temp;//����Ŧ��Ϊ��һ����
	
	while(i<j){
		while(p[j]>=pivot&&i<j) j--;//����ȥ���Ⱥţ�����������ѭ��������������ȵ�ʱ�� 
		p[i]=p[j];
		while(p[i]<=pivot&&i<j) i++;
		p[j]-p[i]; 
	}
		p[i]=pivot;
		quicksort(p,low,i-1);
		quicksort(p,i+1,high); 
}
void heapify(int *p,int n,int i){
	if(i>=n) return;
	int cL=i*2+1;
	int cR=i*2+2;
	int max=i;
	if(cL<n&&p[max]<p[cL]) max=cL;
	if(cR<n&&p[max]<p[cR]) max=cR;
	if(max!=i){
		int temp=p[i];
		p[i]=p[max];
		p[max]=temp;
		heapify(p,n,max);//�ӽϴ��ӽ��ݹ飬��Ϊ��ʼ���ѵ�ʱ���Ѿ������и��ڵ�����ӽڵ� 
	}
}
void build_heap(int *p,int n){
	int last_node=n-1;
	int parent=(last_node-1)/2;
	for(int i=parent;i>=0;i--){
		heapify(p,n,i);
	}
}
void heapsort(int *p,int n){//ʱ�临�Ӷ�O(nlogn) 
	build_heap(p,n);
	for(int i=n-1;i>=0;i--){//��ѵ���´ΰ�ӵ�й��ܵĺ���ģ�黯����ֹ�ͼ����� 
		int temp=p[0];
		p[0]=p[i];
		p[i]=temp;
		heapify(p,i,0);
	}
}
