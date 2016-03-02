#include <iostream>
#include <cstdio>
using namespace std;

char map[27][27];
bool vis[27][27];
const int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

void clean(int x, int y)
{
	vis[x][y] = true;
	int i, j;
	for(i = 0; i<8; i++){
		if(map[x+dir[i][0]][y+dir[i][1]] == '1' && !vis[x+dir[i][0]][y+dir[i][1]]){
			clean(x+dir[i][0], y+dir[i][1]);
		}
	}
}

int main()
{
	int n;
	int i, j;
	int si, sj;
	int num = 0;
	char bin;
	int count;
	while(cin >> n){
		count = 0;
		num++;
		for(i = 0; i<27; i++){
			for(j = 0; j<27; j++){
				map[i][j] = 0;
			}
		}
		for(i = 1; i<=n; i++){
			for(j = 1; j<=n; j++){
				cin >> map[i][j];
			}
		}
		for(i = 0; i<27; i++){
			for(j = 0; j<27; j++){
				vis[i][j] = false;
			}
		}
		for(i = 0; i<=n+1; i++){
			for(j = 0; j<=n+1; j++){
				bin = map[i][j];
				if(bin == '1' && !vis[i][j]){
					count++;
					clean(i, j);
				}
				/*for(i = si-1; i <= si+1; i++){
					for(j = sj-1; j <= sj+1; j++){
						if(map[i][j] == '1'){
							map[i][j] = '0';
						}
					}
				}*/
			}
		}
		cout << "Image number " << num << " contains " << count << " war eagles." << endl; 
	}
	//prints out the square
	/*for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			cout << map[i][j] << endl;
		}
		cout << endl;
	}*/

}