#include <iostream>

using namespace std;

struct node{
	int A;
	int B;
}place[10010];

long long int INF = 2140000000 ;
int dis[10010];
long long int Min = 0;
long long int finish;

void BellmanFord(long long int places, long long int cases, int n)
{
	long long int i, j;
	dis[places] = 0;
	for(i=1; i<n; i++)
	{
		for(j=0; j<cases; j++)
		{
			if(dis[place[j].A]-1<dis[place[j].B] && dis[place[j].A] != INF)
				dis[place[j].B] = dis[place[j].A]-1;
		}
	}
}

int main()
{
	long long int starting;
	long long int i, j, n;
	long long int a, b;
	long long int n1, n2, dist; 
	long long int count = 0;
	int case_count= 0;
	while(cin >> n)
	{
		count++;
		if(n == 0)
			break;
		for(i=0; i<10010; i++)
		{
			dis[i] = INF;
		}
		cin >> starting;
		while(1)
		{
			cin >> a >> b;
			if(a==0 && b==0)
				break;
			place[case_count].A = a;
			place[case_count].B = b;
			case_count++;
		}
		BellmanFord(starting, case_count, n);
		for(i=1; i<=n; ++i)
		{
			if(dis[i] < Min)
			{
				Min = dis[i];
				finish = i;
			}
		}
		cout << "Case " << count << ": The longest path from " 
		<< starting << " has length " << -Min << ", finishing at " 
		<< finish << "." << endl << endl;
		Min = 0;
		case_count = 0;
	}
}
