#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct P
{
	double x;
	double y;
}point[1100],point2[1100],vec[1100],grav[1100],total,prepre,pre;

double plane[1100] = {0};

bool cmp(P a, P b)
{
	if (a.y != b.y)
		return (a.y < b.y);
	else
		return (a.x < b.x);
}

bool cmp2(P a, P b)
{
	double ax = a.x-point[0].x;
	double bx = b.x-point[0].x;
	double ay = a.y-point[0].y;
	double by = b.y-point[0].y;
	double angle = ax*by-ay*bx;
	return angle > 0 || (!angle && sqrt(pow(ax,2)+pow(ay,2)) < sqrt(pow(bx,2)+pow(by,2)));
}

int main()
{
	double A;
	int num;
	int cnt = 0;
	double X,Y;
	while(cin >> num)
	{
		if(num < 3)
			break;

		for(int i=0; i<num; ++i)
		{
			cin >> point2[i].x >> point2[i].y;
		}

		sort(point2,point2+num,cmp);
		sort(point2+1,point2+num,cmp2);

		/*for(int i=0; i<num; ++i)
		{
			cout << "POINT2[" << i << "] : " << point2[i].x << "," << point2[i].y << endl;
		}*/
		//poly---------------------------------
		cnt = 0;
		/*prepre = point2[0];
		pre = point2[1];
		for(int j=0; j<num; ++j)
		{
			X = point2[j].x;
			Y = point2[j].y;
			while(cnt >= 2)
			{
				pre = point[cnt-1];
				prepre = point[cnt-2];
				if(((pre.x - prepre.x)*(Y-prepre.y)-(pre.y - prepre.y)*(X-prepre.x))<=0)
					cnt--;
				else break;
			}
			point[cnt++] = point2[j];
		}*/
		for(int i = 0 ; i < num ; ++i)
		{
			//while(cnt >= 2 && (point[cnt-1]-point[cnt-2]).cross(point2[i]-point[cnt-2]) <= 0)
			while(cnt >= 2 && (point[cnt-1].x-point[cnt-2].x)*(point2[i].y-point[cnt-2].y)-(point[cnt-1].y-point[cnt-2].y)*(point2[i].x-point[cnt-2].x) <= 0)
				--cnt;
			point[cnt++] = point2[i];
		}	

		sort(point,point+cnt,cmp);
		sort(point+1,point+cnt,cmp2);
		//poly---------------------------------
		//cout << "========================" << endl;
		/*for(int i=0; i<cnt; ++i)
		{
			cout << "POINT[" << i << "] : " << point[i].x << "," << point[i].y << endl;
		}*/
		
		//cout << "========================" << endl;
		for(int i=0; i+2<cnt; ++i)
		{
			grav[i].x = (point[0].x+point[i+1].x+point[i+2].x)/3;
			grav[i].y = (point[0].y+point[i+1].y+point[i+2].y)/3;
			//cout << "GRAVITY POINT[" << i << "] : " << grav[i].x << "," << grav[i].y << endl;
		}

		//cout << "========================" << endl;
		for(int i=0; i+1<cnt; ++i)
		{
			vec[i].x = point[i+1].x - point[0].x;
			vec[i].y = point[i+1].y - point[0].y;
			//cout << "VECTOR[" << i << "] : " << vec[i].x << "," << vec[i].y << endl;
		}

		//cout << "========================" << endl;
		for(int i=0; i+1<cnt-1; ++i)
		{
			plane[i] = (vec[i].x*vec[i+1].y - vec[i+1].x*vec[i].y)/2;
			//cout << "PLANE[" << i << "] : " << plane[i] << endl;
		}

		total.x = 0;
		total.y = 0;
		for(int i=0; i<cnt-2; ++i)
		{
			total.x += grav[i].x*plane[i];
			total.y += grav[i].y*plane[i];
		}

		//cout << "A=======================" << endl;
		A = 0;
		for(int i = 0; i+1<cnt-1; ++i)
		{
			A += ((vec[i].x*vec[i+1].y - vec[i+1].x*vec[i].y)/2);
			//cout << "+" << ((vec[i].x*vec[i+1].y - vec[i+1].x*vec[i].y)/2) << endl;
		}
		//cout << "A : " << A << " unit size"<< endl;
		printf("%.3f %.3f\n",(total.x/A),(total.y/A));
	}
}