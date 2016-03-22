#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int>::iterator it;

int list[501] = {0};

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

void booking(int init, long long int limit)
{
	int i;
	int save = 0;
	for(i=init; i>=0 ;i--)
	{
		save += list[i];
		//cout << "+" << list[i];
		if(i == 0)
		{
			//v.push_back(0);
			break;
		}
		else if(save > limit)
		{
			//cout << endl;
			//cout << "SAVE:" << save << endl;
			save = 0;
			//cout << "I+1= " << i+1<<endl;
			v.push_back(i);
			if(i != 1)
			{
				booking(i-1, limit);
			}
			break;
		}
	}
	return;
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
	long long int limit;
	int placement[501];
	for(count = 0; count<cases; count++)
	{
		cin >> num >> book;
		for(j=0; j<num; j++)
		{
			cin >> list[j];
			total += list[j];
		}
		avg = total / book;
		limit = avg;
		for(j=num-1; j>=0; j--)
		{
			save = save + list[j];
			if(save<=avg)
			{
				temp++;
			}
			else
			{
				save = 0;
				break;
			}
		}
		//v.push_back(temp);
		booking(num-temp, limit);
		//cout << endl;
		//cout << "SIZE: " << v.size() << endl;
		//vector_print();
		/*while(v.size() != book-1)
		{
			if(v.size() > book-1)
			{
				temp = temp-1;
				save = 0;
				for(i=num-1; i>=temp; i--)
				{
					save += list[i];
				}
				v.clear();
				v.push_back(temp);
				booking(temp, save);
				//vector_print();
			}
		}*/
		it = v.begin();
		sort(it, it+v.size());
		//vector_print();
		j = 0;
		for(i=0; i<num; i++)
		{
			if(i == v[j])
			{
				cout << "/ ";
				j++;
			}
			cout << list[i] << " ";
		}
		cout << endl;
	}
}