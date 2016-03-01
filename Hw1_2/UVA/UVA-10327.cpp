#include <iostream>

using namespace std;

int main()
{
	int i, j;
	int n;
	int num[1001];
	int temp;
	int count = 0;
	while(cin >> n)
	{
		int num[n];
		for(i=0; i<n; i++)
		{
			cin >> num[i];
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j+1<n; j++)
			{
				if(num[j]>num[j+1])
				{
					temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
					count++;
				}
			}
		}
		cout << "Minimum exchange operations : " << count << endl;
		count = 0;
	}
}