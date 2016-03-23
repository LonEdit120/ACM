#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double a, b;
	cout << fixed << setprecision(0);
	while(cin >> a >> b)
	{
		cout << pow(b, 1/a) << endl;
	}
}