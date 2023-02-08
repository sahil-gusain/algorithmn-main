#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int knapsack(vector<vector<int>> &items,int w,int n)
{
	if(w==0 || n==0)
	return 0;
	
	if(items[n-1][0]<=w)
	return max(items[n-1][1] + knapsack(items,w-items[n-1][0],n-1),knapsack(items,w,n-1));
	
	
	return knapsack(items,w,n-1);
}

int main()
{
	int n,wt,val,w;
	cout<<"enter the total no of element "<<endl;
	cin>>n;
	vector<vector<int>> item;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		cout<<"enter weight and value of item "<<i+1<<endl;
		cin>>wt>>val;
		temp = {wt,val};
		item.push_back(temp);
	}
	cout<<"enter the maximum weight of knapsack"<<endl;
	cin>>w;
	cout<<"max profit "<<knapsack(item,w,n);
}