#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float C, d, F;
	int count = 0;
	int T;
	cout << fixed << setprecision(2);
	cin >> T;
	while(count != T)
	{
		cin >> C >> d;
		count++;
		d = C * (9.0/5.0) + 32 + d;
		C = (d-32)*(5.0/9.0);
		cout << "Case " << count << ": " << C << endl;
	}
}