#include<bits/stdc++.h>
using namespace std;
void printdata(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void quicksort(int *arr,int lb,int ub){
	int loc;
	if(lb<ub){
		loc=quick(arr,lb,ub);
		quicksort(arr,lb,loc-1);
		quick(arr,loc+1,ub);
	}
}
int quick(int *arr,int lb,int ub){
	int start,end;
	start=lb;
	end=ub;
	int pivot=arr[lb];
	while(start<end){
		while(arr[start]>=pivot){
			start++;
		}
		while(arr[end]<pivot){
			end--;
		}
		if(start<end){
			swap(arr[start],arr[end]);
		}	
	}
	swap(arr[lb],arr[end]);
	return end;
}
void mergesort(int *arr,int lb,int ub){
	if(lb<ub){
		int mid=(lb+ub)/2;
		mergesort(arr,lb,mid);
		mergesort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
void merge(int *arr,int lb,int mid,int ub){
	int i,j,k;
	i=lb;
	j=mid+1;
	k=ub;
	while(i<=)
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void insertionsort(int *arr,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	printdata(arr,n);
}
void selectionsort(int *arr,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		int min=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		if(min!=i){
			swap(arr[i],arr[min]);
		}
	}
	printdata(arr,n);
}
void bubblesort(int *arr,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	printdata(arr,n);
}
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF TERMS IN AN ARRAY";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bubblesort(arr,n);
	insertionsort(arr,n);
	selectionsort(arr,n);
	return 0;
}
