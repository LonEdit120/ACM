#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

/*void bubble1(int alpha1[])
{
	int i, j;
	int temp;
	for(i=0; i<26; i++)
	{
		for(j=0; j+1<26; j++)
		{
			if(alpha1[j]>alpha1[j+1])
			{
				temp = alpha1[j];
				alpha1[j] = alpha1[j+1];
				alpha1[j+1] = temp; 
			}
		}
	}
}

void bubble2(int alpha2[])
{
	int i, j;
	int temp;
	for(i=0; i<26; i++)
	{
		for(j=0; j+1<26; j++)
		{
			if(alpha2[j]>alpha2[j+1])
			{
				temp = alpha2[j];
				alpha2[j] = alpha2[j+1];
				alpha2[j+1] = temp; 
			}
		}
	}
}*/

int main()
{
	string s1, s2;
	int i;
	int x = 'A';
	int c;
	int alpha1[26] = {0};
	int alpha2[26] = {0};
	int count = 0;
	getline(cin, s1);
	for(i=0; i<s1.length(); i++)
	{
		c = s1[i]-x;
		alpha1[c]++;
	}
	sort(alpha1, alpha1+26);
	getline(cin, s2);
	for(i=0; i<s2.length(); i++)
	{
		c = s2[i]-x;
		alpha2[c]++;
	}
	sort(alpha2, alpha2+26);
	for(i=0; i<26; i++)
	{	
		if(alpha1[i] != alpha2[i])
		{
			cout << "NO" << endl;
			break;
		}
		if(alpha1[i] == alpha2[i])
		{
			count++;
		}
		if(count == 26)
		{
			cout << "YES" << endl;
		}
	}
}