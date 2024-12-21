#include<iostream>
using namespace std;
int stockprice(int arr[],int start,int end){
	if(end<=start){
		return 0;
	}
	int profit=0;
	for(int i=start;i<end;i++){
		for(int j=i;j<=end;j++){
			if(arr[j]>arr[i]){
				int curr_profit=arr[j]-arr[i]+stockprice(arr,start,i-1)+stockprice(arr,j+1,end);
				profit=max(profit,curr_profit);
			}
		}
	}
	return profit;
}
int main(){
	int a[]={10,20,30};
	int start=0;
	int end=2;
	int result=stockprice(a,start,end);
	cout<<"The profit is:"<<result<<endl;
}
