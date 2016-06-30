#include <iostream>

using namespace std;

struct point{
	double x1;
	double x2;
	int x;
	int y;
}board[5001],toy[5001];

int place[5001] = {0};

int main()
{
	bool check;
	int n, m, X1, Y1, X2, Y2;
	//n(carboard partition)
	//m(number of toys)
	while(cin >> n)
	{
		if(n == 0)
			break;
		cin >> m >> X1 >> Y1 >> X2 >> Y2;
		for(int i=0; i<n; ++i)
		{
			cin >> board[i].x1 >> board[i].x2;
		}
		for(int i=0; i<m; ++i)
		{
			cin >> toy[i].x >> toy[i].y;
		}
		for(int i=0; i<m; ++i)
		{
			//cout << i << "================" << endl;
			check = true;
			int j;
			for(j=0; j<n; ++j)
			{
				//cout << ((board[j].x2-board[j].x1)*(toy[i].y-board[i].y1))-((board[j].y2-board[j].y1)*(toy[i].x-board[j].x1)) << endl;
				if(((board[j].x2-board[j].x1)*(toy[i].y-Y1))-((Y2-Y1)*(toy[i].x-board[j].x1))<0)
				{
					++place[j];
					check = false;
					break;
				}
				//cout << i << " PUTS HERE : " << j << endl;
			}
			//cout << i << " PUTS HERE : " << j << endl;
			if(check)
				++place[n];
		}
		for(int i=0; i<=n; ++i)
		{
			cout << i << ": " << place[i] << endl;
		}
		for(int i=0; i<n+1; ++i)
			place[i] = 0;
		cout << endl;
	}
}