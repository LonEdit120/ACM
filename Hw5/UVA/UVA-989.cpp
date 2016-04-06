#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int su[9][9];
int su2[9][9] = {{0}};
int su3[9][9][10]; 
bool have_zero = false;
int x, y;
int ans[9][9]={{0}};
int ans_count = 0;

class Sudoku
{
	public:
		void readIn(int);
		void sudo_print(int);
		void solve(int);
		void BT(int , int,int);
		void set_zero(int,int,int,int);
		bool check(int,int,int,int);
};

int main()
{
	Sudoku ss;
	int num;
	int i,j,k;
	int count = 0;
	while(cin >> num)
	{
		count++;
		if(count!=1 && ans_count != 0)
			cout << endl << endl;
		else if(count !=1)
			cout << endl;
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				su[i][j] = 0;
				su3[i][j][0] = 0;
				ans[i][j] = 0;
				su2[i][j] = 0;
				for(k=1; k<10; k++)
				{
					su3[i][j][k] = 1;
				}
			}
		}
		have_zero = false;
		ans_count = 0;
		ss.readIn(num);
		ss.solve(num);
	}
}

bool Sudoku::check(int i, int j, int k, int num)
{
	int a, b, i3, j3;
	i3 = (i/num)*num;
	j3 = (j/num)*num;
	for(a=i3; a<=i3+num-1; a++)
	{
		for(b=j3; b<=j3+num-1; b++)
		{
			if(a!=i && b!=j)
			{
				if(su3[a][b][0] == k)
					return false;
			}
		}
	}
	for(a=0; a<num*num; a++)
	{
		if(a!=j)
		{
			if(su3[i][a][0] == k)
				return false;
		}
		if(a!=i)
		{
			if(su3[a][j][0] == k)
				return false;
		}
	}
	return true;
}

void Sudoku::BT(int i, int j, int num)
{
	int k;
	int a, b;
	int m,n;
	if(ans_count==2)
		return;
	for(k=1; k<num*num+1; k++)
	{
		if(check(i,j,k,num))
		{
			su3[i][j][0] = k;
			m = i;
			n = j;
			while(su3[m][n][0] != 0)
			{
				n++;
				if(n==num*num)
				{
					n=0;
					m++;
				}
				if(m==num*num)
					break;
			}
			if(m==num*num)
			{
				ans_count++;
				if(ans_count == 1)
				{
					for(a=0; a<num*num; a++)
					{
						for(b=0 ;b<num*num; b++)
						{
							ans[a][b] = su3[a][b][0];
						}
					}
				}
			}
			else
				BT(m ,n,num);
			su3[i][j][0] = 0;
		}
		else if(k == num*num && check(i,j,k,num) == false)
			return;
	}
}

void Sudoku::set_zero(int i, int j, int k,int num)
{
	int a, b, i3, j3;
	i3 = (i/num)*num;
	j3 = (j/num)*num;
	for(a=i3; a<=i3+num-1; a++)
	{
		for(b=j3; b<=j3+num-1; b++)
		{
			su3[a][b][k] = 0;
		}
	}
	for(a=0; a<num*num; a++)
	{
		su3[i][a][k] = 0;
		su3[a][j][k] = 0;
	}
	for(b=1; b<num*num+1; b++)
	{
		su3[i][j][b] = 0;
	}
}

void Sudoku::solve(int num)
{
	int i, j, k;
	int n;
	for(i=0;i<num*num;i++)
	{
		for(j=0;j<num*num;j++)
		{
			su3[i][j][0] = su[i][j];
		}
	}
	for(i=0; i<num*num; i++)
	{
		for(j=0; j<num*num; j++)
		{
			for(k=1; k<num*num+1; k++)
			{
				su3[i][j][k] = 1;
			}
		}
	}
	for(i=0; i<num*num; i++)
	{
		for(j=0; j<num*num; j++)
		{
			n = su3[i][j][0];
			if(n != 0)
			{
				if(su3[i][j][n] == 0)
				{
					cout << "NO SOLUTION" << endl;
					return;
				}
				set_zero(i,j,n,num);
			}
		}
	}
	for(i=0; i<num*num; i++)
	{
		for(j=0; j<num*num ;j++)
		{
			if(su3[i][j][0] == 0)
			{
				if(have_zero == false)
				{
					have_zero = true;
					x = i;
					y = j;
				}
			}
			/*cout << "After set zero" << endl;
			sudo_print(num);*/
			if(i==num*num-1 && j==num*num-1 && have_zero == false)
			{
				ans_count = 1;
				sudo_print(num);
			}
			su[i][j] = su3[i][j][0];
		}
	}
	if(have_zero == true)
	{
		BT(x, y,num);
	}
	if(ans_count == 0)
		cout << "NO SOLUTION" << endl;

	else if(have_zero == true)
	{
		for(i=0; i<num*num; i++)
		{
			for(j=0; j<num*num ;j++)
			{
				su[i][j] = ans[i][j];
			}
		}
		sudo_print(num);
	}
}

void Sudoku::sudo_print(int num)
{
	int i, j, k;
	for(i=0; i<num*num; i++)
	{
		for(j=0; j<num*num; j++)
		{
			if(num == 1)
				cout << '1' ;
			else if(j!=num*num-1)
				cout << su[i][j] << " ";
			else if(j==num*num-1 && i==num*num-1)
				cout << su[i][j];
			else if(j==num*num-1)
				cout << su[i][j]<< endl;
		}
	}
}

void Sudoku::readIn(int num)
{
	int i, j;
	for(i=0; i<num*num; i++)
	{
		for(j=0; j<num*num; j++)
		{
			scanf("%d", &su[i][j]);
		}
	}
}