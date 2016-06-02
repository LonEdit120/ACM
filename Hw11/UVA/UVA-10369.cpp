#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

float total = 0;

int s[250001];

vector<float> v;
struct P
{
	int No;
	float x;
	float y;
}point[501];

struct L
{
	int a;
	int b;
	float dist;
}length[250000];

void Clean()
{
	int i;
	for(i=0; i<250001; i++)
	{
		s[i] = i;
	}
}
int Find(int x)
{
	return (s[x] == x) ?(x) :(s[x]=Find(s[x]));
}
int Union(int x, int y)
{
	s[Find(x)] = Find(y);
}

float Bis(int i, int j)
{
	float ans = sqrt(pow(point[i].x-point[j].x,2)+pow(point[i].y-point[j].y,2));
	return ans;
}

bool cmp(L a, L b)
{
	return a.dist<b.dist;
}

bool compare(int x, int y)
{
	if(s[x] == y || s[y] == x)
		return false;
	else
		return true;
}

int main()
{
	int cases;
	int points;
	int i, j, k;
	int cnt = 0;
	int S;
	cin >> cases;
	for(i=0; i<cases; ++i)
	{
		Clean();
		cin >> S >> points;
		for(j=1; j<=points; ++j)
		{
			cin >> point[j].x >> point[j].y;
			point[j].No = j;
		}
		for(j=1; j<=points; ++j)
		{
			for(k=j+1; k<=points; ++k)
			{
				length[cnt].a = point[j].No;
				length[cnt].b = point[k].No;
				length[cnt].dist = sqrt(pow(point[j].x-point[k].x,2)+pow(point[j].y-point[k].y,2));
				cnt++;
			}
		}
		sort(length, length+cnt,cmp);
		for(j=0; j<cnt; ++j)
		{
			if(Find(length[j].a) != Find(length[j].b))
			{
				Union(length[j].a,length[j].b);
				v.push_back(length[j].dist);
			}
		}
		printf("%.2f\n",*(v.end()-S));
		total = 0;
		cnt = 0;
	}
}