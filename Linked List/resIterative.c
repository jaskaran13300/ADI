#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void print(struct Node *ptr){
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

struct Node * rev(struct Node *head){
	struct Node *curr=head,*prev=NULL,*next=NULL;
	while(curr){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		
	}
	return prev;
	
	
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
	head=rev(head);
	print(head);
	return 0;
}
