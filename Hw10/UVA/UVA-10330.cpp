#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 200000000
using namespace std;

int flow[205][205] = {{0}};
int cap[205][205] = {{0}};
int v[205] = {0};
int pa[205] = {0};
bool DFS(int cur, int t, int n)
{
	int i;
	v[cur] = 1;
	if(cur == t)
		return true;
	for(i = 0; i<=n; i++)
	{
		if(v[i])
			continue;
		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0)
		{
			pa[i] = cur;
			if(DFS(i, t, n))
				return true;
		}
	}
	return false;
}

int FindFlow(int s, int t, int n)
{
	int i, pre;
	int f = INF;
	for(i=t; i!=s; i=pa[i])
	{
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i]>0)
			f = min(f, cap[pre][i] - flow[pre][i]);
		else
			f= min(f, flow[i][pre]);
	}
	for(i=t; i!=s; i=pa[i])
	{
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i]>0)
			flow[pre][i] += f;
		else
			flow[i][pre] -= f;
	}
	return f;
}

int FordFulkerson(int n)
{
	int ret = 0;
	while(1)
	{
		memset(v,0,sizeof(v));
		if(!DFS(0,n,n))
			break;
		ret += FindFlow(0,n,n);
	}
	return ret;
}

int main()
{
	int nodes, cases;
	int i, j;
	int B,D;
	int m,n;
	int temp;
	while(cin >> nodes)
	{
		for(i=1; i<=nodes; i++)
		{
			cin >> cap[i][nodes+i];
		}
		cin >> cases;
		for(i=0; i<cases; i++)
		{
			cin >> m >> n;
			cin >> cap[nodes+m][n];
		}
		cin >> B >> D;
		for(i=0; i<B; i++)
		{
			cin >> temp;
			cap[0][temp] = INF;
		}
		for(i=0; i<D; i++)
		{
			cin >> temp;
			cap[temp][nodes*2+1] = INF;
		}
		cout << FordFulkerson(nodes*2+1) << endl;
		for(i=0; i<205; i++)
		{
			for(j=0; j<205; j++)
			{
				cap[i][j] = 0;
				flow[i][j] = 0;
			}
			v[i] = 0;
			pa[i] = 0;
		}
	}
}