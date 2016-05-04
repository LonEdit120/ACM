#include <iostream>
#include <string>
using namespace std;

int pi[1000000];
int cur_pos;
int max = 0;
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
			cout << i+1 << " " << (i+1)/(i-cur_pos) << endl;
	}
}
int main()
{
	int len;
	int i;
	string s;
	int cnt = 0;
	while(1)
	{
		cnt++;
		cin >> len;
		if(len == 0)
			break;
		cin >> s;
		if(cnt>1)
			cout << endl;
		cout << "Test case #" << cnt << endl;
		fail(s);
	}
}