#include <iostream>
#include <vector>

using namespace std;

int root[100010];
vector<int> v[100010];
vector<int>::iterator it;

void Clean(int n)
{
	for(int i = 1; i<=n; ++i)
	{
		root[i] = i;
		v[i].clear();
		v[i].push_back(i);
	}
}

void Union(int a, int b)
{
	int m = root[a];
	int n = root[b];
	int small, big;
	if(m == n)
		return;
	if(v[m].size() < v[n].size())
	{
		small = m;
		big = n;
	}
	else
	{
		small = n;
		big = m;
	}
	for(it = v[small].begin(); it != v[small].end(); ++it)
	{
		v[big].push_back(*it);
		root[*it] = big;
	}
	v[small].clear();
}

void Move(int a, int b)
{
	int m = root[a];
	int n = root[b];
	for(it = v[m].begin(); (*it) != a; ++it);
	v[m].erase(it);
	root[a] = n;
	v[n].push_back(a);

}

int main()
{
	int nodes, cases, type;
	int a, b;
	int cnt;
	int ans;
	while(cin >> nodes >> cases)
	{
		Clean(nodes);
		for(int i=0; i<cases; ++i)
		{
			cin >> type;
			switch(type)
			{
				case 1:
					cin >> a >> b;
					Union(a,b);
					break;
				case 2:
					cin >> a >> b;
					Move(a,b);
					break;
				case 3:
					cin >> a;
					cnt = 0;
					ans = 0;
					for(it = v[root[a]].begin(); it != v[root[a]].end(); ++it)
					{
						++cnt;
						ans += (*it);
					}
					cout << cnt << " " << ans << endl;
					break;
			}
		}
	}
}