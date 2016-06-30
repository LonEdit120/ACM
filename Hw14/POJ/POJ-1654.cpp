#include <iostream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	double x, y;
	double cur_x, cur_y;
	long long int plane;
	string path;
	int cases;
	cin >> cases;
	for(int i = 0; i<cases; ++i)
	{
		x = 0;
		y = 0;
		plane = 0;
		cin >> path;
		if(path.length() == 1)
		{
			cout << "0" << endl;
			continue;
		}
		else
		{
			for(unsigned int j=0; j<path.length()-1; ++j)
			{
				cur_x = x;
				cur_y = y;
				//cout <<"\""<<path[j]-'0'<<"\""<<endl;
				switch((int)(path[j]-'0'))
				{
					case 1:
					x -= 1;
					y -= 1;
					break;
					case 2:
					y -= 1;
					break;
					case 3:
					x+=1;
					y-=1;
					break;
					case 4:
					x-=1;
					break;
					case 6:
					x+=1;
					break;
					case 7:
					x-=1;
					y+=1;
					break;
					case 8:
					y+=1;
					break;
					case 9:
					x+=1;
					y+=1;
					break;
				}
				plane += (cur_x*y-cur_y*x);
			}
		}
		plane = fabs(plane);
		if(plane%2 == 0)
		{
			plane /= 2;
			cout << plane << endl;
		}
		else
		{
			plane = (plane-1)/2;
			cout << plane << ".5" << endl;
		}
	}
}