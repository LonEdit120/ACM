#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<long long int> p;
	long long int amount;
	long long int length;
	long long int total = 0;
	long long int ans = 0;
	long long int i;
	long long int a, b;
	cin >> amount;
	for(i=0; i<amount; i++)
	{
		cin >> length;
		p.push(-length);
	}
	while(p.size()>1)
	{
		a = p.top();
		p.pop();
		total = a;
		b = p.top();
		p.pop();
		total += b;
		ans -= total;
		p.push(a+b);
	}
	cout << ans << endl;
	total = 0;
	ans = 0;
}