#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int knapsack(vector<vector<int>> items, int w,int n)
{
	vector<vector<int>> t(n + 1,vector<int>(w + 1));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0 || j==0)
			 t[i][j] = 0;
			else if(items[i - 1][0] <= j)
			 t[i][j] = max(items[i-1][1] + t[i-1][j- items[i - 1][0]],t[i-1][j]);
			else
			 t[i][j] = t[i-1][j];
		}
	}
	return t[n][w];
}

int main()
{
	int n,wt,v,w;
	cout<<"enter the total no of element "<<endl;
	cin>>n;
	vector<vector<int>> items;
	
	for(int i=0;i<n;i++)
	{	
	   vector <int> temp;
		cout<<"enter weight and value of item "<<i+1<<endl;
		cin>>wt>>v;
		temp ={wt,v};
		items.push_back(temp);
	}
	cout<<"enter the maximum weight of knapsack"<<endl;
	cin>>w;
	
	cout<<"max profit "<<knapsack(items,w,n);
	return 0;
}