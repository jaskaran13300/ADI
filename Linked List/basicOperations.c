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
struct Node *insertBeg(struct Node *head,int data){
	if(head==NULL)
	{
		head=(struct Node *)malloc(sizeof(struct Node ));
		head->data=data;
		head->next=NULL;
		return head;
	}
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=head;
	head=temp;
	return head;
}
struct Node *insertLast(struct Node *head,int data){
	if(head==NULL){
		head=(struct Node *)malloc(sizeof(struct Node));
		head->data=data;
		head->next=NULL;
		return head;
	}
	else{
		struct Node *ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
		temp->data=data;
		temp->next=NULL;
		ptr->next=temp;
		return head;
	}
}
struct Node *delBeg(struct Node *head){
	if(head==NULL)
	return NULL;
	struct Node *temp=head;
	head=head->next;
	free(temp);
	return head;
}
struct Node *delLast(struct Node *head){
	if(head==NULL){
		return NULL;
	}
	struct Node *ptr=head;
	if(!ptr->next){
		free(head);
		return NULL;
	}
	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=NULL;
	return head;
}
struct Node *insertInbetween(struct Node *head,int n,int d){
	struct Node *ptr=head;
	int i=1;
	if(head==NULL)
	{
		head=(struct Node *)malloc(sizeof(struct Node));
		head->data=d;
		head->next=NULL;
		return head;
	}
	while(i<n && (ptr->next!=NULL)){
		i++;
		ptr=ptr->next;
	}
//	printf("**** %d ****",ptr->data);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=d;
	if(ptr->next!=NULL){
		temp->next=ptr->next->next;
		
	}
	else{
		temp->next=NULL;
	}
	ptr->next=temp;
	return head;
	
	
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
	head=insertLast(head,5);
	head=insertLast(head,7);
	head=insertBeg(head,0);
	head=insertBeg(head,9);
	head=insertInbetween(head,2,55);//send the node number
	head=delBeg(head);
	head=delLast(head);
	print(head);
	return 0;	
}
