#include <bits/stdc++.h>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
vector<vector<int> >G;
int is_cat[100007],vis[100007];
int n,m,ans=0;
void DFS(int node,int count,int not_valid)
{
    if(count>m)not_valid=1;
    vis[node]=1;
    int leaf=1;
    for(int i=0;i<int(G[node].size());++i)
    {
        int child=G[node][i];
        if(vis[child])continue;
        leaf=0;
        DFS(child,count*(is_cat[child])+is_cat[child],not_valid);
    }
    ans+=(leaf)*!(not_valid);
}
int main()
{
   scanf("%d%d",&n,&m);G.resize(n);
   for(int i=0;i<n;i++)scanf("%d",&is_cat[i]);
   for(int i=0;i<n-1;i++){int x,y;  scanf("%d%d",&x,&y);--x,--y;G[x].push_back(y),G[y].push_back(x);}
   DFS(0,is_cat[0],0);
   cout<<ans<<endl;
}