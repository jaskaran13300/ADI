#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
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

int clacHeight(struct tree * root){
	if(root==NULL){
		return 0;
	}
	int l=calcHeight(root->left);
	int r=calcHeight(root->right);
	return l>r?l+1:r+1;
}
int max(int x,int y){
	if(x>=y){
		return x;
	}
	else return y;
}
int diameter(struct tree * root){
	if(!root){
		return 0;
	}
	int l=clacHeight(root->left);
	int r=calcHeight(root->right);
	int ld=diameter(root->left);
	int rd=diameter(root->right);
	return max(l+r+1,max(ld,rd));
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
	if(!root){
		printf("0");
		return 0;
	}
	printf("%d",diameter(root));

	
	
}
