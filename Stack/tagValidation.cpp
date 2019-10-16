#include<bits/stdc++.h>
using namespace std;

void removeSpaces(char *str) 
{ 
    int count = 0; 
    for (int i = 0; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i]; 
    str[count] = '\0'; 
}


int main(){
	stack <string> s;
	char str[1000];
	printf("h  t ml tag is considered as html and all other tags are considered with removing all spaces\n");
	string tag="",tag1="";
	cin.getline(str, 1000);
	removeSpaces(str);
	int j;
	for(int i=0;i<strlen(str);i++){
			tag="";
			tag1="";
		if(str[i]=='<' && str[i+1]!='/'){
			i++;
//			int j=0;
			
			while(str[i]!='>'){
				tag+=str[i++];
			}
			s.push(tag);
		}
		else if(str[i]=='<' && str[i+1]=='/'){
				i=i+2;
//				j=0;
				while(str[i]!='>'){
					tag1+=str[i++];
				}
//				tag1[j]='\0';
				if(!s.empty() && !tag1.compare(s.top()) ){
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

