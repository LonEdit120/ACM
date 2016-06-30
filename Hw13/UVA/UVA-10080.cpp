#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int llink[110], rlink[110];
bool used[110];
bool edge[110][110];

struct point
{
	double x;
	double y;
}mouse[110], hole[110];

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
	int n, m, s, v;
	while(cin >> n >> m >> s >> v)
	{
		for(int i=0; i<n; ++i)
			cin >> mouse[i].x >> mouse[i].y;
		for(int i=0; i<m; ++i)
			cin >> hole[i].x >> hole[i].y;
		for(int i=0; i<n; ++i)
		{
			for(int j=0;j<m;++j)
			{
				double dis = sqrt(pow((hole[j].x-mouse[i].x),2) + pow((hole[j].y-mouse[i].y),2));
				if(dis/v <= s)
					edge[i][j] = true;
				else
					edge[i][j] = false;
			}
		}
		cout << n - bipartite(n,m) << endl;
	}
}