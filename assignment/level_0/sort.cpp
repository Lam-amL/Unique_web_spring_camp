/*所有排序方法均集中在这一个sort文件中，假定题目是对一组int类型的乱序数进行从小到大排序，其中数列项数不定，数值不定（即数由用户定义），进行排序 */ 
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
	printf("请输入数的个数："); 
	scanf("%d",&n);
	pr=(int *)malloc(sizeof(int)*n);
	printf("请输入一列数:");
	for(int i=0;i<n;i++){
		scanf("%d",pr+i);
	}
	getchar(); 
	printf("请输入排序方法：");
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
	for(int i=0;i<n-1;i++){						//显然时间复杂度为O(n^2) 
		for(int j=0;j<n-j-1;j++){
			if(p[j]>p[j+1]){
				p[j]=p[j]^p[j+1];
				p[j+1]=p[j]^p[j+1];
				p[j]=p[j]^p[j+1];
			}
		}
	}
//然而上述冒泡，存在重复搜索的问题，当前面几个已经排好序时，所以可用标签进行优化
//优化思路：当没有发生交换时，表明排好序了
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
//根据查找方式的不同，有三种插入排序方法 
void direct_insertsort(int *p,int n){					//时间复杂度为O(n^2) 
	//为了少设变量和避免溢出，采取从后往前插入
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
void half_insertsort(int *p,int n){//结合二分查找 
	int temp,m;
	for(int i=1;i<n;i++){
		temp=p[i];
		int low=0,high=i-1;
		while(low<=high){
			m=low+(high-low)/2;
			if(temp>p[m]) low=m+1;
			else high=m-1;
		}
		for(int j=i;j>high;j--){		//时间复杂度还是0(n^2)，因为移动的时间复杂度始终为O(n) ,要优化则需链表结构 
			p[j]=p[j-1];
		}
		p[high+1]=temp;
	} 
}
void shell_insertsort(int *p,int n){		//直接插入排序是希尔排序当增量为1的排序，希尔排序的优化在于将无序变得相对有序，再用直接插入排序会简单一些 
	int t,k;
	printf("请输入希尔排序的趟数：");// 希尔函数的时间复杂度随着序列，增量，趟数的不同而不同，这涉及一些数学上尚未解决的难题，不过当n→∞时，为O(n(logn)^2). 
	scanf("%d",&t);
	int *dk=(int *)malloc(sizeof(int)*t);//t为希尔排序的趟数，dk[]为每趟的增量
	printf("请分别输入每趟的增量(为1时表明为直接插入排序)：");
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
void mergesort(int *p,int low,int high){//以一种二分的形式分而治之，时间复杂度为O(nlogn) ,分治思想 
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
void quicksort(int *p,int low,int high){//时间复杂度为O(nlogn) 
	if(low>=high) return;
	int i=low,j=high,pivot=p[low],temp;//将枢纽设为第一个数
	
	while(i<j){
		while(p[j]>=pivot&&i<j) j--;//不能去掉等号，会陷入无限循环当有两个数相等的时候 
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
		heapify(p,n,max);//从较大孩子结点递归，因为初始化堆的时候已经有所有父节点大于子节点 
	}
}
void build_heap(int *p,int n){
	int last_node=n-1;
	int parent=(last_node-1)/2;
	for(int i=parent;i>=0;i--){
		heapify(p,n,i);
	}
}
void heapsort(int *p,int n){//时间复杂度O(nlogn) 
	build_heap(p,n);
	for(int i=n-1;i>=0;i--){//教训，下次把拥有功能的函数模块化，防止低级错误 
		int temp=p[0];
		p[0]=p[i];
		p[i]=temp;
		heapify(p,i,0);
	}
}
