#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int vertex,edges;
	cin>>vertex;
	vector< pair<int,int> > arr[vertex];
	
	cin>>edges;
	while(edges--)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		
		arr[u].push_back(make_pair(v,wt));
		arr[v].push_back(make_pair(u,wt));
	}
	
	int source[vertex];
	int dist[vertex];
	bool inMST[vertex];
	
	for(int i=0;i<vertex;i++)
	{
		source[i]=-1;
		dist[i]=INT_MAX;
		inMST[i]=false;
	}
	
	source[0]=0;
	dist[0]=0;
	
	for(int i=1;i<vertex;i++)
	{
		int mini=INT_MAX;
		int u;
		
		for(int j=0;j<vertex;j++)
		{
			if(!inMST[j] && dist[j]<mini)
			{
				mini=dist[j];
				u=j;
			}
		}
		
		inMST[u]=true;
		
		for(int j=0;j<arr[u].size();j++)
		{
			int v=arr[u][j].first;
			int wt=arr[u][j].second;
			
			if(!inMST[v] && wt<dist[v])
			{
				dist[v]=wt;
				source[v]=u;
			}
		}
	}
	
	for(int i=1;i<vertex;i++)
	{
		cout<<"Edge between "<<i<<" and "<<source[i]<<"\n";
	}
	return 0;
}





