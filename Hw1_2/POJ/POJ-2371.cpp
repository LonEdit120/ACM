#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int i, data, num[110000] = {0}, times, locate;
	string trash;
	cin >> data;
	for(i=0; i<data; i++)
		cin >> num[i];
	sort(num, num+data);
	cin >> trash;
	cin >> times;
	for(i=0; i<times; i++)
	{
		cin >> locate;
		cout << num[locate-1] << endl;
	}
}