#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

char maze[32][32][32];
int dis[32][32][32];
struct pos{
	int L;
	int R;
	int C;
};

queue<pos> road;

int step(int x, int y, int z)
{
	int i;
	pos cur, nxt;
	road.push(pos{x, y, z});
	maze[x][y][z] = '#';
	int move[6][3] = {{0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}};
	while(!road.empty()){
		cur = road.front();
		road.pop();
		for(i = 0; i<6; i++){
			nxt.L = cur.L + move[i][0];
			nxt.R = cur.R + move[i][1];
			nxt.C = cur.C + move[i][2];
			if(maze[nxt.L][nxt.R][nxt.C]!='#')
			{
				dis[nxt.L][nxt.R][nxt.C] = dis[cur.L][cur.R][cur.C] + 1;
				if(maze[nxt.L][nxt.R][nxt.C] == 'E')
				{
					while(!road.empty())
						road.pop();
					return dis[nxt.L][nxt.R][nxt.C];
				}
				road.push(nxt);
				maze[nxt.L][nxt.R][nxt.C]='#';
			}
		}
	}
	return 0;
}

int main()
{
	int l, r, c;
	int x, y, z;
	int sl, sr, sc;
	int ans;
	while(1){
		cin >> l >> r >> c;
		if(!l && !r && !c)
			break;
		for(x=0; x<32; x++){
			for(y=0; y<32; y++){
				for(z=0; z<32; z++){
					maze[x][y][z] = '#';
					dis[x][y][z] = 0;
				}
			}
		}
		for(x=1; x<=l; x++){
			for(y=1; y<=r; y++){
				for(z=1; z<=c; z++){
					cin >> maze[x][y][z];
					if(maze[x][y][z] == 'S')
					{
						sl = x;
						sr = y;
						sc = z;
					}
				}
			}
		}
		
		ans = step(sl, sr, sc);
		if(ans)
			cout << "Escaped in "<< ans <<" minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}

}