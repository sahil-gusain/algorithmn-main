#include<iostream>
using namespace std;

int BinarySearch(int arr[],int low,int high,int key)
{
	if(high>=1){
	
	int mid = (low + high)/2;
	
	if(arr[mid]==key)
	   return mid;
	if(arr[mid]>key)
	   return 	BinarySearch(arr, low,mid-1, key);
	return BinarySearch(arr,mid+1, high, key);
	}
	return -1;
}
int main()
{
	int n,key;
	cout<<"enter the size of array"<<endl;
	cin>>n;
	cout<<"enter the sorted  array"<<endl;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter the no you want to search"<<endl;
	cin>>key;
	int flag;
	flag=BinarySearch(arr,0,n,key);
	if(flag==-1)
	cout<<"element is not present"<<endl;
	else
	cout<<"element is present at "<<flag<<" index"<<endl;
}
