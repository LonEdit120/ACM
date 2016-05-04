#include <iostream>

using namespace std;

long long int INF = 2147483647 ;
long long int dis[1500] = {0};
long long int lib[1500][1500];

void Relax(long long int u, long long int v)
{
	if(dis[u]+lib[u][v]<dis[v])
		dis[v] = dis[u]+lib[u][v];
}

void BellmanFord(long long int places, long long int cases)
{
	long long int i, j, gan87;
	dis[places] = 0;
	for(i=places; i>=1; i--)
	{
		for(j=places; j>=1; j--)
		{
			if(i!=j)
				Relax(i, j);
		}
	}
}


int main()
{
	long long int cases, places;
	long long int i, j;
	long long int n1, n2, dist; 
	for(i=0; i<1500; i++)
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
		lib[n1][n2] = dist;
		lib[n2][n1] = dist;
	}
	BellmanFord(places, cases);
	/*for(i=1; i<=places; i++)
		cout << dis[i] << " ";
	cout << endl;*/
	cout << dis[1] << endl;
}
