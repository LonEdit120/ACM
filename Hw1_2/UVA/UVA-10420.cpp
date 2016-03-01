#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	unsigned int i = 0;
	unsigned int l;
	if(a.length()<=b.length())
	{
		l = a.length();
	}
	else
	{
		l = b.length();
	}
	for(i = 0;i < l;++i)
	{
		if(a[i] != b[i])
		{
			return a[i] < b[i];
		}
	}
	if(a.length() == l)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int count = 0;
	int lines;
	string country[2001];
	string name;
	cin >> lines;
	int i, j = 1;
	int amount = 1;
	for(i=0; i<lines; i++)
	{
		cin >> country[i];
		getline(cin, name);
	}
	sort(country, country+lines, cmp);
	/*for(i=0; i<lines; i++)
	{
		cout << country[i] << endl;
	}*/
	i=0;
	while(i<lines && j<lines)
	{
		if(country[i] == country[j])
		{
			amount++;
			if(j == lines-1)
			{
				cout << country[i] << " " << amount << endl;
				break;
			}
			j++;
		}
		else if(country[i] != country[j])
		{
			cout << country[i] << " " << amount << endl;
			i = j;
			amount = 0;
		}
	}
}
