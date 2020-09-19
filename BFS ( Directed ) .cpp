#include<bits/stdc++.h> 
using namespace std; 
#define deb(x) cout <<"\n"<< (#x) << " = " << (x) << "\n"
const long long  INF = 1e18;
const long long mod=998244353 ;
void inputoutput()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	    
}


vector<int> adj[100500];
vector<bool> vis(100500);
vector<int> d(100500);
queue<int> q ;

void bfs(int v)
{
	q.push(v);
	vis[v]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto u : adj[x])
		{
			if(!vis[u])
			{
				vis[u]=true;
				q.push(u);
				d[u] = d[x] + 1;
			}
		}
	}
}
void dfs(int v)
{
	vis[v]=true;
	for(auto u : adj[v])
	{
		if(!vis[u])
			dfs(u);
	}
}

void solve()
{
	int n,m,v;
	cin>>n>>m>>v ;

	for(int i=0  ; i<m ; ++i)
	{
		int a,b ;
		cin>>a>>b;
		adj[a].push_back(b);
	}

	bfs(v);

	for(int i=1 ; i<=n ; ++i)
	{	
		if(vis[i])
			cout<<d[i]<<" ";
		else
			cout<<"-1 ";
	}


}

int main()
{ 
	inputoutput() ;
	
	solve();

	return 0;
}
