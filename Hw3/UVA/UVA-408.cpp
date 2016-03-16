#include <iostream>

using namespace std;

void gcd(int a, int b)
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
	if(a == 0 && b == 1)
	{
		cout << "    Good Choice" << endl;
	}
	else if(a == 0 && b != 1)
	{
		cout << "    Bad Choice" << endl;
	}
}

int main()
{
	int step, mod;
	int sc, mc;
	int s2, m2;
	while(cin >> step >> mod)
	{
		s2 = step;
		m2 = mod;
		sc = 1;
		mc = 1;
		while(step >= 10)
		{
			step = step/10;
			sc++;
		}
		sc = 10 - sc;
		while(mod >= 10)
		{
			mod = mod/10;
			mc++;
		}
		mc = 10 - mc;

		while(sc != 0)
		{
			sc--;
			cout << " ";
		}
		cout << s2;
		while(mc != 0)
		{
			mc--;
			cout << " ";
		}
		cout << m2;
		gcd(s2, m2);
		cout << endl;
	}
}