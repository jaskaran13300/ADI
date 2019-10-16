#include<stdio.h>
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
		printf("UnderFlow\n");
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
void print(){
	while(main_Stack!=NULL){
		printf("%d ",main_Stack->data);
		main_Stack=main_Stack->next;
	}
}
int main(){
	push(5);
	push(57);
	push(55);
	push(52);
	printf("%d ",pop());
//	pop();
//	pop();
//	pop();
//	pop();
//	pop();
//	print();
}

