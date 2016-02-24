#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int Case = 0;
	int ans[T] = {0};
	int value1, value2, value3;
	int i;
	while(Case != T)
	{
		cin >> value1 >> value2 >> value3;
		ans[Case] = value1;
		if(value2 >= value1 && value2 <= value3)
		{
			ans[Case] = value2;
		}
		else if(value2 >= value3 && value2 <= value1)
		{
			ans[Case] = value2;
		}
		else if(value1 >= value3 && value1 <= value2)
		{
			ans[Case] = value1;
		}
		else if(value1 >= value2 && value1 <= value3)
		{
			ans[Case] = value1;
		}
		else if(value3 >= value1 && value3 <= value2)
		{
			ans[Case] = value3;
		}
		else if(value3 >= value2 && value2 <= value1)
		{
			ans[Case] = value3;
		}
		Case++;
	}
	for(i = 0; i < T; i++)
	{
		cout << "Case " << i+1 << ": " << ans[i] << endl;
	}
}