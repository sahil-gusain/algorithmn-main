#include<iostream>
using namespace std;

int JumpSearch(int arr[],int low,int high,int key)
{
	int m;
    cout<<"enter the jump"<<endl;
    cin>>m;
    int i=0;
    while(i<high)
    {
    	if(arr[i]<key)
    	i=i+key;
    	else
    	{
    		int n=i;
    		i=i-m;
    		for(;i<=n;i++)
    		{
    			if(arr[i]==key)
    			{
    				return i;
				}
			}
    	}
    	
	}
	i=i-m;
	for(;i<high;i++)
    {
	
    	if(arr[i]==key)
    	{
        	return i;
		}
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
	flag=JumpSearch(arr,0,n,key);
	if(flag==-1)
	cout<<"element is not present"<<endl;
	else
	cout<<"element is present at "<<flag<<" index"<<endl;
}
