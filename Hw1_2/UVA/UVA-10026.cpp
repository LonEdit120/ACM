#include <iostream>
#include <algorithm>

using namespace std;

struct ratio
{
	float rate;
	int locate;
};

bool cmp(ratio r1, ratio r2)
{
	if(r1.rate < r2.rate)
		return 1;
	else
		return 0;
}

int main()
{
	int cases;
	float days[1001] = {0}, fine[1001] = {0};
	int count = 0;
	int lines;
	int i;
	ratio r[1001];
	cin >> cases;
	{
		while(count != cases)
		{
			count++;
			cin >> lines;
			for(i=0; i<lines; i++)
			{
				cin >> days[i] >> fine[i];
				r[i].rate = days[i] / fine[i];
				r[i].locate = i;
			}
			sort(r, r+lines, cmp);
			for(i=0; i<lines; i++)
			{
				if(i != lines-1)	
					cout << r[i].locate+1 << " ";
				else
				{
					cout << r[i].locate+1 << endl;
					if(count != cases)
					{
						cout << endl;
					}
				}
			}
			for(i=0; i<1001; i++)
			{
				days[i]=0;
				fine[i]=0;
				r[i].rate=0;
				r[i].locate=0;
			}
		}
	}
}