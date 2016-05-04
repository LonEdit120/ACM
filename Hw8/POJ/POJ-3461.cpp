#include <iostream>
#include <string>
using namespace std;

int pi[1000000];
int cur_pos;
int max = 0;
int cnt;

void match(string s1, string s2)
{
	int s1len = s1.length();
	int s2len = s2.length();
	cnt = 0;
	cur_pos = -1;
	int i;
	pi[0] = -1;
	for(i=0, cur_pos=-1; i<s1len; i++)
	{
		while(cur_pos>=0 && s1[i]!=s2[cur_pos+1])
			cur_pos=pi[cur_pos];
		if(s1[i]==s2[cur_pos+1])
			cur_pos++;
		//pi[i] = cur_pos;
		if(cur_pos+1 == s2len)
		{
			cnt++;
			cur_pos = pi[cur_pos];
		}
	}
}

void fail(string s)
{
	int slen = s.length();
	cur_pos = -1;
	int i;
	pi[0] = -1;
	for(i=1, cur_pos=-1; i<slen; i++)
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
	int cases;
	int i, j;
	string s1, s2;
	cin >> cases;
	for(i=0; i<cases; i++)
	{
		cin >> s1;
		cin >> s2;
		/*cout << s1 << endl;
		cout << s2 << endl;*/
		fail(s2);
		match(s2, s1);
		/*if(cur_pos+1==s2.length())
		{
			cnt++;
			cur_pos = pi[cur_pos];
		}*/
		/*for(j=0; j<s2.length();j++)
			cout << pi[j] << " ";
		cout << endl;*/
		cout << cnt << endl;
		//cout << "------" << endl;
	}
}