#include <iostream>

using namespace std;

int main()
{
	unsigned long long int a, b;
	unsigned long long int temp;
	while(cin >> a >> b)
	{
		if(a > b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		cout << b-a << endl;
	}
}