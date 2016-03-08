#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int cases;
	stack<char> stk;
	string s;
	char c = ' ';
	int count = 0;
	cin >> cases;
	getchar();
	while(count != cases)
	{
		count++;
		while(!stk.empty())
		{
			stk.pop();
		}
		while(1)
		{
			c = getchar();
			if(c != ' ' && c != '\n')
			{
				if(stk.empty())
				{
					stk.push(c);
				}
				else if(!stk.empty())
				{
					if(c == ')' && stk.top() == '[')
					{
						cout << "No" << endl;
						while(c != '\n' && c != EOF)
						{
							c = getchar();
						}
						while(!stk.empty())
						{
							//cout << stk.top() << endl;
							stk.pop();
						}
						break;
					}
					else if(c == ']' && stk.top() == '(')
					{
						cout << "No" << endl;
						while(c != '\n' && c != EOF)
						{
							c = getchar();
						}
						while(!stk.empty())
						{
							//cout << stk.top() << endl;
							stk.pop();
						}
						break;
					}
					else if(c == ')' && stk.top() == '(')
						stk.pop();
					else if(c == ']' && stk.top() == '[')
						stk.pop();
					else
						stk.push(c);
				}
			}
			else if(c == '\n')
			{
				if(!stk.empty())
				{
					cout << "No" << endl;
					while(!stk.empty())
					{
						//cout << stk.top() << endl;
						stk.pop();
					}
				}
				else if(stk.empty())
					cout << "Yes" << endl;
				else
					cout << "WTF" << endl;
				break;
			}
		}
	}
}