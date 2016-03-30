#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num, capacity;
	int i, j;
	cin >> num >> capacity;
	int temp;
	int value[capacity+1];
	for(i=0; i<capacity+1; i++)
		value[i] = 0;
	int w, v;
	for(i=0; i<num; i++)
	{
		cin >> w >> v;
		for(j=capacity; j-w>=0; j--)
		{
			temp = value[j-w] + v;
			if(temp > value[j])
				value[j] = temp;
		}
	}
	sort(value, value+capacity);
	cout << value[capacity] << endl;
}