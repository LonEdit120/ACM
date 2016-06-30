#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define MAX 3000

bool visited[MAX];
int dfn[MAX], low[MAX];
int cnt_dfn, anscnt;
vector<int> path[MAX];
vector<int> stk;

void tarjan(int n);
void init(int n);

int main()
{
	int n, calls, type, a, b;
	while(cin >> n >> calls && (n && calls))
	{
		init(n);
		for(int i = 0;i < calls;++i)
		{
			cin >> a >> b >> type;
			path[a].push_back(b);
			if(type == 2)
				path[b].push_back(a);
		}
		for(int i = 1;i <= n && anscnt < 2;++i)
		{
			if(!dfn[i])
				tarjan(i);
		}
		if(anscnt == 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}

void init(int n)
{
	for(int i = 0;i <= n;++i)
	{
		visited[i] = false;
		dfn[i] = 0;
		low[i] = 0;
		path[i].clear();
	}
	cnt_dfn = 0;
	anscnt = 0;
	stk.clear();
	return;
}

void tarjan(int n)
{
	low[n] = dfn[n] = ++cnt_dfn;
	stk.push_back(n);
	visited[n] = true;
	for(int &i:path[n])
	{
		if(!dfn[i])
		{
			tarjan(i);
			low[n] = low[n] < low[i] ? low[n] : low[i];
		}
		else if(visited[i])
			low[n] = low[n] < dfn[i] ? low[n] : dfn[i];
	}
	if(dfn[n] == low[n])
	{
		int groupmember;
		while(1)
		{
			groupmember = stk.back();
			visited[groupmember] = false;
			stk.pop_back();
			if(groupmember == n) break;
		}
		++anscnt;
	}
}