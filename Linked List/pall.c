#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
int pall(struct Node *slow,struct Node *fast,struct Node *head){
	static int result;
	static struct Node *temp;
	if(fast==NULL){
		temp=slow;
		return 1;
	}
	if(fast->next==NULL){
		temp=slow->next;
		return 1;
		
	}
	result=pall(slow->next,fast->next->next,head);
	if(result==1){
		if(slow->data==temp->data){
			temp=temp->next;
			return 1;
		}
		else
		return 0;
	}
}
int main(){
	int d,i=0;
	printf("Press -1 To End insertion Operation\n");
	struct Node *head;
	struct Node *ptr;
	scanf("%d",&d);
	while(d!=-1){
		if(i==0){
			head=(struct Node *)malloc(sizeof(struct Node));
			head->data=d;
			head->next=NULL;
			ptr=head;
		}
		else{
			struct Node *temp=(struct Node *)malloc(sizeof(struct Node ));
			temp->data=d;
			temp->next=NULL;
			ptr->next=temp;
			ptr=ptr->next;
		}
		i++;
		scanf("%d",&d);
	}
	struct Node *slow=head,*fast=head;
	int q=pall(slow,fast,head);
	if(q){
		printf("Linked List is Pallindromic\n");
	}
	else
	printf("Linked List is Non Pallindromic\n");
	return 0;
}
