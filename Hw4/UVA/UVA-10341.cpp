#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int p, q, r, s, t, u;

int count = 0;

bool equals_zero(double n)
{
	if(abs(n) < 1e-4)
		return true;
	else
		return false;
}

double calc(double n)
{
	double ans;
	ans = p*(exp(-n))+(q*sin(n))+(r*cos(n))+(s*tan(n))+(t*n*n)+u;
	return ans;
}

double bin_search(double a, double b)
{
	double mid = (a+b)/2;
	double total = calc(mid);
	if(count++ == 50)
		return mid;
	else if(total>=0)
		bin_search(mid,b);
	else if(total<0)
		bin_search(a,mid);
}



int main()
{
	double answ;
	cout << fixed << setprecision(4);
	while(cin >> p >> q >> r >> s >> t >> u)
	{
		answ=bin_search(0.0,1.0);
		//cout <<answ;
		if(equals_zero(calc(answ)))
			cout << answ << endl;
		else
			cout << "No solution" << endl;
		count = 0;
	}
}