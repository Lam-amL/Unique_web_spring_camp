//���Ĳ㼶�����õݹ鷽ʽ�ϼ򵥣�������ĿҪ���÷ǵݹ飬��ô���ö�����ģ��ݹ�Ĳ㼶���� 
#include <stdio.h>
#include <stdlib.h>
typedef int Elementtype;//int���Ի��ɱ���������� 
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
	Tree *r=NULL;//��ʱĬ�϶�������ɹ�����˲��ټ���
	int n,temp;
	printf("����������Ŀ��");
	scanf("%d",&n);
	printf("������ÿ������ֵ��");
	for(int i=0;i<n;i++){
		scanf("%d",&temp);//ע�������������ʱҪ����ת���� 
		insert(&r,temp);
	}
	levelorder(r,n);
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
//���еĻ������� 
void enquene(Tree **a,Tree *n){
	a[rear++]=n;
}
Tree *dequene(Tree **a){
	if(top>=rear){
		printf("�����ѿ�\n");
		return NULL; 
	}
	return a[top++];
}
//��ʼ���� 
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
