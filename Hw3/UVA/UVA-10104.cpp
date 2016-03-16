#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int temp;
	while(a != 0 && b != 0)
	{
		if(a<b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		a = a % b;
	}
	if(a == 0 && b != 1)
	{
		return b;
	}
}

int main()
{
	int a, b;
	int x, y;
	int d;
	while(cin >> a >> b)
	{
		d = gcd(a, b);
	}
}