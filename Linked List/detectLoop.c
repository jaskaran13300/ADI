#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void RemoveLoop(struct Node *slow){
	struct Node *temp=slow;
	while(temp!=slow->next){
		slow=slow->next;
	}
	slow->next=NULL;
}
void FindStart(struct Node *head,struct Node *fast){
	struct Node *slow = head; 
    while (slow != fast) { 
        slow = slow->next; 
        fast = fast->next; 
    } 
	printf("Loop Start from %d\n",slow->data);
	RemoveLoop(slow);
	
}
void point(struct Node *slow,struct Node *fast,struct Node *head){
	if(slow==fast){
		printf("Yes Loop Exist\n");
		printf("They meet each other at %d\n",slow->data);
		FindStart(head,slow);
		return;
	}
	if(fast==NULL){
		printf("Loop Not Exist\n");
		return;
	}
	if(fast->next==NULL){
		printf("Loop Not Exist\n");
		return;
	}
	point(slow->next,fast->next->next,head);
}
void print(struct Node *ptr){
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void DetectLoop(struct Node *head){
	struct Node *slow=head,*fast=head;
	if(fast->next->next && slow->next){
		fast=fast->next->next;
		slow=slow->next;
		
	}
	point(slow,fast,head);
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
	if(!head){
		printf("List is Empty");
		return 0;
	}
	int a,b;
	printf("Enter Two Numbers i.e From-To Loop\n");
	scanf("%d%d",&a,&b);
	i=1;
	int j=1;
	struct Node *temp=head;
	while(i!=a && temp!=NULL){
		temp=temp->next;
		i++;
	}
	if(temp==NULL){
		printf("No Such Elements exist in Linked List\n");
		return 0;
	}
	struct Node *temp1=head;
	while(j!=b  && temp1!=NULL) {
		temp1=temp1->next;
		j++;
	}
	if(temp1==NULL){
		printf("No Such Elements exist in Linked List\n");
		return 0;
	}
	temp->next=temp1;
	DetectLoop(head);
	printf("Link List After Removing The Loop is\n");
	print(head);
	return 0;
	
}
