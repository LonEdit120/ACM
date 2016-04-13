#include <iostream>
using namespace std;

int main()
{
	int cases;
	int i, j=0;
	int num;
	int ans = 0;
	int max;
	while(1)
	{
		cin >> cases;
		if(cases == 0)
			break;
		max = 0;
		for(i=0; i<cases; i++)
		{
			cin >> num;
			if(ans + num < 0)
			{
				ans = 0;
			}
			else if(ans + num >= 0)
			{
				ans = ans + num;
			}
			if(ans > max)
				max = ans;
		}
		if(ans > 0)
			cout << "The maximum winning streak is " << max << "." << endl;
		else
			cout << "Losing streak." << endl;
		ans = 0;
	}
}