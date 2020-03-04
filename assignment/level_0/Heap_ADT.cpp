//heap ADT
typedef int Elementtype;
typedef struct heap{
	int last_node;//以一为根节点的标号 
	int Maxsize;
	Elementtype *data;//这里的int只是elementtype的一个代表 
} Heap;//这里建立大根堆
int size(Heap *p);
bool empty(Heap *p);
void adjustdown(Heap *p,int k);
void adjustup(Heap *p,int k);
void initialize_empty(Heap *p,int size);
void initialize_basic(Heap *p,int size,Elementtype *arr);
void insert(Heap *p,Elementtype value);
Elementtype pop(Heap *p);
void swap(Heap *p,int a,int b);//辅助函数 
/******************************************************分  割   线**********************************************************/
void swap(Heap *p,int a,int b){
	int temp=p->data[b];
	p->data[b]=p->data[a];
	p->data[a]=temp;
}
int size(Heap *p){
	return p->last_node； 
} 
bool empty(Heap *p){
	return 0==p->last_node;
} 
void adjustdown(Heap *p,int k){
	while(2*k<=p->last_node){
		int j=k*2;
		if(j+1<=p->last_node&&p->data[j+1]>p->data[j]) j=j+1;
		if(p->data[k]>p->data[j]) break;//始终满足堆的定义
		swap(p,j,k);
		k=j;
	}
}
void adjustup(Heap *p,int k){
	while(k>1&&p->data[k]>p->data[k/2]){
		swap(p,k,k/2);
		k/=2;
	}
}
void initialize_empty(Heap *p,int size){
	p->Maxsize=size;
	p->last_node=0;
	p->data=(Elenmenttype *)malloc(sizeof(Elementtype)*(Maxsize+1)); 
}
void initialize_basic(Heap *p,int size,Elementtype *arr){//size是arr的大小 
	p->Maxsize=size;//可自行修改Maxsize 
	p->data=(Elenmenttype *)malloc(sizeof(Elementtype)*(Maxsize+1)); 
	for(int i=0;i<size;i++){
		p->data[i+1]=arr[i]; 
	} 
	p->last_node=size;
	for(int i=p->last_node/2;i>=1;i--){
		adjustdown(p,i);
	}
}
void insert(Heap *p,Elementtype value){
	if(p->last_node+1>p->Maxsize) {
		printf("没有足够的存储空间。\n");
		return;
	}
	p->last_node++;
	p->data[last_node]=value;
	adjustup(p,last_node);
}
Elementtype pop(Heap *p){
	Elementtype temp=p->data[1];
	swap(p,1,last_node);
	p->data[last_node--]=0;
	return temp;
}

