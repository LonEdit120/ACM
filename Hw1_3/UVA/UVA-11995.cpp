#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int lines;
	stack<int> stk;
	queue<int> que;
	priority_queue<int> pq;
	int count = 0;
	int s, q, p;
	bool bs = true, bq = true, bp = true;
	int a, b;
	while(cin >> lines)
	{
		while(count != lines)
		{
			count++;
			cin >> a >> b;
			/*if(a == 1)
			{
				stk.push(b);
				que.push(b);
				pq.push(b);
			}*/
//			while(stk.empty() && que.empty() && pq.empty())
//			{
				if(a == 1)
				{
					stk.push(b);
					que.push(b);
					pq.push(b);
				}
				if(a == 2)
				{
					if(stk.empty())
					{
						bs = false;
						bq = false;
						bp = false;
						continue;
					}
					s = stk.top();
					q = que.front();
					p = pq.top();
					/*if(q == s[2])
					{
						bq = true;
					}
					if(s != s[2])
					{
						while(stk.empty() == false)
						{
							stk.pop();
							if(stk.top() == s[2])
							{
								stk.pop();
								if(stk.empty() == true)
								{
									bs = true;
								}
							}
						}
					}*/
					if(s != b)
						bs = false;
					if(q != b)
						bq = false;
					if(p != b)
						bp = false;
					stk.pop();
					que.pop();
					pq.pop();
				}
//			}
		}
		if(bs && !bq && !bp)
		{
				cout << "stack" << endl;
		}
		else if(!bs && bq && !bp)
		{
			cout << "queue" << endl;
		}
		else if(!bs && !bq && bp)
		{
			cout << "priority queue" << endl;
		}
		else if(!bs && !bq && !bp)
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout << "not sure" << endl;
		}
		count = 0;
		while(stk.empty() == false)
		{
			stk.pop();
		}
		while(que.empty() == false)
		{
			que.pop();
		}
		while(pq.empty() == false)
		{
			pq.pop();
		}
		bs = true;
		bq = true;
		bp = true;
	}
}