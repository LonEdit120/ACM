	#include <iostream>
	#include <algorithm>
	#include <cmath>
	#include <cstdio>
	using namespace std;

	double total;

	int s[1000000];

	struct P
	{
		int No;
		int x;
		int y;
	}point[1000];

	struct L
	{
		int a;//No.
		int b;//No.
		double dist;
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
		return (s[x] == x) ?(x) :s[x]=Find(s[x]);
	}
	void Union(int x, int y)
	{
		s[Find(x)] = Find(y);
	}

	bool cmp(L a, L b)
	{
		return a.dist<b.dist;
	}



	int main()
	{
		int points;
		int j, k;
		int cnt = 0;
		int bridge;
		int m,n;
		while(cin >> points)
		{
			Clean();

			total = 0;
			cnt = 0;
			for(j=0; j<points; ++j)
			{
				cin >> point[j].x >> point[j].y;
				point[j].No = j;
			}
			for(j=0; j<points; ++j)
			{
				for(k=j+1; k<points; ++k)
				{
					length[cnt].a = point[j].No;
					length[cnt].b = point[k].No;
					length[cnt].dist = sqrt((point[j].x-point[k].x) * (point[j].x-point[k].x) + (point[j].y-point[k].y) * (point[j].y-point[k].y));
					cnt++;
				}
			}
			sort(length, length+cnt,cmp);
			cin >> bridge;
			for(j=0; j<bridge; ++j)
			{
				cin >> m >> n;
				Union(m-1,n-1);
			}
			for(j=0; j<cnt; ++j)
			{
				if(Find(length[j].a) != Find(length[j].b))
				{
					Union(length[j].a,length[j].b);
					total += length[j].dist;
				}
			}
			printf("%.2lf\n",total);
		}
		return 0;
	}