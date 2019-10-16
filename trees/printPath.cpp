#include<bits/stdc++.h>

using namespace std;
int cost=INT_MIN;
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

void printPaths(struct tree * root,int arr[],int index){
	
	int sum=0;
	if(root==NULL){
		return;
	}
	if(root->left==NULL && root->right==NULL){
		arr[index++]=root->data;
//		arr[index]=index-1;
		for(int i=0;i<index;i++){
			cout<<arr[i]<<"  ";
			sum+=arr[i];
		}
		if(sum>=cost){
			cost=sum;
		}
		cout<<endl;
	}
	arr[index++]=root->data;
	printPaths(root->left,arr,index);
	printPaths(root->right,arr,index);
}

int main(){
	int arr[100],index=0;
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
	
	printPaths(root,arr,index);
	printf("\n Maximum Cost is %d",cost);
}
