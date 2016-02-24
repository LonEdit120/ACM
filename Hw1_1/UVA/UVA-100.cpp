#include <iostream>

using namespace std;

int cycle(int n)
{
	int count = 1;
	while(n != 1)
	{
		count++;
		if(n%2 != 0)
		{
			n = 3*n+1;
		}
		else
		{
			n = n/2;
		}
	}
	return count;
}

int main()
{
	int i, j, is, js;
	int c;
	int temp;
	while(cin >> i >> j)
	{
		is = i;
		js = j;
		if(i > j)
		{
			temp = i;
			i = j;
			j = temp;
		}
		c = cycle(i);
		for(i; i <= j; i++)
		{
			if(c <= cycle(i))
			{
				c = cycle(i);
			}
		}
		cout << is << " " << js << " " << c << endl;
	}
}

//while(scanf(...) != EOF)
//while(cin >> a >> b)