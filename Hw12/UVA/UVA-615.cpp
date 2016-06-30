#include <iostream>

using namespace std;

int s[100000];
void Clean()
{
	int i;
	for(i=0; i<100000; i++)
	{
		s[i] = 0;
	}
}
int Find(int x)
{
	return (s[x] == x) ?(x) :(s[x]=Find(s[x]));
	/*if(s[x] == x) return x;
	else {
		s[x] = Find(s[x]);
		return s[x];
	}*/
}
void Union(int x, int y)
{
	s[Find(x)] = Find(y);
}

int main()
{
	int a, b, cnt;
	bool ans;
	int num;
	cnt = 0;
	Clean();
	ans = true;
	while(1)
	{
		cin >> a >> b;
		if(a==0 && b==0)
		{
			++cnt;
			num = 0;
			for(int i=1; i<100000; ++i)
			{
				if(s[i] == i)
					++num;
			}
			if(num > 1)
				ans = false;
			if(ans == true)
				cout << "Case " << cnt << " is a tree." << endl;
			else
				cout << "Case " << cnt << " is not a tree." << endl;
			Clean();
			ans = true;
		}
		else if(a==-1 && b==-1)
			break;
		else
		{
			if(!s[a])
				s[a] = a;
			if(!s[b])
				s[b] = b;
			if(Find(a) == Find(b))
				ans = false;
			Union(a,b);
		}
	}
}