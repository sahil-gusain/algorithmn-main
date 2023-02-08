#include<iostream>
using namespace std;

int comp=0;
int Partion(int A[],int low,int high)
{
	int x=A[high];//pivot element
	int i=low-1;
	for(int j=low;j<=high-1;j++)
	{
		if(A[j]<=x)
		{
			comp = comp+1;			
			i=i+1;
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}	
	}
	i=i+1;
	int temp = A[high];
	A[high] = A[i];
	A[i] = temp;
	return i;
}
void QuickSort(int A[],int low,int high)
{
  if(low>high)
  return ;
  int index = Partion(A,low,high);
  QuickSort(A,low,index-1);
  QuickSort(A,index+1,high);
}

int main()
{
  int n;
  cout<<"enter the size of array"<<endl;
  cin>>n;
  int arr[n];
  cout<<"enter the array"<<endl;
  for(int i=0;i<n;i++)
  {
     cin>>arr[i];
   }
  QuickSort(arr,0,n-1);
  cout<<"sorted array is"<<endl; 
  for(int i=0;i<n;i++)
  {
     cout<<arr[i]<<" ";
   }
	cout<<endl;
   cout<<"total no of comparisons in quicksort are "<<comp;
}
