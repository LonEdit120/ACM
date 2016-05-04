#include <iostream>
#include <string>
using namespace std;

int pi[1000000];
int cur_pos;
bool zero = true;
int len;
void fail(string s)
{
	cur_pos = -1;
	int i;
	pi[0] = -1;
	for(i=1, cur_pos=-1; i<len; i++)
	{
		while(cur_pos>=0 && s[i]!=s[cur_pos+1])
			cur_pos=pi[cur_pos];
		if(s[i]==s[cur_pos+1])
			cur_pos++;
		pi[i] = cur_pos;
	}
}
int main()
{
	int i;
	string s;
	while(1)
	{
		cin >> s;
		if(s == ".")
			break;
		len = s.length();
		fail(s);
		if(cur_pos >-1 && len % (len-1-cur_pos) == 0)
			cout << len/(len-1-cur_pos) << endl;
		else
			cout << "1" << endl;
	}
}