#include<iostream>
using namespace std;

int count=0;
void Merge(int A[],int low,int mid,int high)
{
	int i = low;
	int j = mid+1;
	int k = 0;
	int B[high - low +1];
	 
	 while(i<=mid && j<=high)
	 {
	 	if(A[i]<=A[j])
	 	{
	 		count++;
	 		B[k++] = A[i++];
		 }
		 else{
		 	count++;
		 	B[k++] = A[j++];
		 }
	 }
	 while(i<=mid)
	 {
	 	B[k++]=A[i++];
	 }
	 while(j<=high)
	 {
	 	B[k++]=A[j++];
	 }
	 k=0;
	 for(int n=low;n<=high;n++)
	 {
	 	A[n] = B[k++];
	 }
}

void MergeSort(int A[],int low,int high)
{
	if(low<high)
	{
		int mid = (high +low)/2;
		MergeSort( A,low,mid);//divition in left side
		MergeSort( A,mid+1,high);
		Merge(A,low,mid,high);
	}
}
int main()
{
	int n;
	cout<<"enter the size of unsorted array"<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MergeSort(arr,0,n-1);
	cout<<"the sorted array is";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"no of comparison "<<count;
}
