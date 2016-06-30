#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct point
{
	double x, y;
}p1,p2,p3,p4;

int main()
{
	int num;
	cin >> num;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	for(int i=0; i<num;++i)
	{
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
		if(fabs((p1.x-p2.x)*(p3.y-p4.y)-(p3.x-p4.x)*(p1.y-p2.y))<=10e-8)
		{
			double dis = sqrt((p3.x-p4.x)*(p3.x-p4.x)+(p3.y-p4.y)*(p3.y-p4.y));
			double dist = ((p2.x-p4.x)*(p3.y-p4.y)-(p3.x-p4.x)*(p2.y-p4.y))/dis;
			if(dist == 0)
				cout << "LINE" << endl;
			else
				cout << "NONE" << endl;
		}
		else
		{
			double t;
			t = ((p1.x-p3.x)*(p3.y-p4.y)-(p1.y-p3.y)*(p3.x-p4.x))/((p1.x-p2.x)*(p3.y-p4.y)-(p1.y-p2.y)*(p3.x-p4.x));
			point ans;
			ans.x = p1.x+(p2.x-p1.x)*t;
			ans.y = p1.y+(p2.y-p1.y)*t;
			printf("POINT %.2f %.2f\n", ans.x, ans.y);
		}
	}
	cout << "END OF OUTPUT" << endl;
}