#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int knapsack(vector<vector<int>> &items,int w,int n,vector<vector<int>> &t )
{
	if(w==0 || n==0)
	return t[n][w]=0;
	
	if(t[n][w]!=-1)
	return t[n][w];
	
	if(items[n - 1][0]<=w)
	return t[n][w] = max(items[n-1][1] + knapsack(items,w-items[n-1][0],n-1,t),knapsack(items,w,n-1,t));
	
	
	return t[n][w] = knapsack(items,w,n-1,t);
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
        vector<vector<int>> t(n + 1,vector<int>(w + 1,-1));
	cout<<"max profit "<<knapsack(item,w,n,t);
}
