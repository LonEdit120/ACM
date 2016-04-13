#include <iostream>

using namespace std;
int a[20] = {0};

void switching(int cases)
{
	int i;
	int b[cases];
	for(i=0; i<cases; i++)
	{
		b[a[i]-1] = i+1;
	}
	for(i=0; i<cases; i++)
	{
		a[i] = b[i];
	}
}

int main()
{
	int i, j;
	int m = 0;
	int cases;
	cin >> cases;
	int DP[21][21] = {{0}};
	int num;
	int count = 0;
	int compare[cases] = {0};
	int max = 0;
	int x,y;
	bool link = false;
	while(cin >> num)
	{
		a[m] = num;
		m++;
		if(m == cases)
		{
			count++;
			m = 0;
			switching(cases);
			/*for(i=0; i<cases; i++)
			{
				cout << a[i] << " ";
				if(i == cases-1)
					cout << endl;
			}*/
			if(count == 1)
			{
				for(i=0; i<cases; i++)
				{
					compare[i] = a[i];
				}
			}
			else
			{
				for(i=0; i<cases; i++)
				{
					for(j=0; j<cases; j++)
					{
						if(compare[i] == a[j])
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
						/*for(x=0; x<=cases; x++)
						{
							for(y=0; y<=cases; y++)
							{
								cout << DP[x][y] << " ";
							}
						}
						cout << endl;*/
					}
				}
				for(i=0; i<=cases; i++)
				{
					for(j=0; j<=cases; j++)
					if(DP[cases][j] > max)
						max = DP[cases][j];
				}
				cout << max << endl;
				max = 0;
				for(i=0; i<21; i++)
				{
					for(j=0; j<21; j++)
					{
						DP[i][j] = 0;
					}
				}
			}
		}
	}
}