#include<bits/stdc++.h>
using namespace std;

map< vector < vector <int> > , bool> visited;
vector< vector <int> >goal_state(3,vector<int>(3));

void printMatrix(vector < vector <int> >a)
{
	cout<<"\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n";
}

bool isGoal(vector< vector<int> >a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!=goal_state[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

vector< vector < vector <int> > > neighbour(vector <vector <int> >a)
{
	int posi,posj;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==0)
			{
				posi=i;
				posj=j;
				break;
			}
		}
	}
	
	vector< vector <vector <int> > >ans;
	
	vector< vector <int> >n=a;
	
	if(posj>=1)
	{
		int newi=posi;
		int newj=posj-1;
		swap(n[posi][posj],n[newi][newj]);
		ans.push_back(n);
	}
	
	n=a;
	
	if(posj<=1)
	{
		int newi=posi;
		int newj=posj+1;
		swap(n[posi][posj],n[newi][newj]);
		ans.push_back(n);
	}
	
	n=a;
	
	if(posi>=1)
	{
		int newi=posi-1;
		int newj=posj;
		swap(n[posi][posj],n[newi][newj]);
		ans.push_back(n);
	}
	
	n=a;
	
	if(posi<=1)
	{
		int newi=posi+1;
		int newj=posj;
		swap(n[posi][posj],n[newi][newj]);
		ans.push_back(n);
	}
	
	return ans;
}

int heuristic(vector< vector <int> >a,int depth)
{
	int cost=depth;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j] != goal_state[i][j])
			{
				cost++;
			}
		}
	}
	return cost;
}

void solve(vector< vector <int> >a,int moves)
{
	printMatrix(a);
	if(isGoal(a))
	{
		cout<<"Done\n";
		return;
	}
	
	visited[a]=true;
	
	vector< vector <int> >test;
	vector< vector < vector <int> > > ns=neighbour(a);
	vector< vector <vector <int> > > :: iterator it;
	int mincost=INT_MAX;
	
	for(it=ns.begin();it!=ns.end();it++)
	{
		vector< vector <int> >temp=*it;
		if(!visited[temp])
		{
			int cost=heuristic(temp,moves);
			if(cost < mincost)
			{
				mincost=cost;
				test=temp;
			}
		}
	}
	solve(test,moves+1);
}

int main()
{
	vector< vector <int> >start_state(3,vector<int>(3));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>start_state[i][j];
		}
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>goal_state[i][j];
		}
	}
	
	solve(start_state,0);
}


//1 2 3
//0 4 6
//7 5 8
//
//
//1 2 3
//4 5 6
//7 8 0




//2 8 3
//1 6 4
//7 0 5
//
//
//1 2 3
//8 0 4
//7 6 5

