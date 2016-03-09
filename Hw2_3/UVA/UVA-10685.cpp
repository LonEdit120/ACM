#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int ani[60000];
string sani[60000];

int Clean(int num)
{
	int i;
	for(i=0; i<60000; i++)
	{
		ani[i] = i;
	}
}
int Find(int x)
{
	return (ani[x] == x) ?(x) :(ani[x]=Find(ani[x]));
}
int Union(int x, int y)
{
	ani[Find(x)] = Find(y);
}

int main()
{
	int num=1, predator=1;
	int i;
	string name;
	string n1, n2;
	int m, n;
	int count = 0;
	/*pair<string, int> p;
	pair<string, int>::iterator it;*/
	vector<pair<string, int> > v;
	vector<pair<string, int> >::iterator vit;
	while(1)
	{
		cin >> num >> predator;
		if(num == 0 && predator == 0)
			break;
		Clean(num);
		for(i=0; i<num; i++)
		{
			cin >> sani[i];
			//v.push_back(make_pair(name, i));
		}
		for(i=0; i<predator; i++)
		{
			cin >> n1 >> n2;
			for(m=0; m<num; m++)
			{
				if(n1 == sani[m])
				{
					for(n=0; n<num; n++)
					{
						if(n2 == sani[n])
						{
							/*cout << n1 << m << endl;
							cout << n2 << n << endl;
							cout << "-----------"<<endl;*/
							break;
						}
					}
					break;
				}
			}
			/*cout << "M: " << m << endl;
			cout << "N: " << n << endl;*/
			Union(m, n);

			
			/*cout << sani[m];
			cout << "-";
			cout << ani[m] << endl;
			cout << sani[n];
			cout << "--";
			cout << ani[n] << endl;*/
			//cout << "0: " << ani[0] << endl;
			m = 0;
			n = 0;
			//cout << m << n << endl;
			
		}
		//cout << "**************" << endl;
		for(i=0; i<num; i++)
		{
			/*cout << sani[i];
			cout << " ";
			cout << ani[i] << endl;*/
			if(ani[i] == i)
			{
				//cout << '[' << ani[i] << ']' << endl;
				count++;
			}
		}
		cout << count << endl;
		count = 0;
	}
}