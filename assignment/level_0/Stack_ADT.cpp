//Stack ADT
define MAXSIZE 100
typedef int type；//同堆一样，用int来指代数据类型 
typedef struct{
	type *base;
	type *top;
	int stacksize; 
} Stack;
void initialize(Stack *p);
void push(Stack *p,type c);
type pop(Stack *p);
type gettop(Stack *p);
/*********************************************分    割      线**************************************/
void initialize(Stack *p){
	p->base=(type *)malloc(sizeof(type)*(MAXSIZE+1));//保证top指针不会指向未初始化的地方 
	if(p->base==NULL) printf("分配失败！");
	p->top=p->base;
	p->stacksize=MAXSIZE;
} 
void push(Stack *p,type c){
	if(p->top-p->base>=MAXSIZE) printf("没有多余空间\n");
	else	*p->top++=c;
	return;
}
type pop(Stack *p){
	if(p->top==p->base){
		printf("栈已空\n");
		exit(0);
	}
	return *--p->top;
}
type gettop(Stack *p){
	if(p->top==p->base){
		printf("栈已空\n");
		exit(0);
	}
	return *(p-->top-1);
}
