#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	long long int cow[10001];
	long long int num;
	scanf("%lld", &num);
	int i, j;
	long long int ans = 0;
	for(i=0; i<num; i++)
		scanf("%lld", &cow[i]); 
	sort(cow, cow+num);
	for(i=0; i<num; i++)
	{	

		for(j=0; j<i; j++)
		{
			ans += (cow[i]-cow[j]);
		}
	}
	ans = ans*2;
	printf("%lld\n", ans);
}