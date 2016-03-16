#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 5000000
using namespace std;
vector<int> p;
vector<int>::iterator it;

bool isprime[MAX];
/*bool isPrime(long long int n)
{
	for(int i = 0; p[i]*p[i] <= n; i++)
		if(n % p[i]==0)
			return false;
	return true;
}
void MakePrime()
{
	p.push_back(2);
	p.push_back(3);
	for(int i=5, gap=2; i < MAX; i+=gap, gap=6-gap)
		if(isPrime(i))
			p.push_back(i);
}*/
void Sieve()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for(unsigned int i = 2;i <= sqrt(MAX); i++)
		if(isprime[i])
			for(int j=2*i;j<MAX; j+=i)
				isprime[j]=false;
}

int main()
{
	long long int input;
	unsigned int i;
	Sieve();
	for(i = 2; i<MAX; i++)
	{
		if(isprime[i] == true)
			p.push_back(i);
	}
	while(1)
	{
		cin >> input;
		if(input < 0)
			break;
		for(i=0; i<p.size(); i++)
		{
			if(input%p[i] == 0)
			{
				cout << "    " << p[i] << endl;
				input = input / p[i];
				i--;
			}
		}
		if(input != 1)
			cout << "    " << input << endl;
		cout << endl;
	}
}