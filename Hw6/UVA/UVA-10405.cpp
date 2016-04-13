#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1,s2;
	int count = 0;
	int x;
	char a[1000], b[1000];
	int max = 0;
	int i, j;
	int DP[1001][1001] = {{0}};
	while(getline(cin,s1))
	{
		count++;
		getline(cin,s2);
		for(i=0; i<s1.length(); i++)
		{
			a[i] = s1[i];
		}
		for(i=0; i<s2.length(); i++)
		{
			b[i] = s2[i];
		}
		for(i=0; i<s1.length(); i++)
		{
			for(j=0; j<s2.length(); j++)
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
		for(i=0; i<=s2.length(); i++)
		{
			if(DP[s1.length()][i] > max)
				max = DP[s1.length()][i];
		}
		cout << max << endl;
		max = 0;
		for(i=0; i<1001; i++)
		{
			for(j=0; j<1001; j++)
			{
				DP[i][j] = 0;
			}
		}
	}
}