#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct P
{
	double x;
	double y;
}point[11000],vec[11000],grav[11000],total;

double plane[11000] = {0};

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
	if(angle > 0)
		return true;
	else
		return sqrt(pow(ax,2)+pow(ay,2)) < sqrt(pow(bx,2)+pow(by,2));
}

int main()
{
	double A;
	int num;
	int VEC, PLANE, POINT, GRAV;
	while(cin >> num)
	{
		if(num < 3)
			break;

		for(int i=0; i<num; ++i)
		{
			cin >> point[i].x >> point[i].y;
		}
		sort(point,point+num,cmp);
		sort(point,point+num,cmp2);

		for(int i=0; i<num; ++i)
		{
			//cout << "POINT[" << i << "] : " << point[i].x << "," << point[i].y << endl;
			POINT = i;
		}

		//cout << "========================" << endl;
		for(int i=0; i+2<num && i+2<=POINT; ++i)
		{
			grav[i].x = (point[0].x+point[i+1].x+point[i+2].x)/3;
			grav[i].y = (point[0].y+point[i+1].y+point[i+2].y)/3;
			//cout << "GRAVITY POINT[" << i << "] : " << grav[i].x << "," << grav[i].y << endl;
			GRAV = i;
		}

		//cout << "========================" << endl;
		for(int i=0; i+1<num && i+1<=POINT; ++i)
		{
			vec[i].x = point[i+1].x - point[0].x;
			vec[i].y = point[i+1].y - point[0].y;
			//cout << "VECTOR[" << i << "] : " << vec[i].x << "," << vec[i].y << endl;
			VEC = i;
		}

		//cout << "========================" << endl;
		for(int i=0; i+1<num-1 && i+1<=VEC; ++i)
		{
			plane[i] = (vec[i].x*vec[i+1].y - vec[i+1].x*vec[i].y)/2;
			//cout << "PLANE[" << i << "] : " << plane[i] << endl;
			PLANE = i;
		}

		total.x = 0;
		total.y = 0;
		for(int i=0; i<num-2 && i<=GRAV && i<= PLANE; ++i)
		{
			total.x += grav[i].x*plane[i];
			total.y += grav[i].y*plane[i];
		}
		cout << POINT+1 << endl;
		cout << VEC+1 << endl;
		cout << GRAV+1 << endl;
		cout << PLANE+1 << endl;
		//cout << "A=======================" << endl;
		A = 0;
		for(int i = 0; i+1<num-1 && i+1<=VEC; ++i)
		{
			A += ((vec[i].x*vec[i+1].y - vec[i+1].x*vec[i].y)/2);
			//cout << "+" << ((vec[i].x*vec[i+1].y - vec[i+1].x*vec[i].y)/2) << endl;
			cout << i << " " << i+1 << endl;
		}
		//cout << "A : " << A << " unit size"<< endl;
		printf("%.3f %.3f\n",(total.x/A),(total.y/A));
	}
}