//#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


struct tree{
	int data;
	struct tree* left,*right;
	
};
int i=0;
queue<struct tree *>q1;
stack<int> s1;

void levelorder(struct tree * root){
	q1.push(root);
	int s=q1.size();
	while(!q1.empty()){
		root=q1.front();
		q1.pop();
		if(i==0 || i%2==0){
			if(root->left)
			s1.push(root->left->data);
			if(root->right)
			s1.push(root->right->data);
		}
		if(i%2==0)
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
			i++;
			if(i%2!=0 ){
				while(!s1.empty()){
					cout<<s1.top()<<"  ";
					s1.pop();
				}
			}
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

//8
//6
//4
//3
//1
//5
//8
//7
//21
