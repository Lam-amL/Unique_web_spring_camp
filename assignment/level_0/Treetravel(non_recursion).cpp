/*���ڵݹ���ջ���ƣ������Ƚ�����������ջ��ģ��ݹ�ﵽ�ǵݹ�ʵ�ֵݹ鹦�ܵ�Ŀ��
	���У�top��ֵΪ-1ʱ����ʾ����ֹͣpop����ֹͣѭ����+1��ʾ��ջ��-1��ʾ��ջ 
		�������ʾջ�Ĳ�Σ��������ɶ�άָ��malloc����
�÷ǵݹ��ʵ���������Ľṹ�����Ĵ�����Treetravel(recursion).cpp һ�����ص����ڱ�����ʵ��
*/ 
#include <stdio.h>
#include <stdlib.h>
typedef int Elementtype;//int���Ի��ɱ���������� 
typedef struct tree{
	Elementtype data;
	tree *leftchild;
	tree *rightchild;
}Tree;
int top=-1;
void push(Tree **a,Tree *elem);
void pop(void);
Tree *gettop(Tree **a);
void insert(Tree **root,Elementtype value);
void preorder(Tree *root,int n);
void inorder(Tree *root,int n);
void postorder(Tree *root,int n); 
int main(void){
	Tree *r=NULL;//��ʱĬ�϶�������ɹ�����˲��ټ���
	int n,temp;
	printf("����������Ŀ��");
	scanf("%d",&n);
	printf("������ÿ������ֵ��");
	for(int i=0;i<n;i++){
		scanf("%d",&temp);//ע�������������ʱҪ����ת���� 
		insert(&r,temp);
	}
	getchar();
	switch(getchar()){
		case 'x': preorder(r,n);break;
		case 'z': inorder(r,n);break;
		case 'h': postorder(r,n);break;
		default:printf("error");
	}
	return 0;
}
void insert(Tree** root,Elementtype value){//����һ����<��<=�ҵĶ��������������������Ϊһ��������ֵ 
	Tree *node=(Tree *)malloc(sizeof(Tree));
	node->leftchild=NULL;
	node->rightchild=NULL;
	node->data=value;
	if(*root==NULL){
		*root=node;
		return;
	}
	Tree *temp=*root;
	while(temp!=NULL){
		if(temp->data>value){
			if(temp->leftchild==NULL){
				temp->leftchild=node;
				return;
			}
			else temp=temp->leftchild;
		}
		else{
			if(temp->rightchild==NULL){
				temp->rightchild=node;
				return;
			}
			else temp=temp->rightchild;
		}
	}
}
//ջ�Ļ�������
void push(Tree **a,Tree *elem){
	a[++top]=elem;
} 
void pop(void){
	if(top==-1){
		printf("ջ��\n");
	}
	top--;
}
Tree *gettop(Tree **a){
	return a[top];
}
//��ʼ���� 
void preorder(Tree *root,int n){
	Tree **stack=(Tree **)malloc((n+1)*sizeof(Tree *));
	Tree *temp;
	push(stack,root);
	while(top!=-1){
		temp=gettop(stack);
		pop();
		while(temp){
			printf("%d ",temp->data);
			if(temp->rightchild) push(stack,temp->rightchild);//����Ϊ������ֻ������ 
			temp=temp->leftchild;							  //��������������꣬��Ӵ����ҽ���ջ������������ʼ���� 
		}
	}
	free(stack); 
}
void inorder(Tree *root,int n){
	Tree **stack=(Tree **)malloc((n+1)*sizeof(Tree *));
	Tree *temp;
	temp=root;
	while(temp!=NULL||top!=-1){
		if(temp){
			push(stack,temp);
			temp=temp->leftchild;
		}
		else{
			temp=gettop(stack);
			printf("%d ",temp->data); 
			pop();
			temp=temp->rightchild;
		}
	}
}
void postorder(Tree *root,int n){
	Tree **stack=(Tree **)malloc((n+1)*sizeof(Tree *));
	Tree *temp,*p=NULL;
	temp=root;
	while(temp!=NULL||top!=-1){
		if(temp){
			push(stack,temp);
			temp=temp->leftchild;
		}
		else{
			temp=gettop(stack);
			if(temp->rightchild&&temp->rightchild!=p){//p��ʾ�Ƿ��������ʹ�����ֹ����ѭ�� 
				temp=temp->rightchild;
			}
			else{
				printf("%d ",temp->data);
				pop();
				p=temp;
				temp=NULL;
			}
		}
	}
}
