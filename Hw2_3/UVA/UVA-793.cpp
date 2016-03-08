#include <iostream>
#include <cstdio>
using namespace std;

int com[60000];

int Clean(int num)
{
	int i;
	for(i=0; i<60000; i++)
	{
		com[i] = i;
	}
}
int Find(int x)
{
	return (com[x] == x) ?(x) :(com[x]=Find(com[x]));
}
int Connect(int x, int y)
{
	com[Find(x)] = Find(y);
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	int i;
	int num;
	char act;
	int c1, c2;
	int y = 0, n = 0;
	while(count != cases)
	{
		count++;
		cin >> num;
		Clean(num);
		getchar();
		while(1)
		{
			act = getchar();
			//cout << "ACT:" << act << "@@" << endl;//
			if(act == '\n' || act == EOF)
			{
				//cout << "stop" << endl;
				break;
			}
			//cout << "ACT:" << act << "@@" << endl;//
			cin >> c1 >> c2;
			//cout << act << " " << c1 << " " << c2 << endl;
			//break;
			getchar();
			if(act == 'c')
			{
				Connect(c1, c2);
			}
			else if(act == 'q')
			{
				if(Find(c1) == Find(c2))
				{
					//cout << c1 << " " << c2 << endl;	
					y++;
				}
				else if(Find(c1) != Find(c2))
				{
					//cout << "NO: " << c1 << " " << c2 << endl;
					n++;
				}
			}
		}
		cout << y << "," << n << endl;
		y = 0;
		n = 0;
		if(count != cases)
			cout << endl;
	}
}