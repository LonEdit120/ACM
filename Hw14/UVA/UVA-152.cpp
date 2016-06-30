#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int calc[10] = {0};

struct P
{
	int x;
	int y;
	int z;
}Point[5001];

int dist(struct P A, struct P B)
{
	int ans;
	ans = sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2)+pow((A.z-B.z),2));
	return ans;
}
int main()
{
	int x,y,z;
	int cnt = 0;
	int min=10;
	while(cin >> x >> y >> z)
	{
		if(x==0 && y==0 && z==0)
			break;
		else
		{
			Point[cnt].x = x;
			Point[cnt].y = y;
			Point[cnt].z = z;
			++cnt;
		}
	}
	for(int i=0; i<cnt; ++i)
	{
		min = 10;
		for(int j=0; j<cnt; ++j)
		{
			if(j == i)
				continue;
			int temp = dist(Point[i],Point[j]);
			if(temp<min)
				min = temp;
		}
		if(min>=0 && min <=9)
		{
			++calc[min];
		}
	}
	for(int i =0; i<10; ++i)
		printf("%4d", calc[i]);
	cout << endl; 
}