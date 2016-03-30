#include <iostream>
#include <vector>
#include <algorithm>
#define max 2147483648

using namespace std;
int main()
{
	vector<long long int> v;
	vector<long long int>::iterator it;
	long long int i, j;
	long long int input;
	for(i=1; i<max; i=i*2)
	{
		for(j=1; i*j <= max; j=j*3)
		{
			v.push_back(i*j);
		}
	}
	sort(v.begin(), v.end());
	while(1)
	{
		cin >> input;
		if(input == 0)
			break;
		for(it=v.begin();it!=v.end();it++)
		{
			if((*it)>=input)
			{
				cout << (*it) << endl;
				break;
			}
		}
	}
}