//heap ADT
typedef int Elementtype;
typedef struct heap{
	int last_node;//��һΪ���ڵ�ı�� 
	int Maxsize;
	Elementtype *data;//�����intֻ��elementtype��һ������ 
} Heap;//���ｨ�������
int size(Heap *p);
bool empty(Heap *p);
void adjustdown(Heap *p,int k);
void adjustup(Heap *p,int k);
void initialize_empty(Heap *p,int size);
void initialize_basic(Heap *p,int size,Elementtype *arr);
void insert(Heap *p,Elementtype value);
Elementtype pop(Heap *p);
void swap(Heap *p,int a,int b);//�������� 
/******************************************************��  ��   ��**********************************************************/
void swap(Heap *p,int a,int b){
	int temp=p->data[b];
	p->data[b]=p->data[a];
	p->data[a]=temp;
}
int size(Heap *p){
	return p->last_node�� 
} 
bool empty(Heap *p){
	return 0==p->last_node;
} 
void adjustdown(Heap *p,int k){
	while(2*k<=p->last_node){
		int j=k*2;
		if(j+1<=p->last_node&&p->data[j+1]>p->data[j]) j=j+1;
		if(p->data[k]>p->data[j]) break;//ʼ������ѵĶ���
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
void initialize_basic(Heap *p,int size,Elementtype *arr){//size��arr�Ĵ�С 
	p->Maxsize=size;//�������޸�Maxsize 
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
		printf("û���㹻�Ĵ洢�ռ䡣\n");
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

