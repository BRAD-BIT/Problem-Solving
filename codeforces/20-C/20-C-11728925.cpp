#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<functional>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define  oo  1e9
using namespace std;
vector<vector<pair<int,int>>>graph;long long dis[100007];int prv[100007];int vis[100007];
struct edge
{
    int indx,weight;
    edge(int i, int w):indx(i),weight(w){}
    bool operator<(const edge&e)const{ return weight>e.weight; }
};
void Dijkstra()
{
    priority_queue<edge>p; p.push(edge(0, 0)); dis[0] = 0;
    while (!p.empty())
    {
        edge cur = p.top(); p.pop();

		if (vis[cur.indx])continue;
		vis[cur.indx]=1;
        for (int i = 0; i < graph[cur.indx].size(); i++)
        {
            edge ee(graph[cur.indx][i].first, graph[cur.indx][i].second + cur.weight);
            if (dis[ee.indx]>dis[cur.indx] + graph[cur.indx][i].second)
            {ee.weight = dis[ee.indx] = dis[cur.indx] + graph[cur.indx][i].second;prv[ee.indx]=cur.indx;}
			p.push(ee);
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;graph.resize(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        graph[--a].push_back(make_pair(--b,c));
        graph[b].push_back(make_pair(a,c));
    }
    for(int i=0;i<n;i++){dis[i]=1000000000000;prv[i]=-1;}
	memset(vis,0,sizeof vis);
    Dijkstra();
    if(dis[n-1]==1000000000000)cout<<-1<<endl;
    else
    {
        vector<int>path;path.push_back(n);
        int i=n-1;
        while(prv[i]!=0)
        {
            path.push_back(prv[i]+1);
            i=prv[i];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++)cout<<path[i]<<" ";cout<<endl;
    }
}