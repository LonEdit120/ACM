#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

struct P
{
	double x;
	double y;
}point[110], poly[110], prepre, pre;

bool cmp(P a, P b)
{
	if (a.x != b.x)
		return (a.x<b.x);
	else if (a.x == b.x)
		return (a.y < b.y);
}

bool cmp2(P a, P b)
{
	double ax = a.x-point[0].x;
	double ay = a.y-point[0].y;

	double bx = b.x-point[0].x;
	double by = b.y-point[0].y;
	double angle = ax*by-ay*bx;
	return angle > 0 || (!angle && sqrt(pow(ax,2)+pow(ay,2)) < sqrt(pow(bx,2)+pow(by,2)));
}

bool cmp3(P a, P b)
{
	double ax = a.x-poly[0].x;
	double bx = b.x-poly[0].x;
	double ay = a.y-poly[0].y;
	double by = b.y-poly[0].y;
	double angle = ax*by-ay*bx;
	return angle > 0 || (!angle && sqrt(pow(ax,2)+pow(ay,2)) < sqrt(pow(bx,2)+pow(by,2)));
}

int main()
{
	int num;
	int cases = 0;
	double per = 0;
	double A1, A2;
	double X, Y;
	int cnt;
	while(cin >> num)
	{
		cases++;
		if(num == 0)
			break;
		for(int i=0; i<num; ++i)
		{
			cin >> point[i].x >> point[i].y;
		}
		sort(point,point+num,cmp);
		sort(point+1,point+num,cmp2);
		/*for(int i=0; i<num; ++i)
		{
			cout << i << " : " << point[i].x << "," << point[i].y << endl;
		}*/
		A1 = 0;
		for(int i=1; i+1<num; ++i)
		{
			double x1 = point[i].x - point[0].x;
			double y1 = point[i].y - point[0].y;
			double x2 = point[i+1].x - point[0].x;
			double y2 = point[i+1].y - point[0].y;
			A1 += (x1*y2 - x2*y1)/2;
			//cout << i << "," << i+1 << " = (" << x1 << "*" << y2 << " - " << x2 << "*" << y1 << ")/2 = "<< (x1*y2 - x2*y1)/2  << endl;
		}
		//cout << "minimum : " << A1 << endl;
		//poly-------------------------------
		cnt = 0;
		for(int i = 0 ; i < num ; ++i)
		{
			while(cnt >= 2 && (poly[cnt-1].x-poly[cnt-2].x)*(point[i].y-poly[cnt-2].y)-(poly[cnt-1].y-poly[cnt-2].y)*(point[i].x-poly[cnt-2].x) <= 0)
				--cnt;
			poly[cnt++] = point[i];
		}	
		/*sort(poly,poly+cnt,cmp);
		sort(poly+1,poly+cnt,cmp3);*/
		/*for(int i=0; i<cnt; ++i)
		{
			cout << poly[i].x << "," << poly[i].y << endl;
		}*/
		//poly-------------------------------
		
		A2 = 0;
		for(int i=1; i+1<cnt; ++i)
		{
			double x1 = poly[i].x - poly[0].x;
			double y1 = poly[i].y - poly[0].y;
			double x2 = poly[i+1].x - poly[0].x;
			double y2 = poly[i+1].y - poly[0].y;
			A2 += (x1*y2 - x2*y1)/2;
			//cout << i << "," << i+1 << " = (" << x1 << "*" << y2 << " - " << x2 << "*" << y1 << ")/2 = "<< (x1*y2 - x2*y1)/2  << endl;
		}
		//cout << "container : " << A2 << endl;
		per = ((A2-A1)/A2)*100;
		cout << "Tile #" << cases << endl;
		printf("Wasted Space = %.2f ", per);
		cout << "%" << endl << endl;
	}
}