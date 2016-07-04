#include <stack>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct P
{
	double x;
	double y;
}point[1000], pre, prepre, temp, stk[1000], stk2[1000];

bool cmpto(P a, P b)
{
	if (a.x != b.x)
		return (a.x<b.x);
	else
		return (a.y < b.y);
}

bool cmpfrom(P a, P b)
{
	if (a.x != b.x)
		return (a.x>b.x);
	else
		return (a.y > b.y);
}

int main()
{
	int X, Y;
	int points;
	int cnt;
	int temp;
	int region = 0;
	double para;
	while(cin >> points)
	{
		++region;
		
		if(points == 0)
			break;
		if(region!=1)
			cout << endl;
		for(int j=0; j<points; ++j)
		{
			cin >> point[j].x >> point[j].y;
		}
		sort(point,point+(points),cmpto);

		cnt = 0;
		prepre = point[0];
		pre = point[1];
		for(int j=0; j<points; ++j)
		{
			X = point[j].x;
			Y = point[j].y;
			//while(cnt>=2 && ((pre.x - prepre.x)*(Y-prepre.y)-(pre.y - prepre.y)*(X-prepre.x))<=0)
			while(cnt >= 2)
			{
				//cout << "WHILE : " << cnt << endl;
				pre = stk[cnt-1];
				prepre = stk[cnt-2];
				if(((pre.x - prepre.x)*(Y-prepre.y)-(pre.y - prepre.y)*(X-prepre.x))>=0)
					cnt--;
				else break;
			}
			
			stk[cnt++] = point[j];
		}
		temp = cnt+1;
		prepre = point[points];
		pre = point[points-1];
		for(int j=points-2; j>=0; --j)
		{
			X = point[j].x;
			Y = point[j].y;
			//while(cnt>=2 && ((pre.x - prepre.x)*(Y-prepre.y)-(pre.y - prepre.y)*(X-prepre.x))<=0)
			while(cnt >= temp)
			{
				//cout << "WHILE : " << cnt << endl;
				pre = stk[cnt-1];
				prepre = stk[cnt-2];
				if(((pre.x - prepre.x)*(Y-prepre.y)-(pre.y - prepre.y)*(X-prepre.x))>=0)
					cnt--;
				else break;
			}
			
			stk[cnt++] = point[j];
		}
		
		///////////////////////////////////////////////////////
		int min = 2130000000;
		for(int j=0; j<cnt-1; ++j)
		{
			if(stk[j].y < min)
			{
				min = stk[j].y;
				temp = j;
			}
		}

		for(int j=temp; j<cnt-1; ++j)
		{
			stk2[j-temp] = stk[j];
		}
		for(int j=0; j<temp; ++j)
		{
			stk2[j+cnt-temp-1] = stk[j];
		}
		stk2[cnt-1] = stk2[0];
		cout << "Region #" << region << ":" << endl;
		for(int j=0; j<cnt; ++j)
		{
			if(j != cnt-1)
				printf("(%.1lf,%.1lf)-",stk2[j].x,stk2[j].y);
			else
				printf("(%.1lf,%.1lf)\n",stk2[j].x,stk2[j].y);
		}
		para = 0;
		for(int j=0; j<cnt-1; ++j)
		{
			para += sqrt(pow(stk2[j].x-stk2[j+1].x,2)+pow(stk2[j].y-stk2[j+1].y,2));
		}
		printf("Perimeter length = %.2lf\n",para);
	}
}