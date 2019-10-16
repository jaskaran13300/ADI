#include<stdio.h>

void BinarySearch(int arr[],int low,int high,int key,int *f){
	if(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==key){
			f=1;
			printf("Key Is found\n");
			return;
		}
		else if(arr[mid]<key){
			return BinarySearch(arr,mid+1,high,key,f);
		}
		else if(arr[mid]>key){
			return BinarySearch(arr,low,mid-1,key,f);
		}
	}
	return;
}
int main(){
	int arr[100],low,n,key,high,mid,i;
	printf("Enter n,Enter array Elelemnts upto n,enter the key value\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	static int f=0;
	printf("Enter Key\n");
	scanf("%d",&key);
	low=0;
	high=n-1;
	mid=(low+high)/2;
	BinarySearch(arr,low,high,key,&f);
	if(f==0)
	printf("Key is Not found");
	return 0;	
}
