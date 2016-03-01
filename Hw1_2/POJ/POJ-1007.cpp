#include <iostream>

using namespace std;

int main()
{
	int chars, lines;
	int times;
	int temp;
	int i, j;
	int count = 0;
	cin >> chars >> lines;
	int dna[chars][lines];
	int total[lines];
	while(count != lines)
	{
		count++;
		times = 0;
		for(i=0; i<chars; i++)
		{
			cin >> dna[i][lines];
		}
		for(i=0; i<lines; i++)
		{
			for(j=0; j+1<lines; j++)
			{
				if(dna[j][lines] > dna[j+1][lines])
				{
					temp = dna[j][lines];
					dna[j][lines] = dna[j+1][lines];
					dna[j+1][lines] = temp;
					times++;
				}
			}
		}
		total[count-1] = times;
	}
	for(i=0; i<lines; i++)
	{
		for(j=0; j+1<lines; j++)
		{
			if(total[j] > total[j+1])
			{
				temp = total[j];
				total[j] = total[j+1];
				total[j+1][lines] = temp;
			}
		}
	}
}