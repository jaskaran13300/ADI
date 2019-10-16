#include<stdio.h>

struct tree{
	int data;
	struct tree* left,*right;
};

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

int calcHeight(struct tree * root){
	if(root==NULL){
		return 0;
	}
	int l=calcHeight(root->left);
	int r=calcHeight(root->right);
	return l>r?l+1:r+1;
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
	
	printf("%d",calcHeight(root));
}
