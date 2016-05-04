#include <iostream>

using namespace std;

long long int INF = 2147483647 ;
long long int dis[1000] = {0};
long long int lib[1500][1500];

void Relax(long long int u, long long int v)
{
	if(dis[u]+lib[u][v]<dis[v])
		dis[v] = dis[u]+lib[u][v];
}

void BellmanFord(long long int places, long long int cases)
{
	long long int i, j;
	dis[0] = 0;
	for(i=0; i<places; i++)
	{
		for(j=0; j<places; j++)
		{
			if(lib[i][j] != INF)
				Relax(i, j);
		}
	}
}


int main()
{
	long long int cases, places;
	long long int i, j;
	long long int n1, n2, dist; 
	for(i=0; i<1000; i++)
	{
		dis[i] = INF;
	}
	for(i=0; i<1500; i++)
	{
		for(j=0; j<1500; j++)
		{
			lib[i][j] = INF;
		}
	}
	cin >> cases >> places;
	for(i=0; i<cases; i++)
	{
		cin >> n1 >> n2 >> dist;
		lib[n1-1][n2-1] = dist;
		lib[n2-1][n1-1] = dist;
	}
	BellmanFord(places, cases);
	/*for(i=0; i<20; i++)
		cout << dis[i] << " ";
	cout << endl;*/
	cout << dis[places-1] << endl;
}
