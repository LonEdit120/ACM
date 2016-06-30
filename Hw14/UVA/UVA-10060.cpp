#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double plane;
double V;
double height, thickness;
double cookie;
double PI = 3.14159265359;
struct P
{
	double x, y;
	//Point(double x=0, double y=0):x(x), y(y){}
}Point[100000];

//vector<P> v;

int main()
{
	int amount;
	int cnt;
	double r;
	double num;
	while(cin >> amount)
	{
		if(amount == 0)
			return 0;
		V = 0;
		for(int i = 0; i<amount; ++i)
		{
			plane = 0;
			cin >> height;
			//cout << "Height : " << height << endl;
			cin >> Point[0].x >> Point[0].y;
			//cout << "Point[0] = (" << Point[0].x << "," << Point[0].y << ")" << endl;
			cnt = 1;
			while(1)
			{
				cin >> Point[cnt].x >> Point[cnt].y;
				if(Point[cnt].x == Point[0].x && Point[cnt].y == Point[0].y)
					break;
				Point[cnt].x -= Point[0].x;
				Point[cnt].y -= Point[0].y;
				//cout << "Point["<<cnt<<"] = (" << Point[cnt].x << "," << Point[cnt].y << ")" << endl;
				++cnt;
			}
			//cnt -= 1;
			//cout << "Amount of vectors : " << cnt << endl;
			//for(int j = 1; j<cnt; ++j)
			//{
				//cout << "(" << Point[j].x << "," << Point[j].y << ")" /*<< " x (" << Point[j+1].x << "," << Point[j+1].y << ") = " << abs((Point[j].x*Point[j+1].y - Point[j+1].x*Point[j].y)/2)*/ << endl ;
				//plane += abs((Point[j].x*Point[j+1].y - Point[j+1].x*Point[j].y)/2);
			//}
			for(int j = 1; j<cnt-1; ++j)
			{
				//cout << "(" << Point[j].x << "," << Point[j].y << ") x (" << Point[j+1].x << "," << Point[j+1].y << ") = " << abs((Point[j].x*Point[j+1].y - Point[j+1].x*Point[j].y)/2) << endl ;
				plane += ((Point[j].x*Point[j+1].y - Point[j+1].x*Point[j].y)/2);
				/*cout << "Point["<<j<<"] = (" << Point[j].x << "," << Point[j].y << ")" << "x";
				cout << "Point["<<j+1<<"] = (" << Point[j+1].x << "," << Point[j+1].y << ")" << endl;*/
			}
			//cout << "Bottom plane size : " << plane << endl;
			V += fabs(plane)*height;
			//cout << "V : " << V << endl;
			//cout << "=================" << endl;
		}
		cin >> r >> thickness;
		//cout << "R : " << r << " , Height : " << height << endl;
		cookie = r*r*PI*thickness;
		//cout << "Cookie size : " << cookie << endl;
		cout << (int)(V/cookie) << endl;
	}
}