#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int i, j;
	int num, cases;
	int cow[50001] = {0};
	int range1, range2;
	scanf("%d%d",&num,&cases);
	priority_queue<int> p;
	priority_queue<int> n;
	for(i=0; i<num; i++)
	{
		scanf("%d", &cow[i]);
		p.push(cow[i]);
		n.push(-cow[i]);
	}
	for(i=0; i<cases; i++)
	{
		scanf("%d%d",&range1,&range2);
		for(j=range1-1; j<range2; j++)
		{
			p.push(cow[j]);
			n.push(-cow[j]);
		}
		printf("%d\n",p.top()+n.top());
		while(!p.empty())
		{
			p.pop();
			n.pop();
		}
	}
} 