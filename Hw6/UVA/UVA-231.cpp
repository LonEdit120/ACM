#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int count = 0;
	int num[100000] = {0};
	int len[100000];
	len[0] = 1;
	int test = 0;
	int i;
	int a, b;
	int length = 0;
	int max = 0;
	for(i=0; i<100000; i++)
	{
		len[i] = 1; 
	}
	i = 0;
	while(cin >> n)
	{
		if(n == -1)
		{
			count++;
			if(count == 2)
				break;
			for(a=1; a<i; a++)
			{
				length = 0;
				for(b=0; b<a; b++)
				{
					if(num[a]<=num[b] && len[b]>=length)
					{
						length = len[b];
					}
				}
				len[a] = length + 1;
				if(len[a] > max)
					max = len[a];
			}
			if(test != 0)
				cout << endl;
			test++;
			cout << "Test #" << test << ":" << endl;
			cout << "  maximum possible interceptions: " << max << endl;
			max = 0;
			i = 0;
		}
		else
		{
			count = 0;
			num[i] = n;
			i++;
		}
	}
}