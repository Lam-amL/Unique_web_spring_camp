//Stack ADT
define MAXSIZE 100
typedef int type��//ͬ��һ������int��ָ���������� 
typedef struct{
	type *base;
	type *top;
	int stacksize; 
} Stack;
void initialize(Stack *p);
void push(Stack *p,type c);
type pop(Stack *p);
type gettop(Stack *p);
/*********************************************��    ��      ��**************************************/
void initialize(Stack *p){
	p->base=(type *)malloc(sizeof(type)*(MAXSIZE+1));//��֤topָ�벻��ָ��δ��ʼ���ĵط� 
	if(p->base==NULL) printf("����ʧ�ܣ�");
	p->top=p->base;
	p->stacksize=MAXSIZE;
} 
void push(Stack *p,type c){
	if(p->top-p->base>=MAXSIZE) printf("û�ж���ռ�\n");
	else	*p->top++=c;
	return;
}
type pop(Stack *p){
	if(p->top==p->base){
		printf("ջ�ѿ�\n");
		exit(0);
	}
	return *--p->top;
}
type gettop(Stack *p){
	if(p->top==p->base){
		printf("ջ�ѿ�\n");
		exit(0);
	}
	return *(p-->top-1);
}
