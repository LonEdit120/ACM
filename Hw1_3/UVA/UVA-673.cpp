#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int cases;
	int i;
	string s;
	cin >> cases;
	getchar();
	char c;
	int count = 0;
	int x = 0;
	int y = 0;
	while(count++ != cases)
	{
		x = 0;
		y = 0;
		getline(cin, s);
		for(i=0; i < s.length(); i++)
		{
			if(x<0 || y<0)
			{
				break;
			}
			else if(i>=1 && s[i-1] == '(' && s[i] == ']')
			{
				break;
			}
			else if(i>=1 && s[i-1] == '[' && s[i] == ')')
			{
				break;
			}
			else if(s[i] == '(')
			{
				x = x + 1;
			}
			else if(s[i] == ')')
			{
				x = x - 1;
			}
			else if(s[i] == '[')
			{
				y = y + 1;
			}
			else if(s[i] == ']')
			{
				y = y - 1;
			}
			else continue;
		}
		if(x == 0 && y == 0)
		{
			//cout << s <<endl;
			cout << "Yes" << endl;
		}
		else
		{
			//cout << s <<endl;
			//cout << "Case" << count <<".x="<<x<<".y="<<y<<endl;
			cout << "No" << endl;
		}
	}
}