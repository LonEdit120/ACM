#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int cases;
	int count = 0;
	int a;
	int i, j;
	int n;
	int pos;
	int temp;
	priority_queue<int> pq;
	queue<int> q;
	int num[100] = {0};
	cin >> cases;
	while(count != cases)
	{
		count++;
		cin >> n >> pos;
		for(i=0; i<100; i++)
		{
			num[i] = 0;
		}
		for(i=0; i<n ;i++)
		{
			cin >> a;
			pq.push(a);
			//q.push(a);
			num[i] = a;
		}
		for(i=0; i<n; i++)
		{
			if(n==1)
				break;
			else if(num[i] < pq.top() && pos == i)
			{
				pos = n-1;
				temp = num[i];
				for(j=i; j+1<n; j++)
				{
					num[j]= num[j+1];
				}
				num[n-1] = temp;
				i -= 1;
			}
			else if(num[i] < pq.top() && i != pos)
			{
				if(i < pos)
					pos--;
				temp = num[i];
				for(j=i; j+1<n; j++)
				{
					num[j]= num[j+1];
				}
				num[n-1] = temp;
				i -= 1;
			}
			else if(num[i] == pq.top())
			{
				pq.pop();
			}
			/*for(ii=0; ii<n; ii++)
			{
				cout << num[ii] << " ";
			}
			cout << endl << "Pos:" << pos+1 << endl;*/
			if(pq.empty())
				break;
		}
		while(!pq.empty())
			pq.pop();
		cout << pos+1 << endl;
	}
}