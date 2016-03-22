#include <iostream>

using namespace std;

int x, y;

int exGCD(int a, int b)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int gcd = exGCD(b, a % b);
		int temp = x;
		x = y;
		y = temp - (a/b)*y;
		return gcd;
	}
}

/*int gcd(int a, int b)
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
}*/

int main()
{
	int a, b;
	int d;
	while(cin >> a >> b)
	{
		cout << x << " " << y << " " << exGCD(a, b) << endl;
	}
}