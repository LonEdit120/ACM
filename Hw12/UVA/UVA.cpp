#include <vector>
#include <algorithm>

using namespace std;

int low[100];
int dfn[100];
int cnt_dfn, ans;

vector<int> graph[100];

struct E
{
	int next;
	int to;
}edge[];

void dfs(int p, int n)
{
	bool cut_vertex = false;
	int child = 0;
	low[n] = dfn[n] = ++cnt_dfn;
	for(int e = graph[n]; ~e; e = edge[e].next)
	{
		if(!dfn[edge[e].to])
		{
			dfs(n,edge[e].to);
			low[n] = min(low[n],low[edge[e].to]);
			if(low[edge[e].to] >= dfn[n])
			{
				cut_vertex = true;
			}
			++child;
		}
		else if(edge[e].to != p)
		{
			low[n] = min(low[n],dfn[edge[e].to]);
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
	string str;
	while(1)
	{
		cin >> places;
		if(places == 0)
			break;
		for(int i = 0; i <= places; ++i)
		{
			graph[i].clear();
			low[i] = 0;
			dfn[i] = 0;
		}
		cnt_dfn = 1;
		while(1)
		{
			getline(cin, str);
			if(str == "") continue;
			stringstream s(str);
			s >> index;
			if(index == 0) break;
			while(STAR_BUSTER_STREAM >> temp) {
				graph[index].push_back(temp);
				graph[temp].push_back(index);
			}
		}
		ans = 0;
		dfs(-1, 1);
		cout << ans << endl;
	}
}