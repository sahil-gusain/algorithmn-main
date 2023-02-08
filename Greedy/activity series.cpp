#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(vector<int> t1,vector <int> t2)
{
	if(t1[1] == t2[1]){
		 return t1[0]< t2[0];
		}
		return t1[1]<t2[1];
}
int main()
{
	int n,c=1;
	cout<<"enter the no of activities"<<endl;
	cin>>n;
	vector<vector<int>> activity;
	for(int i=0;i<n;i++)
	{
		int start_time,finish_time;
		cout<<"enter the starting and finish time of activity "<<i<<endl;
		cin>>start_time>>finish_time;
		activity.push_back({start_time,finish_time}); 
	}
	sort(activity.begin(),activity.end(),compare);
	int previous_finish_time = activity[0][1];
	for(int i=1;i<n;i++)
	{
		if(activity[i][0] >= previous_finish_time){
			c++;
			previous_finish_time = activity[i][1];
		}
	}
	cout<<"Total no activity that can be done "<<c;
}