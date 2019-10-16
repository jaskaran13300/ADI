#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


struct tree{
	int data;
	struct tree* left,*right;
	
};

queue<struct tree *>q1;

void levelorder(struct tree * root){
	q1.push(root);
	int s=q1.size();
	while(!q1.empty()){
		root=q1.front();
		q1.pop();
		cout<<root->data<<"  ";
		if(root->left){
			q1.push(root->left);
		}
		if(root->right){
			q1.push(root->right);
		}
		s--;
		if(s==0){
			s=q1.size();
			printf("\n");
		}
	}
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
	levelorder(root);
	return 0;	
}
