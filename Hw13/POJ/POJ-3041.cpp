#include <iostream>
#include <cstring>

using namespace std;

int llink[501], rlink[501];
bool used[501];
bool edge[501][501];

bool DFS(int now,int m)
{
	int next;
	for(next=0; next<m; ++next)
	{
		if(used[next] || edge[now][next] == false)
			continue;
		used[next] = true;
		if(rlink[next] == -1 || DFS(rlink[next],m))
		{
			rlink[next] = now;
			llink[now] = next;
			return true;
		}
	}
	return false;
}

int bipartite(int L, int m)
{
	int i, ret=0;
	memset(llink,-1,sizeof(llink));
	memset(rlink,-1,sizeof(rlink));
	for(i=0; i<L; ++i)
	{
		memset(used,false,sizeof(used));
		if(DFS(i,m))
			++ret;
	}
	return ret;
}

int main()
{
	int n, cases;
	cin >> n >> cases;
	int a, b;
	memset(edge, false, sizeof(edge));
	for(int i=0; i<cases; ++i)
	{
		cin >> a >> b;
		edge[a][b]=true;
	}
	cout << bipartite(n+1, n+1) << endl;
}