#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


struct tree{
	int data;
	struct tree* left,*right;
	
};

queue<struct tree *>q1;

void Reverselevelorder(struct tree * root,stack<int> &s1){
	q1.push(root);
	while(!q1.empty()){
		root=q1.front();
		q1.pop();
		
		s1.push(root->data);
		
		if(root->left){
			q1.push(root->left);
		}
		if(root->right){
			q1.push(root->right);
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

void printStack(stack<int> s1){
	while(!s1.empty()){
		cout<<s1.top()<<"  ";
		s1.pop();
	}
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
	stack<int> s1;
	Reverselevelorder(root,s1);
	printStack(s1);
	
	return 0;	
}




//9
//6
//4
//3
//5
//1
//8
//7
//21
//10
