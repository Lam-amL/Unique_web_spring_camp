/*由于递归与栈相似，都是先进后出，因此用栈来模拟递归达到非递归实现递归功能的目的
	其中，top初值为-1时，表示出口停止pop，即停止循环；+1表示进栈，-1表示出栈 
		用数组表示栈的层次，而数组由二维指针malloc分配
该非递归的实现其中树的结构，树的创建与Treetravel(recursion).cpp 一样，重点在于遍历的实现
*/ 
#include <stdio.h>
#include <stdlib.h>
typedef int Elementtype;//int可以换成别的数据类型 
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
	Tree *r=NULL;//暂时默认都会申请成功，因此不再检验
	int n,temp;
	printf("请输入结点数目：");
	scanf("%d",&n);
	printf("请输入每个结点的值：");
	for(int i=0;i<n;i++){
		scanf("%d",&temp);//注意更换数据类型时要更换转换符 
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
void insert(Tree** root,Elementtype value){//构造一个左<根<=右的二叉树，便于中序遍历成为一个递增的值 
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
//栈的基本操作
void push(Tree **a,Tree *elem){
	a[++top]=elem;
} 
void pop(void){
	if(top==-1){
		printf("栈空\n");
	}
	top--;
}
Tree *gettop(Tree **a){
	return a[top];
}
//开始遍历 
void preorder(Tree *root,int n){
	Tree **stack=(Tree **)malloc((n+1)*sizeof(Tree *));
	Tree *temp;
	push(stack,root);
	while(top!=-1){
		temp=gettop(stack);
		pop();
		while(temp){
			printf("%d ",temp->data);
			if(temp->rightchild) push(stack,temp->rightchild);//根即为左，于是只需标记右 
			temp=temp->leftchild;							  //当根和左均遍历完，则从代表右结点的栈顶（子树）开始检验 
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
			if(temp->rightchild&&temp->rightchild!=p){//p表示是否曾经访问过，防止无限循环 
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
