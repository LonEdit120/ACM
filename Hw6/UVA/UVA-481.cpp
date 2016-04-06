#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[10000] = {0};
	int length[10000];
	int ans[10000] = {0};
	int i = 0, j;
	int longest = 0;
	int largest = 0;
	int max = 0;
	int terminate;
	for(i=0; i<10000; i++)
	{
		length[i] = 0;
	}
	length[0] = 1;
	i = 0;
	while(cin >> num[i])
	{
		if(num[i] > largest)
			largest = num[i];
		if(i != 0)
		{
			for(j=0; j<i; j++)
			{
				if(num[j]<num[i])
				{
					if(length[j]>longest)
					{
						longest = length[j];
						terminate = i;
					}
				}
			}
			length[i] = longest+1;
		}
		if(longest > max)
			max = longest;
		longest = 0;
		i++;
	}
	max += 1;
	cout << max << endl;
	cout << "-" << endl;
	/*for(i=0; i<terminate; i++)
	{
		cout << length[i] << endl;
	}*/
	for(i=0; i<max; i++)
	{
		ans[i] = largest;
	}
	for(i=0; i<terminate; i++)
	{
		if(num[i] < ans[length[i]-1])
			ans[length[i]-1] = num[i];
	}
	for(i=0; i<max; i++)
	{
		cout << ans[i] << endl;
	}
}