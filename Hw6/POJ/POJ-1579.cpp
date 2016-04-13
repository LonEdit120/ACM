#include <iostream>

using namespace std;
int i, j, k;
int w[21][21][21] = {{{0}}};

int calc(int i, int j, int k)
{
	if(i<j && j<k)
	{
		return w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
	}
	else
	{
		return w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
	}
}


int main()
{
	int a, b, c;
	for(i = 0 ; i < 21 ; i++)
	{
		for(j = 0 ; j < 21 ; j++)
		{
			w[0][i][j] = 1;
			w[i][0][j] = 1;
			w[i][j][0] = 1;
		}
	}
	for(i=1; i<21; i++)
	{
		for(j=1; j<21; j++)
		{
			for(k=1; k<21; k++)
			{
				w[i][j][k] = calc(i,j,k);
			}
		}
	}
	while(cin >> a >> b >> c)
	{
		if(a==-1 && b==-1 && c==-1)
			break;
		else if(a<=0 || b<=0 || c<=0)
			cout << "w("<<a<<", "<<b<<", "<<c<<") = 1"<< endl;
		else if(a>20 || b>20 || c>20)
			cout << "w("<<a<<", "<<b<<", "<<c<<") = 1048576"<< endl;
		else if(a<b && b<c)
		{
			cout << "w("<<a<<", "<<b<<", "<<c<<") = "<< w[a][b][c] << endl;
		}
		else
			cout << "w("<<a<<", "<<b<<", "<<c<<") = " << w[a][b][c] << endl;
	}	

}