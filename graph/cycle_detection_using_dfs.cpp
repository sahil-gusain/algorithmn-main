#include<iostream>
#include<vector>

using namespace std;

void Add_edge(vector<int> *adj,int sou,int dest)
{
	adj[sou].push_back(dest);
	adj[dest].push_back(sou);
}
bool check_cycle(int i,int p,bool visited[],vector<int> *adj)
{
	visited[i]=true;
	for(auto it=adj[i].begin();it!=adj[i].end();it++)
	{
		if (visited[*it] == false)
		{
			if(check_cycle(*it,i,visited,adj)) return true;
			
		}else if(*it != p) return true;
	}
	return false;
}
bool iscycle(int n,vector <int> *adj)
{
	bool visited[n];
	for(int i=0;i<n;i++){
	if(!visited[i])
	{
		if(check_cycle(i,-1,visited,adj)) return true;
	}
  }
  return false;
  
}
int main()
{
	int n,ch=1;
	cout<<"enter the total no of vertices"<<endl;
	cin>>n;
	vector<int> adj[n];
	do{
		int sou,dest;
		cout<<"enter the source and destination"<<endl;
		cin>>sou>>dest;
		Add_edge(adj,sou,dest);
		cout<<"press any key to continue and 0 to end"<<endl;
		cin>>ch;
	}while(ch!=0);
	if(iscycle(n,adj)==true) cout<<"cycle detected";
	else cout<<"no cycle detected";
 } 