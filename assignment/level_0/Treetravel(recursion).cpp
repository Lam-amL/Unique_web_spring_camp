//�Եݹ鷽ʽʵ�������������&�������&�������
//�����������ݽṹ
#include <stdio.h>
#include <stdlib.h>
typedef int Elementtype;//int���Ի��ɱ���������� 
typedef struct tree{
	Elementtype data;
	tree *leftchild;
	tree *rightchild;
}Tree;
void preorder(Tree *root);
void inorder(Tree *root);
void postorder(Tree *root);
//Ϊ�˼����ȷ�ԣ���һ������Ĭ���и��ڵ�
void insert(Tree **root,Elementtype value);
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
		case 'x': preorder(r);break;
		case 'z': inorder(r);break;
		case 'h': postorder(r);break;
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
//��ʼ���� 
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
 
