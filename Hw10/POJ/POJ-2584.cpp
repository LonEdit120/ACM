#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define INF 200000000
using namespace std;

int flow[40][40];
int cap[40][40];
bool v[40];
int pa[40];

int nodes; 	
int a,b,temp;
enum size{S=1,M,L,X,T};

int charToInt(char c)
{
	switch(c)
	{
		case 'S':
			return S;
			break;
		case 'M':
			return M;
			break;
		case 'L':
			return L;
			break;
		case 'X':
			return X;
			break;
		case 'T':
			return T;
			break;
	}
	return 0;
}

bool DFS(int cur, int t, int n)
{
	int i;
	v[cur] = true;
	if(cur == t)
		return true;
	for(i = 0; i<n; i++)
	{
		if(v[i])
			continue;
		if(cap[cur][i] - flow[cur][i] > 0)
		{
			pa[i] = cur;
			if(DFS(i, t, n))
				return true;
		}
	}
	return false;
}

int FindFlow(int cur, int t)
{
	int i, pre;
	int f = INF;
	for(i=t; i!=cur; i=pa[i])
	{
		pre = pa[i];
		f = min(f, cap[pre][i] - flow[pre][i]);
	}
	for(i=t; i!=cur; i=pa[i])
	{
		pre = pa[i];
		flow[pre][i] += f;
		flow[i][pre] -= f;
	}
	return f;
}

int FordFulkerson(int nodes)
{
	int ret = 0;
	while(1)
	{
		memset(v,false,sizeof(v));
		if(!DFS(0,nodes+6,nodes+7))
			break;
		ret += FindFlow(0,nodes+6);
	}
	return ret;
}

int main()
{
	string str;
	while(cin >> str && str != "ENDOFINPUT")
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		cin >> nodes;
		for(int i = 1; i <= nodes; ++i)
		{
			cap[0][i] = 1;
			cin >> str;
			for(int j = charToInt(str[0]); j <= charToInt(str[1]); ++j)
			{
				cap[i][nodes+j] = 1;
			}
		}

		for(int i = 1; i <= 5; ++i)
		{
			cin >> temp;
			cap[nodes + i][nodes + 6] = temp;
		}
		cin >> str;
		if(FordFulkerson(nodes)-nodes == 0)
			cout << "T-shirts rock!" << endl;
		else
			cout << "I'd rather not wear a shirt anyway..." << endl;
	}
	return 0;
}