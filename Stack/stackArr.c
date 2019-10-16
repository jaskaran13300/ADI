#include<stdio.h>
int SIZE=100;
int Stack[200], top = -1;
int isFull()
{	
  	if(top+1==SIZE)
  	{
  		printf("Overflow\n");
		return 1;
	}
  else
    return 0;
}

int isEmpty()
{
	if(top==-1){
		printf("UNDERFLOW\n");
      return 1;
    }
  else{
    return 0;
  }
}

void push(int item)
{
  int r=-1;
  if(!isFull()){
	Stack[++top]=item;
  }
  return;
}

int pop()
{
  int r=-1;
  if(!isEmpty()){
	 r=Stack[top--];
  }
  return r;
}
void print(){
	int ptr=top+1;
	while((ptr--)>0){
		printf("%d ",Stack[ptr]);
	}
}
int main(){
	push(5);
	push(57);
	push(55);
	push(52);
	printf("%d ",pop());
	pop();
	pop();
	pop();
	pop();
	pop();
	print();
}
