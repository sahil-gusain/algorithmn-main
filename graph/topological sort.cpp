#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector <int> *adj_list,int source,stack <int> &Stack,bool *vis)
{
	vis[source]=true;
	
	for(auto it = adj_list[source].begin();it!=adj_list[source].end();it++)
	{
		if(!vis[*it])
		{
			dfs(adj_list,*it,Stack,vis);
		}
	}
	Stack.push(source);
}
void toplogical_sort(vector <int> *adj_list,int v)
{
	bool vis[v];
	stack<int> Stack;
	
	for(int i=0;i<v;i++)
	{
		if(!vis[i]){
			dfs(adj_list,i,Stack,vis);
		}
	}
	while(!Stack.empty())
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}
 void add_edge(vector <int> *adj_list,int s,int c)
 {
 	adj_list[s].push_back(c);
 }
int main()
{
	int v,s,d,c=1;
	cout<<"enter the total no of vertices  "<<endl;
	cin>>v;
	vector <int> adj_list[v];
	do{
		cout<<"enter the source and the destination"<<endl;
		cin>>s>>d;
		add_edge(adj_list,s,d);
		cout<<"press 1 to add new edge and 0 to end "<<endl;
		cin>>c;
	}while(c!=0);
	toplogical_sort(adj_list,v);
	
}
