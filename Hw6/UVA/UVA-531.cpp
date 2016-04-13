#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
	vector<string> a;
	vector<string> b;
	stack<string> ans;
	int DP[201][201] = {{0}};
	string s;
	int i, j;
	int x, y;
	bool nxt = false;
	x=0;
	int count = 0;
	while(cin >> s)
	{
		if(s == "#")
			nxt = true;
		else
		{
			a.push_back(s);
			x++;
		}
		if(nxt)
		{
			count++; 
			nxt = false;
			y=0;
			while(1)
			{
				cin >> s;
				if(s == "#")
					break;
				b.push_back(s);
				y++;
			}
			for(i=0; i<x; i++)
			{
				for(j=0; j<y; j++)
				{
					if(a[i] == b[j])
					{
						DP[i+1][j+1] = DP[i][j] + 1;
					}
					else
					{
						if(DP[i][j+1] >= DP[i+1][j])
							DP[i+1][j+1] = DP[i][j+1];
						else
							DP[i+1][j+1] = DP[i+1][j];
					}
				}
			}
			//cout << "x= " << x << " y= " << y << endl;
			/*for(i=0; i<=x; i++)
			{
				for(j=0; j<=y; j++)
				{
					cout << DP[i][j] << " ";
				}
				cout << endl;
			}*/
			i=x-1;
			j=y-1;
			//cout << a[i] << " " << b[j] << endl;
			while(i>=0 && j>=0)
			{
				if(a[i] == b[j])
				{
					ans.push(b[j]);
					i--;
					j--;
				}
				else
				{
					if(DP[i][j+1]>DP[i+1][j])
						i--;
					else
						j--;
				}
			}
			while(!ans.empty())
			{
				cout << ans.top();
				ans.pop();
				if(!ans.empty())
					cout << " ";
			}
			cout << endl;
			for(i=0; i<201; i++)
			{
				for(j=0; j<201; j++)
				{
					DP[i][j] = 0;
				}
			}
			a.clear();
			b.clear();
			x=0;
			y=0;
			nxt = false;
			//cout << "COUNT : " << count << endl;
		}
	}
}