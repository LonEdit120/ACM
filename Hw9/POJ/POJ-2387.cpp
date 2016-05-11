#include <iostream>

using namespace std;

struct node{
	int A;
	int B;
	int dist;
}place[2000];

long long int INF = 2140000000 ;
long long int dis[2020];
//long long int lib[2020][2020];

void Relax(node n)
{
	/*if(dis[u]+lib[u][v]<dis[v])
		dis[v] = dis[u]+lib[u][v];*/
	if(dis[n.A]+n.dist<dis[n.B])
		dis[n.B] = dis[n.A] + n.dist;
	if(dis[n.B]+n.dist<dis[n.A])
		dis[n.A] = dis[n.B] + n.dist;
}

void BellmanFord(long long int places, long long int cases, node *n)
{
	long long int i, j;
	dis[places] = 0;
	for(i=1; i<places; i++)
	{
		for(j=0; j<cases; j++)
		{
			Relax(n[j]);
		}
	}
}


int main()
{
	long long int cases, places;
	long long int i, j;
	long long int n1, n2, dist; 
	for(i=0; i<2020; i++)
	{
		dis[i] = INF;
	}
	/*for(i=0; i<2020; i++)
	{
		for(j=0; j<2020; j++)
		{
			lib[i][j] = INF;
		}
	}*/
	cin >> cases >> places;
	for(i=0; i<cases; i++)
	{
		cin >> place[i].A >> place[i].B >> place[i].dist;
		/*lib[n1][n2] = dist;
		lib[n2][n1] = dist;*/
	}
	BellmanFord(places, cases, place);
	/*for(i=0; i<20; i++)
		cout << dis[i] << " ";
	cout << endl;*/
	//cout << dis[places-1] << endl;
	cout << dis[1] << endl;
	/*for(i=0; i<=places; ++i)
		cout << dis[i] << endl;*/
}
