#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	char n1[300];
	char n2[300];
	int nn1[300] = {0};
	int nn2[300] = {0};
	int ans[599] = {0};
	int l1, l2;
	int i, j;
	int x = '0';
	int start = 0;
	bool jump;
	for(i=0; i<300; i++)
	{
		n1[i] = '0';
		n2[i] = '0';
	}
	while(scanf("%s%s", n1, n2) != EOF)
	{
		l1 = strlen(n1);
		l2 = strlen(n2);
		for(i=l1-1; i>=0; i--)
		{
			nn1[300-l1+i] = n1[i] - x;
		}
		/*for(i=0; i<300; i++)
		{
			cout << nn1[i];
		}
		cout << endl;*/
		for(i=l2-1; i>=0; i--)
		{
			nn2[300-l2+i] = n2[i] - x;
		}
		/*for(i=0; i<300; i++)
		{
			cout << nn2[i];
		}
		cout << endl;*/
		for(i=299; i>=0; i--)
		{
			for(j=299; j>=0; j--)
			{
				if(nn1[i]*nn2[j] != 0)
				{
					ans[i+j+1]+=((nn1[i]*nn2[j])%10);
					ans[i+j]+=((nn1[i]*nn2[j])-(nn1[i]*nn2[j])%10)/10;
				}
			}
		}
		while(1)
		{
			jump = true;
			for(i=0; i<599; i++)
			{
				if(ans[i]>=10)
				{
					ans[i-1] = ans[i-1]+(ans[i]-ans[i]%10)/10;
					ans[i] = ans[i]%10;
					jump = false;
				}
			}
			if(jump)
				break;
		}
		for(i=0; i<599; i++)
		{
			if(ans[i] != 0)
			{
				break;
			}
		}
		//cout << i << endl;
		/*if(i == 599)
		{
			cout << "0" << endl;
		}
		else*/
			for(i; i<600; i++)
				cout << ans[i];
			cout << endl;	
		for(i=0; i<300; i++)
		{
			n1[i] = '0';
			n2[i] = '0';
			nn1[i] = 0;
			nn2[i] = 0;
		}
		for(i=0; i<600; i++)
			ans[i] = 0;
		start = 0;
	}
}