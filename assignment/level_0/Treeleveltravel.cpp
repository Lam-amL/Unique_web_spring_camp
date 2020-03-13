//树的层级遍历用递归方式较简单，不过题目要求用非递归，那么就用队列来模拟递归的层级遍历 
#include <stdio.h>
#include <stdlib.h>
typedef int Elementtype;//int可以换成别的数据类型 
typedef struct tree{
	Elementtype data;
	tree *leftchild;
	tree *rightchild;
}Tree;
int top=0,rear=0;
void levelorder(Tree *root,int n);
void enquene(Tree **a,Tree *root);
Tree * dequene(Tree **a);
void insert(Tree **root,Elementtype value);
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
	levelorder(r,n);
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
//队列的基本操作 
void enquene(Tree **a,Tree *n){
	a[rear++]=n;
}
Tree *dequene(Tree **a){
	if(top>=rear){
		printf("队列已空\n");
		return NULL; 
	}
	return a[top++];
}
//开始遍历 
void levelorder(Tree *root,int n){
	Tree **a=(Tree **)malloc(sizeof(Tree *)*(n+1));
	Tree *temp=NULL;
	enquene(a,root);
	while(rear>top){
		temp=dequene(a);
		printf("%d ",temp->data);
		if(temp->leftchild!=NULL){
			enquene(a,temp->leftchild);
		}
		if(temp->rightchild!=NULL){
			enquene(a,temp->rightchild);
		}
	}
}
