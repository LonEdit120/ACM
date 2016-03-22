#include <iostream>
#include <algorithm>
using namespace std;

int height[50001];
int quer[25001];

/*int bin_search(int a, int b, int target)
{
	int mid;
	if((b-a)%2==0)
		mid = (a+b)/2;
	else if
		mid = (a+b+1)/2;

}*/

int main()
{
	int n1, n2;
	int i, j;
	int ans1, ans2;
	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> height[i];
	}
	//sort(height, height+n1);
	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> quer[i];
	}
	for(i=0; i<n2; i++)
	{
		for(j=0; j<n1; j++)
		{
			ans1 = -1;
			ans2 = -1;
			if(height[j] > quer[i])
			{
				if(j==0)
				{
					ans1 = 0;
					ans2 = height[j];
					break;
				}
				else
				{
					ans2 = height[j];
					while(height[j-1] == quer[i])
					{
						j--;
						if(j-1 == 0 && height[j-1] == quer[i])
							ans1 = 0;
						else if (j-1 == 0 && height[j-1])
							break;
					}
					if(ans1 != 0)
						ans1 = height[j-1];
					break;
				}
			}
			else if(j == n1-1 && height[j] <= quer[i])
			{
				ans1 = height[j];
				ans2 = 0;
				break;
			}
		}
		if(ans1 != 0 && ans2 != 0)
			cout << ans1 << " " << ans2 << endl;
		else if(ans1 == 0 && ans2 != 0)
			cout << "X " << ans2 << endl;
		else if(ans1 != 0 && ans2 == 0)
			cout << ans1 << " X" << endl;
	}
}