#include<bits/stdc++.h>
using namespace std;

int main(){
	stack <int> s;
	char str[100];
	cin>>str;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='['){
			s.push(str[i]);
		}
		else if(str[i]=='('){
			s.push(str[i]);
		}
		else if(str[i]=='{'){
			s.push(str[i]);
		}
		if(str[i]==']' ){
			if( !s.empty() && s.top()=='['){
				s.pop();
			}
			else{
				printf("Invalid\n");
				return 0;
			}
		}
		else if(str[i]=='}'){
			if( !s.empty() && s.top()=='{' ){
				s.pop();
			}
			else{
				printf("Invalid\n");
				return 0;
			}
		}
		else if(str[i]==')'){
			if(!s.empty() && s.top()=='('){
				s.pop();
			}
			else{
				printf("Invalid\n");
				return 0;
			}
		}
	}
	if(!s.empty()){
		printf("*Invalid\n");
		return 0;
	}
	printf("Valid\n");
	return 0;
}

