#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int low[100];
int dfn[100];
int cnt_dfn, ans;

vector<int> graph[100];

void dfs(int p, int n)
{
	bool cut_vertex = false;
	int child = 0;
	low[n] = dfn[n] = ++cnt_dfn;
	for(int i=0; i<graph[n].size(); ++i)
	{
		if(!dfn[graph[n][i]])
		{
			dfs(n,graph[n][i]);
			low[n] = min(low[n],low[graph[n][i]]);
			if(low[graph[n][i]] >= dfn[n])
			{
				cut_vertex = true;
			}
			++child;
		}
		else if(graph[n][i] != p)
		{
			low[n] = min(low[n],dfn[graph[n][i]]);
		}
	}
	if((child > 1 || p != -1) && cut_vertex)
	{
		++ans;
	}
}

int main()
{
	int places, index, temp;
	string s;
	while(cin >> places)
	{
		if(places == 0)
			break;
		for(int i = 0;i <= places;++i)
		{
			graph[i].clear();
			low[i] = 0;
			dfn[i] = 0;
		}
		cnt_dfn = 1;
		while(1)
		{
			getline(cin, s);
			if(s == "")
				continue;
			//getchar();
			stringstream str(s);
			str >> index;
			if(index == 0)
				break;
			while(str >> temp)
			{
				graph[index].push_back(temp);
				graph[temp].push_back(index);
			}
		}
		ans = 0;
		dfs(-1, 1);
		cout << ans << endl;
	}
}