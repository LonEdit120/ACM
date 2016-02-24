#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

int sum(int n)
{
	while(n >= 10)
	{
		if(n>=1000)
		{
			n = n/1000 + (n%1000)/100 + (n%100)/10 + n%10;
		}
		else if(n>=100&&n<1000)
		{
			n = n/100 + (n%100)/10 + n%10;
		}
		else if(n>=10&&n<100)
		{
			n = n/10 + n%10;
		}
	}
	return n;
}

int main()
{
	int i;
	string name1, name2;
	char name_1[100], name_2[100];
	float num1=0, num2=0;
	float ans;
	int x = 'a'-1;
	int X = 'A'-1;
	cout << fixed << setprecision(2);
	while(fgets(name_1, 100, stdin) != NULL && fgets(name_2, 100, stdin) != NULL)
	{
		name1 = name_1;
		name2 = name_2;
		//cout << name1 << " " << name2 <<endl;
		for(i = 0; i < name1.length(); i++)
		{
			if(name1[i] >= 'a' && name1[i] <= 'z')
			{
				num1 = num1 + (name1[i] - x);
			}
			else if(name1[i] >= 'A' && name1[i] <= 'Z')
			{
				num1 = num1 + (name1[i] - X);
			}
		}
		for(i = 0; i < name2.length(); i++)
		{
			if(name2[i] >= 'a' && name2[i] <= 'z')
			{
				num2 = num2 + (name2[i] - x);
			}
			else if(name2[i] >= 'A' && name2[i] <= 'Z')
			{
				num2 = num2 + (name2[i] - X);
			}
		}
		num1 = sum(num1);
		num2 = sum(num2);
 		if(num1 >= num2 && num1 != 0)
		{
			ans = num2/num1;
		}
		else if(num2 >= num1 && num2 != 0)
		{
			ans = num1/num2;
 		}
		if(num1 == 0 && num2 == 0)
		{
			cout << endl;
		}
		else
		{
			cout << ans*100 << " " << '%' << endl;
		}
		//cout << num1 << " " << num2 << endl;
		num1 = 0;
		num2 = 0;
	}
}