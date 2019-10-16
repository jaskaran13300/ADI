#include<stdio.h>

int getPairsCount(int arr[], int n, int sum)
{
  int l=0,r=n-1,c=0;
  while(l<r){
    if(arr[l]+arr[r]>sum){
      r--;
    }
    if(arr[l]+arr[r]<sum){
      l++;
    }
    else if(arr[r]+arr[l]==sum){
      c++;
     
      l++;
       if(c==n-1)
        l=0;
    }
  }
  return c;

}

int main(){
	int arr[100],n,i,s;
	printf("Enter n,arr elements,then sum value\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter Sum Value\n");
	scanf("%d",&s);
	printf("%d",getPairsCount(arr,n,s));
	return 0;
}
