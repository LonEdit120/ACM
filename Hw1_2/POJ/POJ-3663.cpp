#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int cow[20000];
	int num, leng;
	cin >> num >> leng;
	int count = 0;
	int i, j;
	for(i=0; i<num; i++)
	{
		cin >> cow[i];
	}
	sort(cow, cow+num);
	for(i=0; i<num; i++)
	{
		for(j=i+1; j>i && j<num; j++)
		{
			if(cow[i]+cow[j]<=leng)
			{
				count++;
			}
			else
				break;
		}
	}
	cout << count << endl;
}