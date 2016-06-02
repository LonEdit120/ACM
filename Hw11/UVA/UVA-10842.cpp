#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int total = 0;

int s[1000000];

struct L
{
	int a;//No.
	int b;//No.
	int dist;
}length[1000000];

void Clean()
{
	int i;
	for(i=0; i<1000000; i++)
	{
		s[i] = i;
	}
}
int Find(int x)
{
	return (s[x] == x) ?(x) :(s[x]=Find(s[x]));
}
void Union(int x, int y)
{
	s[Find(x)] = Find(y);
}


bool cmp(L a, L b)
{
	return a.dist>b.dist;
}

int main()
{
	int cases;
	int points;
	int i, j;
	int cnt = 0;
	cin >> cases;
	for(i=0; i<cases; ++i)
	{
		Clean();
		total = 0;
		cin >> cnt >> points;
		for(j=0; j<points; ++j)
		{
			cin >> length[j].a >> length[j].b >> length[j].dist;
		}
		sort(length, length+points,cmp);
		for(j=0; j<points; ++j)
		{
			if(Find(length[j].a) != Find(length[j].b))
			{
				Union(length[j].a,length[j].b);
				total = length[j].dist;
			}
		}

		printf("Case #%d: %d\n",i+1,total);
		//initializer---------------------
	}
}