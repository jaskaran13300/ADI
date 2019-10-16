#include <bits/stdc++.h> 
using namespace std;
queue <int> q1;
queue <int> q2;

void push(int data){
	q2.push(data);
	while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
	}
	queue<int> q = q1; 
        q1 = q2; 
        q2 = q;
}
void pop(){
	if(q1.empty()){
		return;
	}
	q1.pop();
	
}

int top() 
{ 
    if (q1.empty()) 
        return -1; 
    return q1.front(); 
}
    
int main(){
	printf("Enter n,then elements\n");
	int n,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		push(data);
	}
	pop();
	printf("%d\n",q1.front());
	return 0;
}
