#include <iostream>
#include <cstdio>
using namespace std;

int p[60000];
int Clean(int num)
{
	int i;
	for(i=1; i<52000; i++)
	{
		p[i] = i;
	}
}
int Find(int x)
{
	return (p[x] == x) ?(x) :(p[x]=Find(p[x]));
}
int Union(int x, int y)
{
	p[Find(x)] = Find(y);
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	int i;
	int num;
	int p1, p2;
	char check = '0';
	int ans;
	char pin[3000];
	while(count != cases)
	{
		count++;
		cin >> num;
		//getchar();
		Clean(num);
		fgets(pin, 3000, stdin);
		while(check != '\n' && check != EOF)
		{
			scanf("%d%d", &p1, &p2);
			Union(p1, p2);
			check = getchar();
			/*cout << p1 << " " << p2 << endl;
			cout << "CHECK:" << endl;*/
		}
		//cout << "Find 0: "<< Find(0) << endl;
		//cout << "Find 10: "<< Find(10) << endl;
		ans = 0;
		for(i=1; i<num; i++)
		{
			//cout << i << " " << Find(i) << endl;
			if(p[i] == i)
			{
				//cout << p[i] << " " << i << endl;
				ans++;
			}
		}
		cout << ans << endl;
	}
}