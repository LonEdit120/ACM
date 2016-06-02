#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 200000000
using namespace std;

int flow[205][205] = {{0}};
int cap[205][205] = {{0}};
int v[205];
int pa[205];

int nodes;
int cnt = 0;
int s, t, c;
int a,b,temp;
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
		if(!DFS(s,t,c))
			break;
		ret += FindFlow(s,t,n);
	}
	return ret;
}

int main()
{
	int i;
	while(1)
	{
		++cnt;
		cin >> nodes;
		if(nodes == 0)
			break;
		cin >> s >> t >> c;
		for(int i = 0;i < c;++i)
		{
			cin >> a >> b >> temp;
			cap[a][b] += temp;
			cap[b][a] += temp;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", cnt, FordFulkerson(nodes));
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
	}
}