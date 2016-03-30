#include <iostream>

using namespace std;

int main()
{
	int value;
	int i, j;
	int count = 0;
	int coin[5]={1, 5, 10, 25 ,50};
	int change[7849] = {0};
	change[0] = 1;
	for(i=0; i<5; i++)
	{
		for(j=0; j<7849; j++)
		{
			if(j-coin[i] >= 0 && change[j-coin[i]])
			{
				//value -= coin[i];
				change[j] += change[j-coin[i]];
			}
		}
	}
	while(cin >> value)
	{
		cout << change[value] << endl;
	}
}
