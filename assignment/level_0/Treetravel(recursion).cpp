//以递归方式实现树的先序遍历&中序遍历&后序遍历
//构造树的数据结构
#include <stdio.h>
#include <stdlib.h>
typedef int Elementtype;//int可以换成别的数据类型 
typedef struct tree{
	Elementtype data;
	tree *leftchild;
	tree *rightchild;
}Tree;
void preorder(Tree *root);
void inorder(Tree *root);
void postorder(Tree *root);
//为了检测正确性，造一棵树，默认有根节点
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
	getchar();
	switch(getchar()){
		case 'x': preorder(r);break;
		case 'z': inorder(r);break;
		case 'h': postorder(r);break;
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
//开始遍历 
void preorder(Tree *root){
	if(root==NULL) return;
	printf("%d ",root->data);
	preorder(root->leftchild);
	preorder(root->rightchild); 
}
void inorder(Tree *root){
	if(root==NULL) return;
	inorder(root->leftchild);
	printf("%d ",root->data);
	inorder(root->rightchild);
}
void postorder(Tree *root){
	if(root==NULL) return;
	postorder(root->leftchild);
	postorder(root->rightchild);
	printf("%d ",root->data);
}
 
