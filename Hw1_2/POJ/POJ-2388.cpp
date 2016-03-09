#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i, num, arr[10000] = {0};
	cin >> num;
	for(i=0; i<num; i++)
		cin >> arr[i];
	sort(arr, arr+num);
	cout << arr[num/2] << endl;
}