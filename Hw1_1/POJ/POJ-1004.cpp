#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float input[12];
	float in;
	int i;
	float ans = 0;
	cout << fixed << setprecision(2);
	for(i = 0; i<12; i++)
	{
		cin >> in;
		input[i] = in;
	}
	for(i = 0; i<12; i++)
	{
		ans = ans + input[i];
	}
	ans = ans / 12.0;
	cout << "$" << ans << endl;
}