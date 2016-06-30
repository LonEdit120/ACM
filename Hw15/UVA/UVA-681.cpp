#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct P
{
	int x;
	int y;
}point[520], pre, prepre;

stack<P> stk;

bool cmp(P a, P b)
{
	return a.x<b.x;
}

int main()
{
	int X, Y;
	int cases;
	int points;
	int trash;
	cin >> cases;
	for(int i=0; i<cases; ++i)
	{
		cin >> points;
		for(int j=0; j<points-1; ++j)
		{
			cin >> point[j].x >> point[j].y;
		}
		cin >> trash >> trash;
		sort(point,point+(points-1),cmp);
		for(int j=0; j<points-1; ++j)
		{
			cout << j << " : " << point[j].x << " " << point[j].y << endl;
		}
		cout << "================" << endl;
		stk.push(point[0]);
		prepre = point[0];
		pre = point[1];
		/*int cnt = 1;
		while(prepre.x == pre.x && prepre.y == pre.y)
		{
			++cnt;
			pre = point[cnt];
		}
		stk.push(point[cnt]);*/
		stk.push(point[1]);
		for(int j=2; j<points-1; ++j)
		{
			X = point[j].x;
			Y = point[j].y;
			//cout << "j:" << j << " => " << X << " " << Y << endl;
			if((((prepre.x-X)*(pre.y-Y))-((prepre.y-Y)*(pre.x-X))) > 0)
			{
				stk.pop();
				prepre = stk.top();
				stk.push(point[j]);
				pre = point[j];
				cout << j << " => " << point[j].x << " " << point[j].y << endl;
			}
		}
		//----------------------------------
		while(!stk.empty())
		{
			cout << stk.top().x << " " << stk.top().y << endl;
			stk.pop();
		}
		cin >> trash;
	}
}