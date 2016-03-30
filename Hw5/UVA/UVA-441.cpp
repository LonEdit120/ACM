#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	int i;
	int arr[51] = {0};
	int count;
	int a, b, c, d, e, f;
	cin >> num;
	while(1)
	{
		if(num == 0)
			break;
		for(i=0; i<num; i++)
			cin >> arr[i];
		sort(arr,arr+num);
		for(a=0;a<num;a++)
		{
			b=a+1;
			if(a==num-5)
				break;
			for(b;b<num;b++)
			{
				c=b+1;
				for(c;c<num;c++)
				{
					d=c+1;
					for(d;d<num;d++)
					{
						e=d+1;
						for(e;e<num;e++)
						{
							f=e+1;
							for(f;f<num;f++)
							{
								if(arr[a]<arr[b]&&arr[b]<arr[c]&&arr[c]<arr[d]&&arr[d]<arr[e]&arr[e]<arr[f])
								{
									cout
									<< arr[a]
									<< " "
									<< arr[b]
									<< " "
									<< arr[c]
									<< " "
									<< arr[d]
									<< " "
									<< arr[e]
									<< " "
									<< arr[f]
									<< endl; 
								}
							}
						}
					}
				}
			}
		}
		//-----------------
		for(i=0; i<51; i++)
			arr[i] = 0;
		cin >> num;
		if(num != 0)
		{
			cout << endl;
		}
	}
}