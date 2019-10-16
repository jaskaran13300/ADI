#include<bits/stdc++.h>
using namespace std;
class DoubleStack{
	int stack[100];
	int top1,top2;
	public:
		DoubleStack(){
			top1=-1;
			top2=100;
			memset(stack,0,sizeof(stack));
		}
		int isFull(){
			if(top1>top2){
				return 1;
			}
			else
			return 0;
		}
		int isEmpty1(){
			if(top1<=-1){
				return 1;
			}
			else 
			return 0;
		}
		int isEmpty2(){
			if(top2>=100){
				return 1;
			}
			else 
			return 0;
		}
		void push1(int data){
			if(!isFull()){
				stack[++top1]=data;
			}
			else{
				printf("OverFlow\n");
			}
		}
		void push2(int data){
			if(!isFull()){
				stack[--top2]=data;
			}
			else{
				printf("OverFlow\n");
			}
		}
		int pop1(){
			if(!isEmpty1()){
				return stack[top1--];
			}
			printf("UnderFlow First Array \n");
			return -1;
		}
		int pop2(){
			if(!isEmpty2()){
				return stack[top2++];
			}
			printf("Underflow Second Array\n");
			return -1;
		}
};
int main(){
	printf("Press q for Push in first Stack then data\n");
	printf("Press w for Push in Second Stack then data\n");
	printf("Press e for Pop in first Stack\n");
	printf("Press r for Pop in Second Stack\n");
	printf("In UnderFlow COndition It will Return -1\n");
	DoubleStack s;
	char c;
	while(1){
		printf("Enter Character\n");
		scanf("%c",&c);
		int data;
		if(c=='q'){
			printf("Enter Data\n");
			scanf("%d",&data);
			s.push1(data);
		}
		else if(c=='w'){
			printf("Enter Data\n");
			scanf("%d",&data);
			s.push2(data);
		}
		else if(c=='e'){
			printf("%d\n",s.pop1());
		}
		else if(c=='r'){
			printf("%d\n",s.pop2());
		}
	}
	return 0;
}
