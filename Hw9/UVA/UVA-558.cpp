#include <iostream>

using namespace std;

struct node{
	int A;
	int B;
	int dist;
}place[11000];
long long int INF = 2140000000 ;
long long int dis[11000];

bool cover = false;
void Relax(node n)
{
	if(dis[n.A]+n.dist<dis[n.B])
		dis[n.B] = dis[n.A] + n.dist;
}

void BellmanFord(long long int places, long long int lines, node *n)
{
	long long int i, j;
	dis[places] = 0;
	for(i=1; i<places; ++i)
	{
		for(j=0; j<lines; ++j)
		{
			Relax(n[j]);
		}
	}
	for(i=0; i<lines; ++i)
	{
		if(dis[place[i].A]+place[i].dist<dis[place[i].B])
		{
			cout << "possible" << endl;
			return;
		}
	}
	cout << "not possible" << endl;
}

int main()
{
	long long int places, lines, worms;
	long long int i, j;
	long long int n1, n2, dist; 
	int count, cases;
	cin >> cases;
	for(count=0; count < cases; ++count)
	{
		for(i=0; i<11000; ++i)
		{
			dis[i] = INF;
		}
		cin >> places >> lines;
		for(i=0; i<lines; ++i)
		{
			cin >> place[i].A >> place[i].B >> place[i].dist;
		}
		BellmanFord(places, lines, place);
	}
}
