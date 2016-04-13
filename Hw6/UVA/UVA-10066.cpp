#include <iostream>

using namespace std;

int main()
{
	int a[100] = {0};
	int b[100] = {0};
	int compare[100] = {0};
	int DP[101][101] = {{0}};
	int num1, num2;
	int i, j;
	int count = 0;
	int num;
	int max = 0;
	while(cin >> num1 >> num2)
	{
		count++;
		if(num1 == 0 && num2 == 0)
			break;
		for(i=0; i<num1; i++)
		{
			cin >> a[i];
		}
		for(i=0; i<num2; i++)
		{
			cin >> b[i];
		}
		for(i=0; i<num1; i++)
		{
			for(j=0; j<num2; j++)
			{
				if(a[i] == b[j])
				{
					DP[i+1][j+1] = DP[i][j] + 1;
				}
				else
				{
					if(DP[i][j+1] >= DP[i+1][j])
						DP[i+1][j+1] = DP[i][j+1];
					else
						DP[i+1][j+1] = DP[i+1][j];
				}
			}
		}
		for(i=0; i<=num2; i++)
		{
			if(DP[num1][i] > max)
				max = DP[num1][i];
		}
		cout << "Twin Towers #" << count << endl;
		cout << "Number of Tiles : " << max << endl;
		cout << endl;
		max = 0;
		for(i=0; i<101; i++)
		{
			for(j=0; j<101; j++)
			{
				DP[i][j] = 0;
			}
		}
	}
}