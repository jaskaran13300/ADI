#include<stdio.h>

struct tree{
	int data;
	struct tree* left,*right;
};
void inorder(struct tree * root){
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
void preorder(struct tree * root){
	if(root==NULL)
	return;
	printf("%d  ",root->data);
	inorder(root->left);
	
	inorder(root->right);
}
void postorder(struct tree * root){
	if(root==NULL)
	return;
	inorder(root->left);

	inorder(root->right);
		printf("%d  ",root->data);
}
struct tree * insert(struct tree * root,int data){
	if(root==NULL){
		struct tree * temp=(struct tree *)malloc(sizeof(struct tree));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	 if((root->data)<data){
		root->right=insert(root->right,data);
	}

	else if((root->data)>data){
		root->left=insert(root->left,data);
	}
	return root;
}

int main(){
	struct tree *root=NULL;
	int i=0,data,n;
	printf("Enter n the node data\n");
	scanf("%d",&n);
	int ar[n];
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	root=insert(root,ar[0]);
	for(i=1;i<n;i++)
	insert(root,ar[i]);
	printf("\n IN ORDER:");
	inorder(root);
	printf("\n Post ORDER:");
	postorder(root);
	printf("\n PRE ORDER:");
	preorder(root);
}
