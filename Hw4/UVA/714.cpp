#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int>::iterator it;

int list[501] = {0};

int bin_search(int a, int b)
{
	int mid;
	if(mid%2==0)
		mid = (a+b)/2;
	else if(mid%2==1)
		mid = (a+b+1)/2;

}
                                                                                                                                                               
void vector_print()
{ 
	cout << "Vector contains these elements : " << endl;
	for(it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	//prints the vector from the first element to the last element
	cout << endl;
	cout << endl;
}

int main()
{
	int cases;
	int num, book;
	cin >> cases;
	int i, j, count;
	int temp = 0;
	long long int total = 0; 
	long long int avg;
	long long int save = 0;
	int b_count;
	long long int largest;
	long long int smallest;
	int placement[501];
	bool enough;
	int state;//1 not enough	0 OK	-1	too much space
	for(count = 0; count<cases; count++)
	{
		cin >> num >> book;
		for(i=0; i<num; i++)
		{
			cin >> list[i];
			if(i=0)
			{
				smallest = list[0];
				largest = list[0];
			}
			total += list[i];
			if(list[i] > largest)
				largest = list[i];
			else
				smallest = list[i];
		}
		bin_search(smallest, largest);
		/*avg = total / book;
		for(i=0; i<num; i++)
		{
			save = save + list[i];
			if(save>avg)
			{
				v.push_back(i);
				save = 0;
			}
		}*/
	}
}