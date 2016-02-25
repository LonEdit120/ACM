#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int a, b;
	int count = 0;
	float ans;
	int input;
	cout << fixed << setprecision(2);
	cin >> input;
	while(count != input)
	{
		cin >> a >> b;
		count++;
		if(a%2 == 1 && b%2 == 1)
		{
			ans = (a*b)+0.41;
		}
		else
		{
			ans = a*b;
		}
		cout << "Scenario #" << count << ": " << endl;
		cout << ans << endl;
		cout << endl;
	}
}