#include<iostream>
#include<vector>
using namespace std;

void Addedges(vector <int>*adj_list,int s,int d){
	adj_list[s].push_back(d);
	adj_list[d].push_back(s);
}
void dfs(vector <int> *adj_list,int source,bool *visited)
{
	visited[source]=true;
	cout<<source;
	
	for(auto it = adj_list[source].begin();it!=adj_list[source].end();it++)
	{
		if(!visited[*it])
		{
			dfs(adj_list,*it,visited);
		}
	}
}



int main()
{
	int v,s, d,c;
	cout<<"enter the total no of vertices "<<endl;
	cin>>v;
	vector <int> adj_list[v];
	do{
		cout<<"enter the source and destination"<<endl;
		cin>>s>>d;
		Addedges(adj_list,s,d);
		cout<<"press 1 to add  new edge and 0 to end"<<endl;
		cin>>c;
	}while(c!=0);
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		if(!visited[i]){
			dfs(adj_list,i,visited);
		}
	}
	
}
