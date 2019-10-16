#include<bits/stdc++.h>
using namespace std;
class Queue{
	int array[100];
	int front=-1,rear=-1;
	public:
void enqueue(int item)
{
	if(front ==-1 && rear==-1){
      front++;
      rear++;
      array[rear]=item;
    }
  else{
    rear++;
    array[rear]=item;
  }
}

int dequeue()
{
	if(rear<front){
      return -1;
    }
  else{
    front++;
    return array[front-1];
  }
}
};
int main(){
	char c;
	Queue q;
	int data;
	cout<<"Enter E for Enq. in Queue then data \n Enter d for dequeue from queue"<<endl;
	cout<<"IF QUEUE is empty and we will perform dequeue it will return -1"<<endl;
	scanf("%c",&c);
	while(1){
		if(c=='e'){
			cin>>data;
			q.enqueue(data);
		}
		else if(c=='d'){
			cout<<q.dequeue()<<endl;
		}
		scanf("%c",&c);
		cout<<"Enter the character"<<endl;
	}
}
