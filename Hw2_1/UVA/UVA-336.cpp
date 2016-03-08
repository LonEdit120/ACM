#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main()
{
	int cases;
	int n1, n2;
	int i;
	int save[31];
	int target;
	int TTL;
	int count = 0;
	pair<int, int> p;
	vector<pair<int, int> > v1;
	vector<pair<int, int> > v2;

	vector<pair<int, int> >::iterator it;
	while(1)
	{
		cin >> cases;
		if(cases == 0)
		{
			break;
		}
		for(i=0; i<cases; i++)
		{
			cin >> n1 >> n2;
			v1.push_back(make_pair(n1, n2));
			v2.push_back(make_pair(n2, n1));
		}
		while(1)
		{
			//count++;
			cin >> target >> TTL;
			if(target == 0 && TTL == 0)
			{
				break;
			}
			//--------------
			//load
			//--------------
			cout << "Case " << count << ": " <<  << " nodes not reachable from node " << target << " with TTL = " << TTL << "." << endl;
		}
		count = 0;
	}
}