#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, stop, start, end;
	s = "string";
	stop = "ENDOFINPUT";
	start = "START";
	end = "END";
	int i;
	int num;
	char c;
	while(1)
	{
		getline(cin, s);
		if(s == stop)
		{
			break;
		}
		else if(s == start || s == end)
		{
			continue;
		}
		else
		{
			for(i=0; i<s.length(); i++)
			{
				if(s[i] >= 'A' && s[i] <= 'Z')
				{
					num = s[i];
					if(num-5 < 'A')
					{
						num = num+21;
					}
					else
					{
						num = num-5;
					}
					c = num;
					cout << c;
				}
				else
				{
					cout << s[i];
				}	
			}
			cout << endl;
		}
	}
}
/*
{
			getline(cin, s);
			if(s == stop)
			{
				break;
			}
			while(s != end)
			{
				getline(cin, s);
				for(i=0; i<s.length(); i++)
				{
					num = s[i];
					if(num-5 < 'A')
					{
						num = num+21;
					}
					else
					{
						num = num-5;
					}
					c = num;
					cout << c;
				}
				cout << endl;			
			}
		} 
		*/