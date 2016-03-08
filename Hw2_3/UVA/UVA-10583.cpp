#include <iostream>
/*+1*/
using namespace std;
int s[52000];
int Clean(int num)
{
	int i;
	for(i=0; i<52000; i++)
	{
		s[i] = i/*+1*/;
	}
}
int Find(int x)
{
	return (s[x] == x/*+1*/) ?(x/*+1*/) :(s[x]=Find(s[x]));
	/*Same meaning as
		if(s[x] == x+1)
			return x+1;
		else if(s[x] != x+1)
		{
			s[x] = Find(s[x]);
		}
	*/
}
int Union(int x, int y)
{
	s[Find(x)] = Find(y);
}

int main()
{
	int i;
	int num, lines;
	int n1, n2;
	int count = 0;
	int cases = 0;
	while(cin >> num >> lines)
	{
		cases++;
		if(num == 0 && lines == 0)
			break;
		Clean(num);
		for(i=0; i<lines; i++)
		{
			cin >> n1 >> n2;
			//cout << n1 << " " << n2 << endl;
			//cout << "F1:" << Find(n1) << endl;
			//cout << "F2:" << Find(n2) << endl;
			Union(n1, n2);
			//cout << "FF1:" << Find(n1) << endl;
			//cout << "FF2:" << Find(n2) << endl;
			//cout << n1 << " " << n2 << endl;
			//cout << "..." << endl;
		}
		//cout << "---------------" << endl;
		for(i=0; i<num; i++)
		{
			if(s[i] == i/*+1*/)
			{
				//cout << i << " " << s[i] <<endl;
				count++;
			}
		}
		cout << "Case " << cases << ": " << count << endl;
		count = 0;
	}
}