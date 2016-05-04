#include <iostream>
#include <string>
using namespace std;

int pi[1000000];
int cur_pos;
bool zero = true;
void fail(string s)
{
	cur_pos = -1;
	int i;
	pi[0] = -1;
	for(i=1, cur_pos=-1; i<s.length(); i++)
	{
		while(cur_pos>=0 && s[i]!=s[cur_pos+1])
			cur_pos=pi[cur_pos];
		if(s[i]==s[cur_pos+1])
			cur_pos++;
		pi[i] = cur_pos;
		if(cur_pos >-1 && (i+1) % (i-cur_pos) == 0)
		{
			if(i+1 == s.length())
			{
				cout << (i+1)/(i-cur_pos) << endl;
				zero = false;
			}
		}
	}
}
int main()
{
	int len;
	int i;
	string s;
	while(1)
	{
		cin >> s;
		if(s == ".")
			break;
		fail(s);
		if(zero)
			cout << "1" << endl;
		zero = true;
	}
}