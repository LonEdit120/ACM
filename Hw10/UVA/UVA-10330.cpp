#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 200000000
using namespace std;

int flow[205][205];
int cap[205][205];
bool v[205];
int pa[205];
int nodes, cases;
int B,D;
int m,n;
int temp;
int fuckingshit;
bool DFS(int cur, int t, int n)
{
	v[cur] = true;
	if(cur == t)
		return true;
	for(int i = 0; i<=n; ++i)
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
int FindFlow(int s, int t)
{
	int pre;
	int f = INF;
	for(int i=t; i!=s; i=pa[i])
	{
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i]>0)
			f = min(f, cap[pre][i] - flow[pre][i]);
		else
			f= min(f, flow[i][pre]);
	}
	for(int i=t; i!=s; i=pa[i])
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
		memset(v,false,sizeof(v));
		if(!DFS(0,(n<<1)+1,(n<<1)+2))
			break;
		ret += FindFlow(0,(n<<1)+1);
	}
	return ret;
}

int main()
{
	while(scanf("%d",&nodes) != EOF)
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		for(int i=1; i<=nodes; ++i)
		{
			scanf("%d",&cap[i][nodes+i]);
		}
		scanf("%d",&cases);
		for(int i=0; i<cases; ++i)
		{
			/*scanf("%d%d",&m,&n);
			scanf("%d",&cap[nodes+m][n]);*/
			scanf("%d%d%d", &m, &n, &fuckingshit);
			cap[m + nodes][n] = fuckingshit;
		}
		scanf("%d%d",&B,&D);
		while(B--)
		{
			scanf("%d",&temp);
			cap[0][temp] = INF;
		}
		while(D--)
		{
			scanf("%d",&temp);
			cap[temp+nodes][(nodes<<1)+1] = INF;
		}
		printf("%d\n",FordFulkerson(nodes));
	}
	return 0;
}