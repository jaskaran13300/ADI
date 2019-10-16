#include<stdio.h>

int main(){
	int arr[100],low,n,key,high,mid,i;
	printf("Enter n,Enter array Elelemnts upto n,enter the key value\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	printf("Enter Key\n");
	scanf("%d",&key);
	low=0;
	high=n-1;
	
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==key)
		{
			printf("%d is found on %d th index\n",key,mid);
			return 0;
		}
		else if(arr[mid]<key){
			low=mid-1;
		}
		else if(arr[mid]>key){
			high=mid+1;
		}
	}
	printf("Key is Not Found\n");
	return 0;
}
