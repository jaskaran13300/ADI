//Find whether there is a subtree in the given binary tree which has average node value equal to k.
//Note: Average of valid subtree should be an integer value equal to k and not a rounded off floating point number. Also note that a leaf node is also considered as a subtree.
//Input:
//3
//1 2 3 4 N 5 6 7 8 N 9 N 2
//5
//1 2 7 4 5
//7
//1 2 2 4 5
//3
//Output:
//True
//True
//False
//                       1
//                     /    \
//                   2      3
//                 /       /    \
//               4      5      6
//             /    \      \       \
//           7     8      9      2
//Average node value for subtree with root 3 = (3+5+9+6+2)/5 = 5
//Testcase 2:
//                      1
//                    /    \
//                  2      7
//                /    \
//              4      5
//Tree contains a leaf node with value 7.
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};
struct four{
  int sum;
  int count;
  bool found;
};
struct Node* newnode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right  = NULL; 
    return (node); 
} 
struct four check(Node *n,int k){
    if(!n){
        four ans;
        ans.sum=0;
        ans.found=false;
        ans.count=0;
        return ans;
    }
    four op1=check(n->left,k);
    four op2=check(n->right,k);
    if(op1.found){
        return op1;
    }
    if(op2.found){
        return op2;
    }
    int sum=(op1.sum+op2.sum+n->data);
    int count = op1.count+op2.count+1;
    four r;
    r.sum=(op1.sum+op2.sum+n->data);
    r.count=(op1.count+op2.count+1);
    if(sum%count==0 && sum/count==k){
        r.found=true;
    }
    else{
        r.found=false;
    }
    return r;
    
}
bool Kaverage_subNode(Node* n, int k)
{
    int found=0;
    four sum=check(n,k);
    return sum.found;
}
int main() 
{ 
    struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    int sum = 7; 
  
    if (Kaverage_subNode(root, sum)) 
        cout << "Yes"; 
    else
        cout << "No"; 
    return 0; 
} 

