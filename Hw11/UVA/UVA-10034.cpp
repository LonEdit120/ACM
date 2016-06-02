#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

float total = 0;

int s[52000];

struct P
{
	int No;
	float x;
	float y;
}point[101];

struct L
{
	int a;//No.
	int b;//No.
	float dist;
}length[4950];

void Clean()
{
	int i;
	for(i=0; i<52000; i++)
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
	cin >> cases;
	for(i=0; i<cases; ++i)
	{
		Clean();
		cin >> points;
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
				//cout <<"("<< point[length[cnt].a].x <<","<<point[length[cnt].a].y<< ")"<< "->("<< point[length[cnt].b].x <<","<<point[length[cnt].b].y<< ") = "<< length[cnt].dist << endl;
				cnt++;
			}
		}
		/*for(j=0; j<cnt; ++j)
		{
			cout <<"("<< point[length[j].a].x <<","<<point[length[j].a].y<< ")"<< "->("<< point[length[j].b].x <<","<<point[length[j].b].y<< ") = "<< length[j].dist << endl;
		}
		cout << "=====SORT=====" << endl*/
		sort(length, length+cnt,cmp);
		/*for(j=0; j<cnt; ++j)
		{
			cout <<"("<< point[length[j].a].x <<","<<point[length[j].a].y<< ")"<< "->("<< point[length[j].b].x <<","<<point[length[j].b].y<< ") = "<< length[j].dist << endl;
		}*/
		for(j=0; j<cnt; ++j)
		{
			if(Find(length[j].a) != Find(length[j].b))
			{
				Union(length[j].a,length[j].b);
				//cout << length[j].dist << endl;
				total += length[j].dist;
			}
		}

		/*cout << "===UNION===" << endl;
		for(j=0; j<cnt; ++j)
		{
			cout <<"("<< point[length[j].a].x <<","<<point[length[j].a].y<< ")"<< "->("<< point[length[j].b].x <<","<<point[length[j].b].y<< ") = "<< length[j].dist << endl;
		}*/
		if(i!=0)
			cout << endl;
		printf("%.2f\n",total);
		//initializer---------------------
		total = 0;
		cnt = 0;
	}
}