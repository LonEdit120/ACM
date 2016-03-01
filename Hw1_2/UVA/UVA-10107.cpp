#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i;
	unsigned int num[10001] = {0};
	int count = 0;
	while(cin >> num[count])
	{
		count++;
		sort(num, num+count);
		if(count%2==1)
			cout << num[((count+1)/2)-1] << endl;
		else
			cout << (num[(count/2)-1]+num[(count/2)])/2 << endl;
	}
}
/*
1
2
3
3
4
27
4
*/
/*
1
3
4
60
70
50
2
*/