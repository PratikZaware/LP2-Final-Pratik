#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(vector<int>arr[],int vertex,bool visited[])
{
	visited[vertex]=true;
	cout<<"Visit "<<vertex<<"\n";
	
	for(int i=0;i<arr[vertex].size();i++)
	{
		int v=arr[vertex][i];
		if(!visited[v])
		{
			dfs(arr,v,visited);
		}
	}
}


void bfs(vector<int> arr[],int vertex, bool visited[])
{
	cout<<"Visit "<<vertex<<"\n";
	queue<int>que;
	visited[vertex]=true;
	que.push(vertex);
	
	while(!que.empty())
	{
		int top=que.front();
		que.pop();
		
		for(int i=0;i<arr[top].size();i++)
		{
			int v=arr[top][i];
			
			if(!visited[v])
			{
				cout<<"Visit "<<v<<"\n";
				visited[v]=true;
				que.push(v);
			}
		}
	}
}

int main()
{
	int vertex;
	int edges;
	cin>>vertex;
	
	vector<int> arr[vertex];
	cin>>edges;
	while(edges--)
	{
		int u,v;
		cin>>u>>v;
		
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	
	bool visited[vertex];
	for(int i=0;i<vertex;i++)
	{
		visited[i]=false;
	}
	dfs(arr,0,visited);

//	bfs(arr,0,visited);
 	return 0;
}





