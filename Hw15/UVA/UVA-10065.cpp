#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct P
{
	double x;
	double y;
}point[110];

bool cmp(P a, P b)
{
	if (a.x != b.x)
		return (a.x < b.x);
	else
		return (a.y < b.y);
}

bool cmp2(P a, P b)
{
	double ax = a.x-point[0].x;
	double bx = b.x-point[0].x;
	double ay = a.y-point[0].y;
	double by = b.y-point[0].y;
	double angle = ax*by-ay*bx;
	return angle > 0 || (!angle && sqrt(pow(ax,2)+pow(ay,2)) > sqrt(pow(bx,2)+pow(by,2)));
}

int main()
{
	int num;
	int cnt=0;
	double per = 0;
	double A1, A2;
	while(cin >> num)
	{
		cnt++;
		if(num == 0)
			break;
		for(int i=0; i<num; ++i)
		{
			cin >> point[i].x >> point[i].y;
		}
		sort(point,point+num,cmp);
		sort(point+1,point+num,cmp2);
		for(int i=0; i<num; ++i)
		{
			cout << point[i].x << " " << point[i].y << endl;
		}
		A1 = 0;
		for(int i=1; i+1<num; ++i)
		{
			double x1 = point[i].x - point[0].x;
			double y1 = point[i].y - point[0].y;
			double x2 = point[i+1].x - point[0].x;
			double y2 = point[i+1].y - point[0].y;
			A1 += (x1*y2 - x2*y1)/2;
			cout << i << "," << i+1 << " = (" << x1 << "*" << y2 << " - " << x2 << "*" << y1 << ")/2 = "<< (x1*y2 - x2*y1)/2  << endl;
		}
		cout << "A1 : " << A1 << endl;

		cout << "Tile #" << cnt << endl;
		printf("Wasted Space = %.2f ", per);
		cout << "%" << endl << endl;
	}
}