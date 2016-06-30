#include <iostream>
#include <cstring>

using namespace std;

int llink[110], rlink[110];
bool used[110];
bool edge[110][110];

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
	int n, m, k;
	int I, x, y;
	while(cin >> n)
	{
		if(n == 0)
			break;
		memset(edge,false,sizeof(edge));
		cin >> m >> k;
		for(int i=0; i<k; ++i)
		{
			cin >> I >> x >> y;
			if(x == 0 || y == 0)
				continue;
			edge[x][y] = true;
		}
		cout << bipartite(n, m) << endl;
	}
	return 0;
}