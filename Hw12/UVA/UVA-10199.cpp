#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

int low[110];
int dfn[110];
int cnt_dfn, ans;

vector<string> graph[110];
vector<string> temp;
map<string, int> m1;
map<int, string> m2;

void dfs(int p, int n)
{
	bool cut_vertex = false;
	int child = 0;
	low[n] = dfn[n] = ++cnt_dfn;
	for(int i=0; i<graph[n].size(); ++i)
	{
		if(!dfn[m1[graph[n][i]]])
		{
			dfs(n,m1[graph[n][i]]);
			low[n] = min(low[n],low[m1[graph[n][i]]]);
			if(low[m1[graph[n][i]]] >= dfn[n])
			{
				cut_vertex = true;
			}
			++child;
		}
		else if(m1[graph[n][i]] != p)
		{
			low[n] = min(low[n],dfn[m1[graph[n][i]]]);
		}
	}
	if((child > 1 || p != -1) && cut_vertex)
	{
		temp.push_back(m2[n]);
	}
}

int main()
{
	int nodes, road, cnt;
	cnt = 0;
	string s1, s2;
	while(cin >> nodes)
	{
		if(nodes == 0)
			break;
		m1.clear();
		m2.clear();
		ans = 1;
		for(int i=0; i <= nodes; ++i)
		{
			graph[i].clear();
			low[i] = 0;
			dfn[i] = 0;
		}
		cnt_dfn = 1;
		for(int i=0; i < nodes; ++i)
		{
			cin >> s1;
			m1[s1] = ans;
			m2[ans++] = s1;
		}
		cin >> road;
		for(int i=0; i<road; ++i)
		{
			cin >> s1 >> s2;
			graph[m1[s1]].push_back(s2);
			graph[m1[s2]].push_back(s1);
		}
		temp.clear();
		for(int i=0; i<nodes; ++i)
		{
			if(!dfn[i])
				dfs(-1, i);
		}
		if(cnt)
			cout << endl;
		++cnt;
		cout << "City map #" << cnt << ": " << temp.size() << " camera(s) found" << endl;
		sort(temp.begin(), temp.end());
		for(string &s:temp)
		{
			cout << s << endl;
		}
	}
}