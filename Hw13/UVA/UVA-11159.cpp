#include <iostream>
#include <cstring>

using namespace std;

int llink[110], rlink[110];
bool used[110];
bool edge[110][110];
int first[110], second[110];

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
	int cases, n, m;
	cin >> cases;
	for(int k=1;k <= cases; k++)
	{
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> first[i];
		cin >> m;
		for(int i=0; i<m; ++i)
			cin >> second[i];
		for(int i=0; i<n; ++i)
		{
			for(int j=0;j<m;++j)
			{
				if(first[i]==0 && second[j]==0 || first[i]!=0 && second[j] % first[i] == 0)
					edge[i][j]=true;
				else 
					edge[i][j]=false;
			}
		}
		cout << "Case " << k << ": " << bipartite(n,m) << endl;
	}
}