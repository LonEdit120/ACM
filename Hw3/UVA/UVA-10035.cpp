#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char n1[11];
	char n2[11];
	int nn1[11] = {0};
	int nn2[11] = {0};
	int ans[11] = {0};
	string n1s, n2s;
	int l1, l2;
	int i;
	int x = '0';
	long long int carry;
	for(i=0; i<11; i++)
	{
		n1[i] = '0';
		n2[i] = '0';
	}
	while(scanf("%s%s", n1, n2) != EOF)
	{
		n1s = n1;
		n2s = n2;
		if(n1s == "0" && n2s == "0")
		{
			//cout << "BREAK" << endl;
			break;
		}
		carry = 0;
		l1 = strlen(n1);
		l2 = strlen(n2);
		for(i=l1-1; i>=0; i--)
		{
			nn1[11-l1+i] = n1[i] - x;
		}
		for(i=l2-1; i>=0; i--)
		{
			nn2[11-l2+i] = n2[i] - x;
		}
		for(i=10; i>=0; i--)
		{
			ans[i] = nn1[i]+nn2[i]+ans[i];
			/*cout 
			<<"I: "
			<< i
			<< " " 
			<< nn1[i] 
			<< " " 
			<< nn2[i] 
			<< " " 
			<< ans[i];*/
			if(ans[i] >= 10)
			{
				carry++;
				ans[i-1] += (ans[i] - (ans[i]%10))/10;
				ans[i] = ans[i]%10;
			}
			//cout << "CARRY: " << carry << endl;
		}

		if(carry == 0)
			cout << "No carry operation." << endl;
		else if(carry == 1)
			cout << "1 carry operation." << endl;
		else
			cout << carry << " carry operations." << endl;
		
		for(i=0; i<11; i++)
		{
			n1[i] = '0';
			n2[i] = '0';
			nn1[i] = 0;
			nn2[i] = 0;
			ans[i] = 0;
		}
	}
}