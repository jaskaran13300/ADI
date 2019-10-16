#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void nNodeLast(struct Node *head,int n){
	int k=0;
	struct Node *slow=head,*fast=head;
 	 while(fast!=NULL && fast->next!=NULL){
    if(k==n){
      break;
    }
    k++;
    fast=fast->next;
  }
  int f=0;
  if(k<n){
    printf("%d",fast->data);
    f=1;
  }
  if(f!=1){
  while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next;
  }
  printf("%d",slow->next->data);
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
	int n;
	printf("Enter the n value\n");
	scanf("%d",&n);
	nNodeLast(head,n);
	return 0;
}
