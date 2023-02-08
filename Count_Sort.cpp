#include<iostream>
using namespace std;

int Find_Max(int arr[],int n)
{
         int  max = arr[0];
         for(int i=1;i<n;i++)
         {
                  if(max<arr[i])
                  {
                    max = arr[i];
                    }
        }
        return max;
}


void CountSort(int arr[],int n)
 {
      int max = Find_Max(arr,n);
      int B[max+1],C[n];
      for(int i=0;i<=max;i++)
      {
            B[i] = 0;      
       }
      for(int i=0;i<n;i++)
      {
          B[arr[i]] = B[arr[i]] +1;
       }   
      for(int i=1;i<=max;i++)
	{
		B[i] = B[i] + B[i-1];
	}
      for(int i=(n-1);i>=0;i--)
	{
		C[B[arr[i]]-1]=arr[i];
		 B[arr[i]]=B[arr[i]]-1;
		}
	for(int i=0;i<n;i++)
	    arr[i]=C[i];
 
}
int main()
{
   int n;
   cout<<"enter the size of the array"<<endl;
   cin>>n;
   int arr[n];
   cout<<"enter the array"<<endl;
   for(int i=0;i<n;i++)
   {
            cin>>arr[i];
      }
   CountSort(arr,n);
   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
      }
}


