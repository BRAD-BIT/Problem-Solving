//In the name of Allah
#include <bits/stdc++.h>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
int const MAX = 1024 + 7;
int grid[MAX][MAX],FT[MAX][MAX];
int N;

void update(int x,int y,int v)
{
	for(int i=x;i<=N;i+=(i&-i))
	for(int j=y;j<=N;j+=(j&-j))
		FT[i][j]+=v;
}
int RSQ(int x,int y)
{
	int ret=0;
	for(int i=x;i>0;i-=(i&-i))
	for(int j=y;j>0;j-=(j&-j))
		ret+=FT[i][j];
	return ret;
}

int main()
{
	int t;char s[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&N);
		memset(FT,0,sizeof FT);
		memset(grid,0,sizeof grid);
		while(1)
		{
			scanf("%s",s);
			if(s[1]=='E')
			{
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				int v=z-grid[x][y];grid[x][y]=z;
				update(++x,++y,v);
			}
			else
			if(s[1]=='U')
			{
				 int sum = 0;
				 int x1,y1,x,y;
				 scanf(" %d%d%d%d",&x,&y,&x1,&y1);
				 sum = RSQ(x1+1,y1+1) + RSQ(x,y) - RSQ(x,y1+1) - RSQ(x1+1 , y);
				 printf("%d\n",sum);
			}
			else break;
		}
		printf("\n");
	}
}
