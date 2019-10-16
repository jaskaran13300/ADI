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
void swap(int *a,int *b) {
   int temp=*a;
   *a=*b;
   *b=temp;
 }
void Reverse(struct Node *head,struct Node *slow,struct Node *fast){
	static struct Node *temp=NULL;
	if(fast==NULL){
		temp=slow;
		return ;
	}
	if(fast->next==NULL){
		temp=slow->next;
		return ;
	}
	Reverse(head,slow->next,fast->next->next);
	struct Node *temp2;
	swap(&temp->data,&slow->data);
	temp=temp->next;
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
	Reverse(head,head,head);
	print(head);
	return 0;
}
