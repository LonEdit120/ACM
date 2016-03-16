#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#define MAX 1000000
using namespace std;

vector<int> p;
vector<int>::iterator it;
priority_queue<int> q;

bool isprime[MAX];
void Primes()
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
	int n1, n2;
	int num;
	unsigned int i;
	Primes();
	int total = 0;
	int count = 0;
	int n;
	for(i = 2; i<MAX; i++)
	{
		if(isprime[i] == true)
			p.push_back(i);
	}
	/*for(it=p.begin();it!=p.end();it++)
	{
		cout << (*it) << endl;
	}*/
	while(1)
	{
		cin >> n1;
		if(n1 == 0)
			break;
		cin >> n2;
		for(num=n1; num<=n2; num++)
		{
			n = num;
			//cout <<"NUM: " << num << endl;
			for(i=0; i<p.size(); i++)
			{
				/*cout << "i: " << i <<endl;
				cout << "n: " << n << endl;*/
				if(n%p[i] == 0)
				{
					if(q.empty() || p[i] != q.top())
						q.push(p[i]);
					n = n / p[i];
					if(n == 1)
						break;
					i--;
				}
					//cout << "p[i]: " <<p[i] << endl;
				if(n == 1)
					continue;
				/*if(i == p.size()-1)
				{
					continue;
				}*/
			}
			total = 0;
			while(!q.empty())
			{
				total += q.top();
				q.pop();
			}
			if(isprime[total])
				count++;
			//cout << "COUNT:" << count << endl;
			//cout << "--------------------" << endl;
		}
		cout << count << endl;
		count = 0;
	}
}