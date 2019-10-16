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
void level(struct tree*root,int hd,map<int, vector<int> > &m){
	if(!root)
	return;
	m[hd].push_back(root->data);
	level(root->left,hd-1,m);
	level(root->right,hd+1,m);
}
void verticalOrder(struct tree * root){
	map<int,vector<int> > m;
	int hd=0;
	level(root,hd,m);
	map< int,vector<int> > :: iterator it;
	for(it=m.begin();it!=m.end();it++){
//		cout<<it->first<<"     ";
		for(int i=0;i<it->second.size();i++){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}
//level(root,hd,m);
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
	verticalOrder(root);
	return 0;	
}








//9
//10
//8
//7
//9
//15
//13
//14
//18
//20
