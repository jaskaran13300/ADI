#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

void FindMiddle(struct Node *head,struct Node *slow,struct Node *fast){
	if(fast==NULL){
		printf("%d",slow->data);
		return;
	}
	if(fast->next==NULL){
		printf("%d",slow->data);
		return;
	}
	FindMiddle(head,slow->next,fast->next->next);
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
	FindMiddle(head,head,head);
	return 0;
}
