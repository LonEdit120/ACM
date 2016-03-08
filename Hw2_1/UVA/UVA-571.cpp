#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

struct jar
{
	int va;
	int vb;
	int a;
	int b;
};

jar pour_A_B(jar j)
{
	if(j.a+j.b >= j.vb)
	{
		j.a = j.a+j.b-j.vb;
		j.b = j.vb;
	}
	else
	{
		j.b=j.a+j.b;
		j.a=0;
	}
	return j;
}

jar pour_B_A(jar j)
{
	if(j.a+j.b >= j.va)
	{
		j.b = j.a+j.b-j.va;
		j.a = j.va;
	}
	else
	{
		j.a=j.a+j.b;
		j.b=0;
	}
	return j;
}

jar empty_A(jar j)
{
	j.a = 0;
	return j;
}

jar empty_B(jar j)
{
	j.b = 0;
	return j;
}

jar fill_A(jar j)
{
	j.a = j.va;
	return j;
}

jar fill_B(jar j)
{
	j.b = j.vb;
	return j;
}

int main()
{
	int action;
	int v;
	jar j;
	srand(time(NULL));
	while(cin >> j.va >> j.vb >> v)
	{
		j.a = 0;
		j.b = 0;
		while(j.a != v && j.b != v)
		{
			cout << "???" <<endl;
			action = rand()%6;
			switch(action)
			{
				case 0:
					pour_A_B(j);
					cout << "Hi" << endl;
					break;
				case 1:
					pour_B_A(j);
					cout << "Hi" << endl;
					break;
				case 2:
					empty_A(j);
					cout << "Hi" << endl;
					break;
				case 3:
					empty_B(j);
					cout << "Hi" << endl;
					break;
				case 4:
					fill_A(j);
					cout << "Hi" << endl;
					break;
				case 5:
					fill_B(j);
					cout << "Hi" << endl;
					break;
				default:
					cout << "ERROR~!" << endl;
			}
		}
		cout << "success" << endl;
	}
}