#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct P
{
	int x;
	int y;
}point[520], pre, prepre, temp, stk[520], stk2[520];

bool cmpto(P a, P b)
{
	if (a.x != b.x)
		return (a.x<b.x);
	else if (a.x == b.x)
		return (a.y < b.y);
}

bool cmpfrom(P a, P b)
{
	if (a.x != b.x)
		return (a.x>b.x);
	else if (a.x == b.x)
		return (a.y > b.y);
}

int main()
{
	int X, Y;
	int cases;
	int points;
	int trash;
	int cnt, cnt2;
	int temp;
	cin >> cases;
	cout << cases << endl;
	for(int i=0; i<cases; ++i)
	{
		if(i!=0)
			cout << "-1" << endl;
		cin >> points;
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
				if(((pre.x - prepre.x)*(Y-prepre.y)-(pre.y - prepre.y)*(X-prepre.x))<=0)
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
				if(((pre.x - prepre.x)*(Y-prepre.y)-(pre.y - prepre.y)*(X-prepre.x))<=0)
					cnt--;
				else break;
			}
			
			stk[cnt++] = point[j];
		}
		
		///////////////////////////////////////////////////////
		cout << cnt << endl;
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
		for(int j=0; j<cnt; ++j)
		{
			cout << stk2[j].x << " " << stk2[j].y << endl;
		}
		cin >> trash;
	}
}