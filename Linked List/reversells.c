#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

struct StackLL
{
  int data;
  struct StackLL* next;
};
struct StackLL* main_Stack = NULL;	// The stack head to be used for operations.

struct StackLL* newElement(int data){
	struct StackLL *temp=(struct StackLL *)malloc(sizeof(struct StackLL));
	temp->data=data;
	return temp;
}

int isEmpty()
{
	if(main_Stack==NULL){
//		printf("UnderFlow\n");
      return 1;
    }
  else{
    return 0;
  }
}

void push(int data)
{
	struct StackLL *temp=newElement(data);
//   main_Stack=temp;
  temp->next=main_Stack;
  main_Stack=temp;
}

int pop()
{
  int d;
	if(isEmpty()){
      return -1;
    }
  else{
    struct StackLL *temp=main_Stack;
    d=temp->data;
    main_Stack=main_Stack->next;
//     free(temp);
  }
  return d;
}


void print(struct Node *ptr){
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void Reverse(struct Node *head){
	struct Node *temp=head;
	while(temp!=NULL){
		push(temp->data);
		temp=temp->next;
	}
	temp=head;
	while(!isEmpty()){
		temp->data=pop();
		temp=temp->next;
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
	Reverse(head);
	print(head);
	return 0;
}
